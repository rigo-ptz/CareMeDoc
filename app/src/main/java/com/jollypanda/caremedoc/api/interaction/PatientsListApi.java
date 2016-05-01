package com.jollypanda.caremedoc.api.interaction;

import com.jollypanda.caremedoc.api.model.Patient;
import com.jollypanda.caremedoc.tools.Constants;

import java.util.ArrayList;

/**
 * Actions with SIB for getting patient list
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class PatientsListApi {

    static {
        System.loadLibrary(Constants.JNI_LIBRARY_HELLO);
    }
    public native int connectSmartSpace(String name, String ip, int port);
    public native void disconnectSmartSpace();
    public native void subscribeForPatients(long nodeDescriptor);

    //    private static final String KP_SS_ADDRESS_LOCAL =  "78.46.130.194";
    private static final String SS_NAME =  "oss.fruct.org/smartcare";
    private static final String KP_SS_ADDRESS_LOCAL =  "192.168.56.1";

    private ArrayList<Patient> mPatientArrayList;
    private int nodeDescriptor;

    private static PatientsListApi instance = new PatientsListApi();

    public static PatientsListApi getInstance() {
        return instance;
    }

    private PatientsListApi() {
    }

    public void getResult() {
        mPatientArrayList = new ArrayList<>();
        nodeDescriptor = connectSmartSpace(SS_NAME, KP_SS_ADDRESS_LOCAL, 10010);
        subscribeForPatients(nodeDescriptor);
    }

    /**
     * Method handle Patient object from native.
     * If patient already exist here we just put it higher in list position.
     *
     * @param patient - Patient object
     * @see Patient
     */
    private void handlePatientFromNative(Patient patient) {
        // Slow, make it better

        int pos = checkIfListContainsPatient(patient);
        if (pos == -1) {
            mPatientArrayList.add(patient);
        } else {
            Patient p = mPatientArrayList.get(pos);
            mPatientArrayList.remove(pos);
            mPatientArrayList.add(pos, p);
        }
    }

    private int checkIfListContainsPatient(Patient patient) {
        int size = mPatientArrayList.size();
        if (size == 0)
            return -1;

        for (int i = 0; i < size; i++) {
            Patient p = mPatientArrayList.get(i);
            if (p.getName().equals(patient.getName()) &&
                    p.getSurname().equals(patient.getSurname()))
                return i;
        }
        return -1;
    }
}
