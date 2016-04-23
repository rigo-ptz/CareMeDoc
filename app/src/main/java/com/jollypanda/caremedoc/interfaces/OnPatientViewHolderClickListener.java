package com.jollypanda.caremedoc.interfaces;

import android.view.View;

/**
 * Interface with declarations for PatientListViewHolder
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public interface OnPatientViewHolderClickListener {
    void onPatientProfileClick(View v, int position);
    void onPatientEcgClick(View v, int position);
}
