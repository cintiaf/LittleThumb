package com.github.ros_java.tango.localization;

import org.ros.message.Time;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;
import org.ros.rosjava_geometry.FrameName;
import org.ros.rosjava_geometry.FrameTransform;
import org.ros.rosjava_geometry.Quaternion;
import org.ros.rosjava_geometry.Transform;
import org.ros.rosjava_geometry.Vector3;

import java.util.ArrayList;

import geometry_msgs.TransformStamped;
import tf2_msgs.TFMessage;

/**
 * Created by bruno on 26.08.15.
 */
public class TransformTangoDevicePublisher {
    private FrameTransform mFrame;
    private TransformStamped mTfStamped;
    private TFMessage mTfMessage;
    private Publisher<TFMessage> mPublisher;

    public TransformTangoDevicePublisher(ConnectedNode connectedNode) {
        mTfStamped = connectedNode.getTopicMessageFactory().newFromType(TransformStamped._TYPE);
        mTfMessage = connectedNode.getTopicMessageFactory().newFromType(TFMessage._TYPE);
        mPublisher = connectedNode.newPublisher("tf", TFMessage._TYPE);
    }

    public void sendTransform(Transform transform) {
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        mFrame = new FrameTransform(transform, FrameName.of("tango_ss"), FrameName.of("tango_device"), t);

        ArrayList<TransformStamped> list = new ArrayList<TransformStamped>(1);
        list.add(mFrame.toTransformStampedMessage(mTfStamped));
        mTfMessage.setTransforms(list);
        mPublisher.publish(mTfMessage);
    }

    public void sendTransform(double v_x, double v_y, double v_z,
                              double q_x, double q_y, double q_z, double q_w) {
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        Vector3 vect = new Vector3(v_x, v_y, v_z);
        Quaternion quat = new Quaternion(q_x, q_y, q_z, q_w);
        mFrame = new FrameTransform(new Transform(vect, quat), FrameName.of("tango_ss"), FrameName.of("tango_device"), t);

        ArrayList<TransformStamped> list = new ArrayList<TransformStamped>(1);
        list.add(mFrame.toTransformStampedMessage(mTfStamped));
        mTfMessage.setTransforms(list);
        mPublisher.publish(mTfMessage);
    }
}
