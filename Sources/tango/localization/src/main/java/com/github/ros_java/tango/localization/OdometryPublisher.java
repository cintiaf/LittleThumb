package com.github.ros_java.tango.localization;

import org.ros.message.Time;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

import geometry_msgs.Point;
import geometry_msgs.PoseWithCovariance;
import geometry_msgs.Quaternion;
import geometry_msgs.TwistWithCovariance;
import nav_msgs.Odometry;

/**
 * Created by bruno on 26.08.15.
 */
public class OdometryPublisher {
    private PoseWithCovariance mPose;
    private PoseWithCovariance mLastPose;
    TwistWithCovariance mTwist;
    private Odometry mOdom;
    private Publisher<Odometry> mPublisher;
    private long mLastTime;

    public OdometryPublisher(ConnectedNode connectedNode){
        mOdom = connectedNode.getTopicMessageFactory().newFromType(Odometry._TYPE);

        mPublisher = connectedNode.newPublisher("/odometry/filtered", Odometry._TYPE);

        mPose = mOdom.getPose();
        mLastPose = mPose;
        mTwist = mOdom.getTwist();

        mLastPose.getPose().getPosition().setX(0);
        mLastPose.getPose().getPosition().setY(0);
        mLastPose.getPose().getPosition().setZ(0);
        mLastPose.getPose().getOrientation().setX(0);
        mLastPose.getPose().getOrientation().setY(0);
        mLastPose.getPose().getOrientation().setZ(0);
        mLastPose.getPose().getOrientation().setW(1);

        mLastTime = System.currentTimeMillis();
    }

    public void setOrientation(double x, double y, double z, double w) {
        Quaternion q = mPose.getPose().getOrientation();
        q.setW(w);
        q.setX(x);
        q.setY(y);
        q.setZ(z);
        mPose.getPose().setOrientation(q);
    }

    public void setPosition(double x, double y, double z) {
        Point p = mPose.getPose().getPosition();
        p.setX(x);
        p.setY(y);
        p.setZ(z);
        mPose.getPose().setPosition(p);
    }

    public void publish(){
        mLastPose = mPose;
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        mOdom.getHeader().setStamp(t);
        mOdom.getHeader().setFrameId("tango_device");
        mOdom.setPose(mPose);
        mOdom.setTwist(mTwist);
        mPublisher.publish(mOdom);
    }

    private TwistWithCovariance calculateTwist(){
        double timeDiff = (System.currentTimeMillis() - mLastTime) /1000;
        double xDiff = mPose.getPose().getPosition().getX() - mLastPose.getPose().getPosition().getX();
        double yDiff = mPose.getPose().getPosition().getY() - mLastPose.getPose().getPosition().getY();
        double zDiff = mPose.getPose().getPosition().getZ() - mLastPose.getPose().getPosition().getZ();

        mTwist.getTwist().getLinear().setX(xDiff / timeDiff);
        mTwist.getTwist().getLinear().setY(yDiff / timeDiff);
        mTwist.getTwist().getLinear().setZ(zDiff / timeDiff);
        return mTwist;
    }
}
