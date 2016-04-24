package com.jollypanda.caremedoc.interfaces;

import android.view.View;

import com.jollypanda.caremedoc.adapters.PatientListViewHolder;
import com.jollypanda.caremedoc.fragments.PatientsListFragment;

/**
 * Interface to notify {@link PatientsListFragment} from {@link PatientListViewHolder}
 * if user click profile or ecg buttons for some patient.
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public interface OnPatientViewHolderClickListener {
    /**
     * Called when user click on profile button.
     *
     * @param v Viewholder of patient list.
     * @param position Position of view in recycler view. Equal with position in items list.
     */
    void onPatientProfileClick(View v, int position);

    /**
     * Called when user click on ecg button.
     *
     * @param v Viewholder of patient list.
     * @param position Position of view in recycler view. Equal with position in items list.
     */
    void onPatientEcgClick(View v, int position);
}
