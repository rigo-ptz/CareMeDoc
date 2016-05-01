package com.jollypanda.caremedoc.adapters;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.interfaces.OnEcgViewHolderClickListener;

import butterknife.Bind;
import butterknife.ButterKnife;

/**
 * View Holder for ecg list.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 * @see EcgListAdapter
 */
public class EcgListViewHolder extends RecyclerView.ViewHolder implements
        View.OnClickListener {

    @Bind(R.id.tvEcgDateTime)
    TextView tvEcgDateTime;

    @Bind(R.id.tvEcgOtherInfo)
    TextView tvEcgOtherInfo;

    private OnEcgViewHolderClickListener mListener;

    public EcgListViewHolder(View itemView, OnEcgViewHolderClickListener listener) {
        super(itemView);
        ButterKnife.bind(this, itemView);
        mListener = listener;
        itemView.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        mListener.onClick(v, getAdapterPosition());
    }
}
