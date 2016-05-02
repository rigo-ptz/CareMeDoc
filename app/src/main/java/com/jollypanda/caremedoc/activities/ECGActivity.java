package com.jollypanda.caremedoc.activities;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.Toolbar;
import android.util.DisplayMetrics;
import android.view.MenuItem;
import android.widget.RelativeLayout;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.views.ECGView;

import butterknife.Bind;
import butterknife.ButterKnife;

/**
 * Activity for viewing ecg record.
 *
 * @author Yamushev Igor
 * @since 02.05.2016
 */
public class ECGActivity extends BaseAppCompatActivity {

    @Bind(R.id.rvEcgViewContainer)
    RelativeLayout rvEcgViewContainer;

    @Bind(R.id.mainActivityToolbar)
    Toolbar mToolbar;

    private ECGView mEcgView;

    private int[] mDemoSignal;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ecg);
        ButterKnife.bind(this);

        setSupportActionBar(mToolbar);
        setTitle();

        setEcgView();
    }

    @Override
    protected void onDestroy() {
        ButterKnife.unbind(this);
        super.onDestroy();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home) {
            onBackPressed();
        }
        return super.onOptionsItemSelected(item);
    }

    private void setTitle() {
        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(getString(R.string.ecg_activity_title));
            actionBar.setDisplayHomeAsUpEnabled(true);
        }
    }

    private void setEcgView() {
        mEcgView = new ECGView(this, getPixelsPerMillimeter());
        rvEcgViewContainer.addView(mEcgView);

        mDemoSignal = getResources().getIntArray(R.array.demosignal);

        mEcgView.setECGData(mDemoSignal);
    }

    public double getPixelsPerMillimeter() {
        DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        int screenHeight = metrics.heightPixels;
        int screenWidth = metrics.widthPixels;
        // xdpi - the exact physical pixels per inch of the screen in the X dimension.
        float xDpi = metrics.xdpi;
        return (double) (xDpi / 25.4f);
    }
}
