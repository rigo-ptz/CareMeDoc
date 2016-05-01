package com.jollypanda.caremedoc.adapters;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.api.model.EcgItem;
import com.jollypanda.caremedoc.interfaces.OnEcgViewHolderClickListener;

import java.util.ArrayList;

/**
 * Adapter for filling ecf list in dialog.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 * @see com.jollypanda.caremedoc.dialogs.EcgListDialog
 */
public class EcgListAdapter extends RecyclerView.Adapter<EcgListViewHolder> {

    private ArrayList<EcgItem> mItems;
    private OnEcgViewHolderClickListener mListener;
    private Context mContext;

    public EcgListAdapter(Context context, ArrayList<EcgItem> items, OnEcgViewHolderClickListener listener) {
        mContext = context;
        mListener = listener;
        mItems = items;
    }

    @Override
    public EcgListViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_ecg_list, parent, false);

        return new EcgListViewHolder(v, mListener);
    }

    @Override
    public void onBindViewHolder(EcgListViewHolder holder, int position) {
        EcgItem ecgItem = mItems.get(position);

        holder.tvEcgDateTime.setText(ecgItem.getDate());
        holder.tvEcgOtherInfo.setText(ecgItem.getDescription());
    }

    @Override
    public int getItemCount() {
        return mItems == null ? 0 : mItems.size();
    }
}
