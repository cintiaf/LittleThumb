package com.github.ros_java.tango.localization;

import android.nfc.Tag;
import android.util.Log;

import org.jboss.netty.buffer.ChannelBuffer;
import org.jboss.netty.buffer.ChannelBuffers;
import org.ros.message.Time;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

import java.nio.ByteOrder;

import nav_msgs.MapMetaData;
import nav_msgs.OccupancyGrid;
import std_msgs.Header;

/**
 * Created by julien on 14/12/15.
 */
public class MyOccupancyGridPublisher {
    private static final String TAG = LocalizationNode.class.getSimpleName();

    private OccupancyGrid mOccupGrid;
    private Publisher<OccupancyGrid> mPublisher;
    private long mLastTime;
    private ChannelBuffer mBuffer;
    private ChannelBuffer mLastBuffer;
    private byte[] grid = new byte[500*500];

    public MyOccupancyGridPublisher(ConnectedNode connectedNode){
        mOccupGrid = connectedNode.getTopicMessageFactory().newFromType(OccupancyGrid._TYPE);

        mOccupGrid.getInfo().getOrigin().getPosition().setX(-2.5);
        mOccupGrid.getInfo().getOrigin().getPosition().setY(-2.5);
        mOccupGrid.getInfo().getOrigin().getPosition().setZ(0);
        mOccupGrid.getInfo().getOrigin().getOrientation().setX(0);
        mOccupGrid.getInfo().getOrigin().getOrientation().setY(0);
        mOccupGrid.getInfo().getOrigin().getOrientation().setZ(0);
        mOccupGrid.getInfo().getOrigin().getOrientation().setW(1);

        mPublisher = connectedNode.newPublisher("/occupancy_grid", OccupancyGrid._TYPE);

        mBuffer = ChannelBuffers.buffer(0);
        for (int i = 0; i < (500*250); ++i)
        {
            grid[i] = (byte)255;
        }
        mBuffer = ChannelBuffers.wrappedBuffer(ByteOrder.LITTLE_ENDIAN, grid);
        mLastBuffer = mBuffer;
        mLastTime = System.currentTimeMillis();
    }

    public void setCell() {

        //int res = 100;
        //int height = 10;
        //int width = 10;
        //int index = (x*res) + ((y*res) * (width * res));

        //mOccupGrid.getData().setByte(50, 255);

    }

    public void publish(){
        mLastBuffer = mBuffer;
        long lt = System.currentTimeMillis();
        Time t = new Time((int) (lt / 1e3), (int) ((lt % 1e3) * 1e6));
        mOccupGrid.getHeader().setStamp(t);
        mOccupGrid.getHeader().setFrameId("map");
        mOccupGrid.getInfo().setMapLoadTime(t);
        mOccupGrid.getInfo().setHeight(500);
        mOccupGrid.getInfo().setWidth(500);
        mOccupGrid.getInfo().setResolution((float) 0.01);
        mOccupGrid.setData(mBuffer);
        mPublisher.publish( mOccupGrid);
    }
}
