package com.jollypanda.caremedoc.adapters;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.api.model.Patient;
import com.jollypanda.caremedoc.interfaces.OnPatientViewHolderClickListener;

import java.util.ArrayList;

/**
 * Adapter for filling patients data
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class PatientListAdapter extends RecyclerView.Adapter<PatientListViewHolder> {

    private Context mContext;
    private OnPatientViewHolderClickListener mListener;
    private ArrayList<Patient> mItems;

    public PatientListAdapter(Context context, ArrayList<Patient> items, OnPatientViewHolderClickListener listener) {
        mContext = context;
        mListener = listener;
        mItems = items;
    }

    @Override
    public PatientListViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_patient_list, parent, false);

        return new PatientListViewHolder(v, mContext, mListener);
    }

    @Override
    public void onBindViewHolder(PatientListViewHolder holder, int position) {
        Patient patient = mItems.get(position);

        StringBuilder sb = new StringBuilder();
        sb.append(patient.getSurname())
                .append(" ")
                .append(patient.getName())
                .append(" ")
                .append(patient.getMiddleName());
        holder.tvUserNameSurname.setText(sb.toString());
    }

    @Override
    public int getItemCount() {
        return mItems == null ? 0 : mItems.size();
    }
}
