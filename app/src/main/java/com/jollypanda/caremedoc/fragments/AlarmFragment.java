package com.jollypanda.caremedoc.fragments;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.jollypanda.caremedoc.R;

import butterknife.ButterKnife;

/**
 * Fragment for sending alarm to SIB.
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class AlarmFragment extends Fragment {

    public AlarmFragment() {
    }

    public static AlarmFragment newInstance() {
        return new AlarmFragment();
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_feed, container, false);
        ButterKnife.bind(this, rootView);

        setTitle();

        return rootView;
    }

    private void setTitle() {
        ActionBar actionBar = ((AppCompatActivity) getActivity()).getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(getString(R.string.title_alarm));
        }
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        ButterKnife.unbind(this);
    }
}
