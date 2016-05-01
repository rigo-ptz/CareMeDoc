package com.jollypanda.caremedoc.dialogs;

import android.content.Context;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.view.Window;
import android.widget.Button;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.adapters.EcgListAdapter;
import com.jollypanda.caremedoc.api.model.EcgItem;
import com.jollypanda.caremedoc.interfaces.OnEcgViewHolderClickListener;

import java.util.ArrayList;

import butterknife.Bind;
import butterknife.ButterKnife;
import butterknife.OnClick;

/**
 * Dialog with list of ECG recordings for
 * current patient.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 */
public class EcgListDialog extends AlertDialog implements OnEcgViewHolderClickListener {

    @Bind(R.id.rvEcgList)
    RecyclerView rvEcgList;

    @Bind(R.id.btnCancel)
    Button btnCancel;

    private EcgListAdapter mAdapter;
    private ArrayList<EcgItem> mEcgItems;

    private Context mContext;

    public EcgListDialog(Context context) {
        super(context);
        mContext = context;

        getWindow().requestFeature(Window.FEATURE_NO_TITLE);
    }

    public EcgListDialog(Context context, int themeResId) {
        super(context, themeResId);
    }

    protected EcgListDialog(Context context, boolean cancelable, OnCancelListener cancelListener) {
        super(context, cancelable, cancelListener);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.dialog_ecg);
        ButterKnife.bind(this);

        testRecycler();

        setRecyclerView();
    }

    @Override
    protected void onStop() {
        ButterKnife.unbind(this);
        super.onStop();
    }

    @OnClick(R.id.btnCancel)
    public void onCancelClick() {
        this.dismiss();
    }

    @Deprecated
    private void testRecycler() {
        mEcgItems = new ArrayList<>();
        EcgItem i1 = new EcgItem("1 января 2016, 00:30", "Подозрение на тахикардию");
        EcgItem i2 = new EcgItem("7 января 2016, 15:55", "Ритм ровный");
        EcgItem i3 = new EcgItem("28 января 2016, 17:55", "Ритм ровный");
        EcgItem i4 = new EcgItem("28 января 2016, 19:55", "Ритм ровный");
        EcgItem i5 = new EcgItem("28 января 2016, 20:55", "Подозрение на тахикардию");
        EcgItem i6 = new EcgItem("29 января 2016, 10:55", "Ритм ровный");
        EcgItem i7 = new EcgItem("28 января 2016, 11:55", "Ритм ровный");

        mEcgItems.add(i1);
        mEcgItems.add(i2);
        mEcgItems.add(i3);
        mEcgItems.add(i4);
        mEcgItems.add(i5);
        mEcgItems.add(i6);
        mEcgItems.add(i7);
    }

    private void setRecyclerView() {
        LinearLayoutManager llm = new LinearLayoutManager(mContext);
        llm.setOrientation(LinearLayoutManager.VERTICAL);
        rvEcgList.setLayoutManager(llm);
        rvEcgList.setHasFixedSize(true);
        rvEcgList.setItemAnimator(new DefaultItemAnimator());

        mAdapter = new EcgListAdapter(mContext, mEcgItems, this);
        rvEcgList.setAdapter(mAdapter);
    }

    @Override
    public void onClick(View v, int position) {

    }
}
