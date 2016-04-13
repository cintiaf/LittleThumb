package com.github.ros_java.tango.localization;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

import org.ros.address.InetAddressFactory;
import org.ros.android.RosActivity;
import org.ros.node.NodeConfiguration;
import org.ros.node.NodeMainExecutor;

import com.google.atap.tangoservice.Tango;
import com.google.atap.tangoservice.TangoCameraPreview;
import com.google.atap.tangoservice.TangoConfig;
import com.google.atap.tangoservice.TangoErrorException;
import com.google.atap.tangoservice.TangoOutOfDateException;

import com.google.atap.tango.ux.UxExceptionEvent;
import com.google.atap.tango.ux.UxExceptionEventListener;
import com.google.atap.tango.ux.TangoUx;
import com.google.atap.tango.ux.TangoUxLayout;

public class MainActivity extends RosActivity implements OnClickListener
{
    private static final String TAG = MainActivity.class.getSimpleName();

    private Tango mTango;
    private TangoConfig mConfig;
    private TangoUx mTangoUx;
    private TangoUxLayout mTangoUxLayout;
    private boolean mIsTangoServiceConnected;
    private TangoCameraPreview mTangoCameraPreview;
    private LocalizationNode mNode;
    private Button mMotionResetButton;

    public MainActivity() {
        super("MainActivity", "MainActivity");
    }

    private UxExceptionEventListener mUxExceptionListener = new UxExceptionEventListener() {

        @Override
        public void onUxExceptionEvent(UxExceptionEvent uxExceptionEvent) {
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_LYING_ON_SURFACE){
                Log.i(TAG, "Device lying on surface ");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_FEW_DEPTH_POINTS){
                Log.i(TAG, "Very few depth points in point cloud " );
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_FEW_FEATURES){
                Log.i(TAG, "Invalid poses in MotionTracking ");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_INCOMPATIBLE_VM){
                Log.i(TAG, "Device not running on ART");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_MOTION_TRACK_INVALID){
                Log.i(TAG, "Invalid poses in MotionTracking ");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_MOVING_TOO_FAST){
                Log.i(TAG, "Invalid poses in MotionTracking ");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_OVER_EXPOSED){
                Log.i(TAG, "Camera Over Exposed");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_TANGO_SERVICE_NOT_RESPONDING){
                Log.i(TAG, "TangoService is not responding ");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_TANGO_UPDATE_NEEDED){
                Log.i(TAG, "Device not running on ART");
            }
            if(uxExceptionEvent.getType() == UxExceptionEvent.TYPE_UNDER_EXPOSED){
                Log.i(TAG, "Camera Under Exposed " );
            }

        }
    };
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        // Button to reset motion tracking
        mMotionResetButton = (Button) findViewById(R.id.resetmotion);
        mMotionResetButton.setOnClickListener(this);

        mTangoCameraPreview = new TangoCameraPreview(this);

        // Instantiate the Tango service
        mTango = new Tango(this);
        // Create a new Tango Configuration and enable the MotionTrackingActivity API
        mConfig = new TangoConfig();
        mConfig = mTango.getConfig(TangoConfig.CONFIG_TYPE_CURRENT);
        mConfig.putBoolean(TangoConfig.KEY_BOOLEAN_MOTIONTRACKING, true);
        mConfig.putBoolean(TangoConfig.KEY_BOOLEAN_AUTORECOVERY, true);
        mConfig.putBoolean(TangoConfig.KEY_BOOLEAN_DEPTH, true);

        mTangoUx = new TangoUx.Builder(this).build();
        mTangoUxLayout = (TangoUxLayout) findViewById(R.id.layout_tango);
        mTangoUx = new TangoUx.Builder(this).setTangoUxLayout(mTangoUxLayout).build();
        mTangoUx.setUxExceptionEventListener(mUxExceptionListener);

        mNode = new LocalizationNode(mTango, mTangoUx);
    }

    @Override
    protected void init(NodeMainExecutor nodeMainExecutor) {
        Log.i(TAG, "init called");
                NodeConfiguration nodeConfiguration =
                NodeConfiguration.newPublic(InetAddressFactory.newNonLoopback().getHostAddress(), getMasterUri());
        nodeConfiguration.setMasterUri(getMasterUri());
        nodeMainExecutor.execute(mNode, nodeConfiguration);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mTangoUx.stop();
        try {
            mTango.disconnect();
            mIsTangoServiceConnected = false;
        } catch (TangoErrorException e) {
            Toast.makeText(getApplicationContext(), R.string.TangoError, Toast.LENGTH_SHORT).show();
        }
        Log.i(TAG, "onPaused");
    }

    protected void onResume() {
        super.onResume();
        mTangoUx.start();
        if (!mIsTangoServiceConnected) {
            startActivityForResult(
                    Tango.getRequestPermissionIntent(Tango.PERMISSIONTYPE_MOTION_TRACKING),
                    Tango.TANGO_INTENT_ACTIVITYCODE);
        }
        Log.i(TAG, "onResumed");
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        // Check which request we're responding to
        if (requestCode == Tango.TANGO_INTENT_ACTIVITYCODE) {
            // Make sure the request was successful
            if (resultCode == RESULT_CANCELED) {
                Toast.makeText(this, R.string.motiontrackingpermission, Toast.LENGTH_SHORT).show();
                finish();
                return;
            }
            try {
                mNode.setTangoListeners(mTangoCameraPreview);
            } catch (TangoErrorException e) {
                Toast.makeText(this, R.string.TangoError, Toast.LENGTH_SHORT).show();
            } catch (SecurityException e) {
                Toast.makeText(getApplicationContext(), R.string.motiontrackingpermission,
                        Toast.LENGTH_SHORT).show();
            }
            try {
                mTango.connect(mConfig);
                mIsTangoServiceConnected = true;
            } catch (TangoOutOfDateException outDateEx) {
                if (mTangoUx != null) {
                    mTangoUx.onTangoOutOfDate();
                }
            } catch (TangoErrorException e) {
                Toast.makeText(getApplicationContext(), R.string.TangoError, Toast.LENGTH_SHORT)
                        .show();
            }
            mNode.setUpExtrinsics();
        }
        else {
            super.onActivityResult(requestCode, resultCode, data);
        }
    }

    @Override
    protected void onDestroy() {

        mTangoUx.stop();
        mTango.disconnect();
        super.onDestroy();
        Log.i(TAG, "onDestroyed");
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.resetmotion:
                mTango.resetMotionTracking();
                break;
            default:
                return;
        }
    }
}
