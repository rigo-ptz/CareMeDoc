package com.jollypanda.caremedoc.fragments;

import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.api.interaction.PatientsListApi;
import com.jollypanda.caremedoc.api.model.Patient;

import java.util.Observable;
import java.util.Observer;

import butterknife.ButterKnife;

/**
 * Fragment for sending alarm to SIB.
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class AlarmFragment extends Fragment implements
        Observer {

    private Handler mHandler;
    private Handler.Callback hc = new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            if (msg.what == 1) {
                String s = (String) msg.obj;
                AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
                builder.setMessage(s)
                        .setPositiveButton(getString(R.string.OK), new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                            }
                        })
                        .create()
                        .show();
                return true;
            }
            return false;
        }
    };

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
        mHandler = new Handler(hc);

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

    @Override
    public void onResume() {
        PatientsListApi.getInstance().addObserver(this);
        super.onResume();
    }

    @Override
    public void onPause() {
        PatientsListApi.getInstance().deleteObserver(this);
        super.onPause();
    }

    @Override
    public void update(Observable observable, Object data) {
        Patient patient = (Patient) data;
        StringBuilder sb = new StringBuilder();
        sb.append(getString(R.string.added_new_patient))
                .append(" ")
                .append(patient.getName())
                .append(" ")
                .append(patient.getSurname());
        if (observable instanceof PatientsListApi) {
            Message msg = Message.obtain();
            msg.what = 1;
            msg.obj = sb.toString();
            mHandler.sendMessage(msg);
        }
    }
}
