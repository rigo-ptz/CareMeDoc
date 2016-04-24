package com.jollypanda.caremedoc.adapters;

import android.content.Context;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.interfaces.OnItemTouchHelperViewHolder;
import com.jollypanda.caremedoc.interfaces.OnPatientViewHolderClickListener;

import butterknife.Bind;
import butterknife.ButterKnife;
import butterknife.OnClick;

/**
 * View holder for patients list on PatientsListFragment
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class PatientListViewHolder extends RecyclerView.ViewHolder implements OnItemTouchHelperViewHolder {

    @Bind(R.id.btnPatientProfile)
    Button btnPatientProfile;

    @Bind(R.id.btnPatientEcg)
    Button btnPatientEcg;

    @Bind(R.id.tvUserNameSurname)
    TextView tvUserNameSurname;

    @Bind(R.id.ivUser)
    ImageView ivUser;

    @Bind(R.id.tvDescription)
    TextView tvDescription;

    private OnPatientViewHolderClickListener mListener;
    private View mThisView;
    private final Drawable mDefaultBackground;

    public PatientListViewHolder(View itemView, Context context, OnPatientViewHolderClickListener listener) {
        super(itemView);
        ButterKnife.bind(this, itemView);

        mThisView = itemView;
        mDefaultBackground = mThisView.getBackground();

        mListener = listener;
    }

    @OnClick(R.id.btnPatientProfile)
    public void onProfileClicked() {
        if (mListener != null)
            mListener.onPatientProfileClick(mThisView, getAdapterPosition());
    }

    @OnClick(R.id.btnPatientEcg)
    public void onEcgClicked() {
        if (mListener != null)
            mListener.onPatientEcgClick(mThisView, getAdapterPosition());
    }

    @Override
    public void onItemSelected() {
        mThisView.setBackgroundColor(Color.LTGRAY);
    }

    @Override
    public void onItemClear() {
        mThisView.setBackground(mDefaultBackground);
    }
}
