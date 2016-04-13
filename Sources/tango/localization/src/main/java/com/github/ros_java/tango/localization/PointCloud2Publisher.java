package com.github.ros_java.tango.localization;

import android.util.Log;

import org.jboss.netty.buffer.ChannelBuffer;
import org.jboss.netty.buffer.ChannelBuffers;
import org.ros.message.Time;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.util.ArrayList;
import java.util.List;

import sensor_msgs.PointCloud2;
import sensor_msgs.PointField;

/**
 * Created by bruno on 26.08.15.
 */
public class PointCloud2Publisher {
    private static final String TAG = PointCloud2Publisher.class.getSimpleName();

    private PointCloud2 mPointCloud;
    private Publisher<PointCloud2> mPublisher;
    private long mLastTime;
    private int mNumPoints;
    private ChannelBuffer mBuffer;
    private ChannelBuffer mLastBuffer;

    public PointCloud2Publisher(ConnectedNode connectedNode){
        mPointCloud = connectedNode.getTopicMessageFactory().newFromType(PointCloud2._TYPE);
        List<PointField> list = new ArrayList<PointField>(0);
        list.add((PointField) connectedNode.getTopicMessageFactory().newFromType(PointField._TYPE));
        list.add((PointField) connectedNode.getTopicMessageFactory().newFromType(PointField._TYPE));
        list.add((PointField) connectedNode.getTopicMessageFactory().newFromType(PointField._TYPE));
        mPointCloud.setFields(list);
        mPointCloud.getFields().get(0).setName("x");
        mPointCloud.getFields().get(0).setOffset(0);
        mPointCloud.getFields().get(0).setDatatype(PointField.FLOAT32);
        mPointCloud.getFields().get(0).setCount(1);
        mPointCloud.getFields().get(1).setName("y");
        mPointCloud.getFields().get(1).setOffset(4);
        mPointCloud.getFields().get(1).setDatatype(PointField.FLOAT32);
        mPointCloud.getFields().get(1).setCount(1);
        mPointCloud.getFields().get(2).setName("z");
        mPointCloud.getFields().get(2).setOffset(8);
        mPointCloud.getFields().get(2).setDatatype(PointField.FLOAT32);
        mPointCloud.getFields().get(2).setCount(1);

        mPublisher = connectedNode.newPublisher("/simple_cloud", PointCloud2._TYPE);

        mBuffer = ChannelBuffers.buffer(0);
        mLastBuffer = mBuffer;
        mLastTime = System.currentTimeMillis();
    }

    public void setXyzIj(int count, FloatBuffer fBuffer) {
        float[] floats = new float[fBuffer.capacity()];
        fBuffer.position(0);
        fBuffer.get(floats);
        byte[] bytes = new byte[4 * floats.length];
        for (int i = 0; i < floats.length; i++) {
            int bits = Float.floatToIntBits(floats[i]);
            bytes[4 * i + 0] = (byte) (bits & 0xff);
            bytes[4 * i + 1] = (byte) ((bits >> 8) & 0xff);
            bytes[4 * i + 2] = (byte) ((bits >> 16) & 0xff);
            bytes[4 * i + 3] = (byte) ((bits >> 24) & 0xff);
        }
        mNumPoints = count;
        mBuffer = ChannelBuffers.wrappedBuffer(ByteOrder.LITTLE_ENDIAN, bytes);
    }

    public void publish(){
        mLastBuffer = mBuffer;
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        mPointCloud.getHeader().setStamp(t);
        mPointCloud.getHeader().setFrameId("tango_depth");
        mPointCloud.setHeight(1);
        mPointCloud.setWidth(mNumPoints);
        mPointCloud.setIsBigendian(false);
        mPointCloud.setPointStep(12);
        mPointCloud.setRowStep(12 * mNumPoints);
        mPointCloud.setData(mBuffer);
        mPointCloud.setIsDense(true);
        mPublisher.publish(mPointCloud);
    }

}
