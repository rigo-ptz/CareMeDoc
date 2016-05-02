package com.jollypanda.caremedoc.activities;

import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.design.widget.CollapsingToolbarLayout;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;

import com.jollypanda.caremedoc.R;

import butterknife.Bind;
import butterknife.ButterKnife;

/**
 * Provides information about patient.
 *
 * @author Yamushev Igor
 * @since 02.05.2016
 */
public class ProfileActivity extends BaseAppCompatActivity {

    @Bind(R.id.toolbar)
    Toolbar mToolbar;

    @Bind(R.id.collapsingToolbar)
    CollapsingToolbarLayout collapsingToolbar;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);
        ButterKnife.bind(this);

        setToolbar();
    }

    @Override
    protected void onDestroy() {
        ButterKnife.unbind(this);
        super.onDestroy();
    }

    private void setToolbar() {
        setSupportActionBar(mToolbar);
        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(getString(R.string.profile_title));
            actionBar.setDisplayHomeAsUpEnabled(true);
        }
        collapsingToolbar.setCollapsedTitleTextColor(Color.WHITE);
        collapsingToolbar.setExpandedTitleColor(Color.WHITE);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home) {
            onBackPressed();
        }
        return super.onOptionsItemSelected(item);
    }
}
