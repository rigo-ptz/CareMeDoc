package com.jollypanda.caremedoc.interfaces;

import android.view.View;

/**
 * Interface to notify {@link com.jollypanda.caremedoc.dialogs.EcgListDialog}
 * from {@link com.jollypanda.caremedoc.adapters.EcgListViewHolder}
 * if user click on ecg record.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 */
public interface OnEcgViewHolderClickListener {
    /**
     * Called when user click on ecg record item.
     *
     * @param v Viewholder of patient list.
     * @param position Position of view in recycler view. Equal with position in items list.
     */
    void onClick(View v, int position);
}
