package com.github.ros_java.tango.localization;

import org.ros.message.Time;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

import geometry_msgs.Point;
import geometry_msgs.PoseStamped;
import geometry_msgs.Quaternion;

/**
 * Created by bruno on 26.08.15.
 */
public class PosePublisher {
    private PoseStamped mPoseStamped;
    private Publisher<PoseStamped> mPublisher;

    public PosePublisher(ConnectedNode connectedNode){
        mPoseStamped = connectedNode.getTopicMessageFactory().newFromType(PoseStamped._TYPE);

        mPublisher = connectedNode.newPublisher("simple_pose", PoseStamped._TYPE);
    }

    public void setOrientation(double x, double y, double z, double w) {
        Quaternion q = mPoseStamped.getPose().getOrientation();
        q.setW(w);
        q.setX(x);
        q.setY(y);
        q.setZ(z);
        mPoseStamped.getPose().setOrientation(q);
    }

    public void setPosition(double x, double y, double z) {
        Point p = mPoseStamped.getPose().getPosition();
        p.setX(x);
        p.setY(y);
        p.setZ(z);
        mPoseStamped.getPose().setPosition(p);
    }

    public void publish(){
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        mPoseStamped.getHeader().setStamp(t);
        mPoseStamped.getHeader().setFrameId("tango_device");
        mPublisher.publish(mPoseStamped);
    }
}
