package com.github.ros_java.tango.localization;

import android.util.Log;
import android.widget.Toast;

import java.util.ArrayList;
import java.lang.Math;

import org.ros.concurrent.CancellableLoop;
import org.ros.message.Time;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.rosjava_geometry.FrameName;
import org.ros.rosjava_geometry.FrameTransform;
import org.ros.rosjava_geometry.Quaternion;
import org.ros.rosjava_geometry.Vector3;

import com.google.atap.tangoservice.Tango;
import com.google.atap.tangoservice.Tango.OnTangoUpdateListener;
import com.google.atap.tangoservice.TangoCameraIntrinsics;
import com.google.atap.tangoservice.TangoCameraPreview;
import com.google.atap.tangoservice.TangoConfig;
import com.google.atap.tangoservice.TangoCoordinateFramePair;
import com.google.atap.tangoservice.TangoErrorException;
import com.google.atap.tangoservice.TangoEvent;
import com.google.atap.tangoservice.TangoInvalidException;
import com.google.atap.tangoservice.TangoPoseData;
import com.google.atap.tangoservice.TangoXyzIjData;
import com.google.atap.tango.ux.TangoUx;

import org.ros.rosjava_geometry.Transform;

import nav_msgs.MapMetaData;
import nav_msgs.OccupancyGrid;

/**
 * Created by bruno on 25.08.15.
 */
public class LocalizationNode implements NodeMain {
    private static final String TAG = LocalizationNode.class.getSimpleName();
    private OdometryPublisher mOdometryPublisher;
    private PointCloud2Publisher mPointCloudPublisher;
    private MyOccupancyGridPublisher mMyOccupancyGridPublisher;
    private Tango mTango;
    private TangoUx mTangoUx;
    private TangoCameraPreview mTangoCameraPreview;
    private static final int SECS_TO_MILLISECS = 1000;
    private float mDeltaTime;
    private float mPointCloudFrameDelta;
    private float mPreviousTimeStamp;
    private float mXyIjPreviousTimeStamp;
    private TangoPoseData mPose;
    private TangoXyzIjData mXyzIj;
    private static final int UPDATE_INTERVAL_MS = 100;
    private TangoPoseData mIMUToDevicePose;
    private TangoPoseData mIMUToDepthPose;
    private PosePublisher mPosePublisher;

    private Transform mRosToSSTransform;
    private Transform mIMUToDeviceTransform;
    private Transform mIMUToDepthTransform;
    private Transform mDeviceToDepthTransform;

//    private Transform mPoseTransform = new Transform(Vector3.zero(), new Quaternion(0.5, 0.5, -0.5, 0.5));
    private Transform mPoseTransform = new Transform(Vector3.zero(), Quaternion.fromAxisAngle(Vector3.zAxis(), -Math.PI / 2));
    private Transform mPointCloudTransform;
    //private Transform mOccupancyGridTransform;
    private TransformTangoSSPublisher mTransformTangoSSPublisher;
    private TransformTangoDevicePublisher mTransformTangoDevicePublisher;
    private TransformTangoDepthPublisher mTransformTangoDepthPublisher;
    public static Object poseLock = new Object();
    public static Object depthLock = new Object();

    public LocalizationNode(Tango tango, TangoUx tangoUx) {
        mTango = tango;
        mTangoUx = tangoUx;
    }

    /**
     * Set up the TangoConfig and the listeners for the Tango service, then begin using the Motion
     * Tracking API. This is called in response to the user clicking the 'Start' Button.
     */
    public void setTangoListeners(TangoCameraPreview tangoCameraPreview) {
        // Connect to color camera
        mTangoCameraPreview = tangoCameraPreview;
        mTangoCameraPreview.connectToTangoCamera(mTango, TangoCameraIntrinsics.TANGO_CAMERA_COLOR);

        // Lock configuration and connect to Tango
        // Select coordinate frame pair
        final ArrayList<TangoCoordinateFramePair> framePairs = new ArrayList<TangoCoordinateFramePair>();
        framePairs.add(new TangoCoordinateFramePair(
                TangoPoseData.COORDINATE_FRAME_START_OF_SERVICE,
                TangoPoseData.COORDINATE_FRAME_DEVICE));

        // Listen for new Tango data
        mTango.connectListener(framePairs, new OnTangoUpdateListener() {

            @Override
            public void onPoseAvailable(final TangoPoseData pose) {
                // Passing in the pose data to UX library produce exceptions.
                if (mTangoUx != null) {
                    mTangoUx.updatePoseStatus(pose.statusCode);
                }
                //Make sure to have atomic access to Tango Pose Data so that
                //render loop doesn't interfere while Pose call back is updating
                // the data.
                synchronized (poseLock) {
                    mPose = pose;
                    mDeltaTime = (float) (pose.timestamp - mPreviousTimeStamp) * SECS_TO_MILLISECS;
                    mPreviousTimeStamp = (float) pose.timestamp;
                    // Log whenever Motion Tracking enters an invalid state
                    if (pose.statusCode != TangoPoseData.POSE_VALID) {
                        mPose = null;
                    }
                }
            }

            @Override
            public void onXyzIjAvailable(TangoXyzIjData xyzIj) {
                if(mTangoUx!=null){
                    mTangoUx.updateXyzCount(xyzIj.xyzCount);
                }
                // Make sure to have atomic access to TangoXyzIjData so that
                // render loop doesn't interfere while onXYZijAvailable callback is updating
                // the point cloud data.
                synchronized (depthLock) {
                    mXyzIj = xyzIj;
                    float currentTimeStamp = (float) xyzIj.timestamp;
                    mPointCloudFrameDelta = (currentTimeStamp - mXyIjPreviousTimeStamp)
                            * SECS_TO_MILLISECS;
                    mXyIjPreviousTimeStamp = currentTimeStamp;
                    TangoPoseData pose = mTango.getPoseAtTime(currentTimeStamp,
                            framePairs.get(0));
                    Transform ssToDevTransform = new Transform(
                            new Vector3(pose.translation[0], pose.translation[1], pose.translation[2]),
                            new Quaternion(pose.rotation[0], pose.rotation[1], pose.rotation[2], pose.rotation[3])
                    );
                    mPointCloudTransform = ssToDevTransform;
                    //mOccupancyGridTransform = ssToDevTransform;
                }
            }

            @Override
            public void onTangoEvent(final TangoEvent event) {
                if(mTangoUx!=null){
                    mTangoUx.onTangoEvent(event);
                }
            }

            @Override
            public void onFrameAvailable(int cameraId) {
                // Check if the frame available is for the camera we want and
                // update its frame on the camera preview.
                if (cameraId == TangoCameraIntrinsics.TANGO_CAMERA_COLOR) {
                    mTangoCameraPreview.onFrameAvailable();
                }
            }
        });
    }

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("localization");
    }

    @Override
    public void onStart(ConnectedNode node) {
        mOdometryPublisher = new OdometryPublisher(node);
        mPosePublisher = new PosePublisher(node);
        mPointCloudPublisher = new PointCloud2Publisher(node);
        mTransformTangoSSPublisher = new TransformTangoSSPublisher(node);
        mTransformTangoDevicePublisher = new TransformTangoDevicePublisher(node);
        mTransformTangoDepthPublisher = new TransformTangoDepthPublisher(node);

        mMyOccupancyGridPublisher = new MyOccupancyGridPublisher(node);

        node.executeCancellableLoop(new CancellableLoop() {
            @Override
            protected void loop() throws InterruptedException {
                synchronized (poseLock) {
                    if (mPose != null) {
                        Thread.sleep(30);
                        mOdometryPublisher.setPosition(mPose.translation[0], mPose.translation[1], mPose.translation[2]);
                        mOdometryPublisher.setOrientation(mPose.rotation[0], mPose.rotation[1], mPose.rotation[2], mPose.rotation[3]);
                        mPosePublisher.setPosition(mPose.translation[0], mPose.translation[1], mPose.translation[2]);
                        mPosePublisher.setOrientation(mPose.rotation[0], mPose.rotation[1], mPose.rotation[2], mPose.rotation[3]);

                        Transform ssToDevTransform = new Transform(
                                new Vector3(mPose.translation[0], mPose.translation[1], mPose.translation[2]),
                                new Quaternion(mPose.rotation[0], mPose.rotation[1], mPose.rotation[2], mPose.rotation[3])
                        );

                        mOdometryPublisher.publish();
                        mPosePublisher.publish();
                        //mTransformTangoDevicePublisher.sendTransform(ssToDevTransform.invert());
                        mPose = null;
                    }
                }
                synchronized (depthLock) {
                    if (mXyzIj != null) {
                        Thread.sleep(30);
                        mPointCloudPublisher.setXyzIj(mXyzIj.xyzCount, mXyzIj.xyz);

                        mPointCloudPublisher.publish();

                        if (mPointCloudTransform != null) {
                            mTransformTangoDevicePublisher.sendTransform(mPointCloudTransform.invert());
                        }
                        mXyzIj = null;
                    }
                }
                if (mRosToSSTransform != null) {
                    mTransformTangoSSPublisher.sendTransform(mRosToSSTransform);
                }
                if (mDeviceToDepthTransform != null) {
                    mTransformTangoDepthPublisher.sendTransform(mDeviceToDepthTransform);
                }
                //mMyOccupancyGridPublisher.setCell();
                mMyOccupancyGridPublisher.publish();
                /*if (mOccupancyGridTransform != null) {
                    mTransformTangoDevicePublisher.sendTransform(mOccupancyGridTransform.invert());
                }*/
            }
        });
    }

    @Override
    public void onShutdown(Node node) {
    }

    @Override
    public void onShutdownComplete(Node node) {
    }

    @Override
    public void onError(Node node, Throwable throwable) {
    }

    public void setUpExtrinsics() {
        mIMUToDevicePose = new TangoPoseData();
        TangoCoordinateFramePair framePair = new TangoCoordinateFramePair();
        framePair.baseFrame = TangoPoseData.COORDINATE_FRAME_IMU;
        framePair.targetFrame = TangoPoseData.COORDINATE_FRAME_DEVICE;
        mIMUToDevicePose = mTango.getPoseAtTime(0.0, framePair);

        mIMUToDepthPose = new TangoPoseData();
        framePair.baseFrame = TangoPoseData.COORDINATE_FRAME_IMU;
        framePair.targetFrame = TangoPoseData.COORDINATE_FRAME_CAMERA_COLOR;
        mIMUToDepthPose = mTango.getPoseAtTime(0.0, framePair);

        Log.i(TAG, "mIMUToDevicePose " + mIMUToDevicePose);
        Log.i(TAG, "mIMUToDepthPose "  + mIMUToDepthPose);

        mIMUToDeviceTransform = new Transform(
                new Vector3(mIMUToDevicePose.translation[0], mIMUToDevicePose.translation[1], mIMUToDevicePose.translation[2]),
                new Quaternion(mIMUToDevicePose.rotation[0], mIMUToDevicePose.rotation[1], mIMUToDevicePose.rotation[2], mIMUToDevicePose.rotation[3])
        );
        mIMUToDepthTransform = new Transform(
                new Vector3(mIMUToDepthPose.translation[0], mIMUToDepthPose.translation[1], mIMUToDepthPose.translation[2]),
                new Quaternion(mIMUToDepthPose.rotation[0], mIMUToDepthPose.rotation[1], mIMUToDepthPose.rotation[2], mIMUToDepthPose.rotation[3])
        );
        mDeviceToDepthTransform = mIMUToDeviceTransform.invert().multiply(mIMUToDepthTransform);
        mRosToSSTransform = Transform.zRotation(Math.PI / 2);

        Log.i(TAG, "mIMUToDeviceTransform = "  + mIMUToDeviceTransform);
        Log.i(TAG, "mIMUToDepthTransform = "  + mIMUToDepthTransform);
        Log.i(TAG, "mDeviceToDepthTransform = "  + mDeviceToDepthTransform);
        Log.i(TAG, "mRosToSSTransform = "  + mRosToSSTransform);
    }
}
