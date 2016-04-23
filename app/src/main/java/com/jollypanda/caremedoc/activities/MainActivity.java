package com.jollypanda.caremedoc.activities;

import android.content.res.Configuration;
import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.FrameLayout;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.fragments.AlarmFragment;
import com.jollypanda.caremedoc.fragments.FeedFragment;
import com.jollypanda.caremedoc.fragments.PatientsListFragment;

import butterknife.Bind;
import butterknife.ButterKnife;

/**
 * Activity that contains:
 * PatientListFragment
 * NewsFeedFragment
 * AlarmFragment
 *
 * @author Yamushev Igor
 * @since 21.04.2016
 */
public class MainActivity extends BaseAppCompatActivity {

    private static final String DRAWER_SELECTED_ITEM = "drawerSelectedItem";

    @Bind(R.id.mainActivityToolbar)
    Toolbar mToolbar;

    @Bind(R.id.container)
    FrameLayout mContainer;

    @Bind(R.id.drawerLayout)
    DrawerLayout mDrawerLayout;

    @Bind(R.id.navigation_view)
    NavigationView mNavigationView;

    private ActionBarDrawerToggle mDrawerToggle;

    private Fragment fragmentToOpen;

    /**
     * Position of last drawer selected item
     */
    private int mCurrentSelectedDrawerPosition;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);

        setSupportActionBar(mToolbar);
        initDrawer();

        ifFirstOpen(savedInstanceState);
    }

    private void ifFirstOpen(Bundle savedInstanceState) {
        if (savedInstanceState == null) {
            Menu menu = mNavigationView.getMenu();
            menu.getItem(mCurrentSelectedDrawerPosition).setChecked(true);

            Fragment f = PatientsListFragment.newInstance();
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.container, f, "patientsList")
                    .addToBackStack("main")
                    .commit();

            getSupportActionBar().setTitle(getString(R.string.title_patients_list));
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        ButterKnife.unbind(this);
    }

    @Override
    protected void onPostCreate(Bundle savedInstanceState) {
        mDrawerToggle.syncState();
        super.onPostCreate(savedInstanceState);
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putInt(DRAWER_SELECTED_ITEM, mCurrentSelectedDrawerPosition);
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        mDrawerToggle.onConfigurationChanged(newConfig);
    }

    @Override
    public void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        mCurrentSelectedDrawerPosition = savedInstanceState.getInt(DRAWER_SELECTED_ITEM);
        Menu m = mNavigationView.getMenu();
        m.getItem(mCurrentSelectedDrawerPosition).setChecked(true);
    }

    @Override
    public void onBackPressed() {
        if (mDrawerLayout.isDrawerOpen(GravityCompat.START))
            mDrawerLayout.closeDrawers();
        else
            super.onBackPressed();
    }

    private void initDrawer() {
        setDrawerMenuListener();
        mDrawerLayout.addDrawerListener(initDrawerToggle());
    }

    private void setDrawerMenuListener() {
        mNavigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(MenuItem item) {
                Fragment fragment = getSupportFragmentManager().findFragmentById(R.id.container);

                item.setChecked(true);

                switch (item.getItemId()) {
                    case R.id.nav_main_fragment:
                        mCurrentSelectedDrawerPosition = 0;
                        fragment = PatientsListFragment.newInstance();
                        break;
                    case R.id.nav_feed_fragment:
                        mCurrentSelectedDrawerPosition = 1;
                        fragment = FeedFragment.newInstance();
                        break;
                    case R.id.nav_alarm_fragment:
                        mCurrentSelectedDrawerPosition = 2;
                        fragment = AlarmFragment.newInstance();
                        break;
                    default:
                        break;
                }

                fragmentToOpen = fragment;
                mDrawerLayout.closeDrawers();
                return true;
            }
        });
    }
    private ActionBarDrawerToggle initDrawerToggle() {
        mDrawerToggle = new ActionBarDrawerToggle(this, mDrawerLayout, mToolbar, R.string.drawerOpen, R.string.drawerClose) {
            @Override
            public void onDrawerOpened(View drawerView) {
                super.onDrawerOpened(drawerView);
                invalidateOptionsMenu();
            }

            @Override
            public void onDrawerClosed(View drawerView) {
                if (fragmentToOpen != null) {
                    FragmentManager fragmentManager = getSupportFragmentManager();
                    fragmentManager.beginTransaction()
                            .replace(R.id.container, fragmentToOpen)
                            .commit();
                }

                super.onDrawerClosed(drawerView);
                invalidateOptionsMenu();
            }
        };
        return mDrawerToggle;
    }
}
