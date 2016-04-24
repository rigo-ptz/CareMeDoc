package com.jollypanda.caremedoc.fragments;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.helper.ItemTouchHelper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.adapters.ItemTouchHelperCallback;
import com.jollypanda.caremedoc.adapters.PatientListAdapter;
import com.jollypanda.caremedoc.api.model.Patient;
import com.jollypanda.caremedoc.interfaces.OnPatientViewHolderClickListener;

import java.util.ArrayList;

import butterknife.Bind;
import butterknife.ButterKnife;

/**
 * Fragment that contains list of passengers
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class PatientsListFragment extends Fragment implements OnPatientViewHolderClickListener{

    @Bind(R.id.rvPacients)
    RecyclerView rvPacients;

    private PatientListAdapter mAdapter;
    private ItemTouchHelper mItemTouchHelper;

    private ArrayList<Patient> mPatientList;

    public PatientsListFragment() {
    }

    public static PatientsListFragment newInstance() {
        return new PatientsListFragment();
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_pacients_list, container, false);
        ButterKnife.bind(this, rootView);

        testRecycler();

        setTitle();
        setRecyclerView();

        return rootView;
    }

    @Deprecated
    private void testRecycler() {
        mPatientList = new ArrayList<>();
        Patient p1 = new Patient();
        Patient p2 = new Patient();
        Patient p3 = new Patient();

        p1.setName("Сергей");
        p2.setName("Константин");
        p3.setName("Анастасия");

        p1.setSurname("Варламов");
        p2.setSurname("Константинопольский");
        p3.setSurname("Никитина");

        p1.setMiddleName("Анатольевич");
        p2.setMiddleName("Константинович");
        p3.setMiddleName("Николаевна");

        mPatientList.add(p1);
        mPatientList.add(p2);
        mPatientList.add(p3);
    }

    private void setRecyclerView() {
        LinearLayoutManager llm = new LinearLayoutManager(getActivity());
        llm.setOrientation(LinearLayoutManager.VERTICAL);
        rvPacients.setLayoutManager(llm);
        rvPacients.setHasFixedSize(true);
        rvPacients.setItemAnimator(new DefaultItemAnimator());

        mAdapter = new PatientListAdapter(getActivity(), mPatientList, this);
        rvPacients.setAdapter(mAdapter);

        ItemTouchHelper.Callback callback = new ItemTouchHelperCallback(mAdapter);
        mItemTouchHelper = new ItemTouchHelper(callback);
        mItemTouchHelper.attachToRecyclerView(rvPacients);
    }

    private void setTitle() {
        ActionBar actionBar = ((AppCompatActivity) getActivity()).getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(getString(R.string.title_patients_list));
        }
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        ButterKnife.unbind(this);
    }

    @Override
    public void onPatientProfileClick(View v, int position) {

    }

    @Override
    public void onPatientEcgClick(View v, int position) {

    }
}
