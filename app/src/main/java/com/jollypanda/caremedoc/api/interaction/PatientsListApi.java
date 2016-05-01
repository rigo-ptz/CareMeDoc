package com.jollypanda.caremedoc.api.interaction;

import com.jollypanda.caremedoc.api.model.Patient;
import com.jollypanda.caremedoc.tools.Constants;

import java.util.ArrayList;
import java.util.Observable;

/**
 * Actions with SIB for getting patient list
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class PatientsListApi extends Observable {

    static {
        System.loadLibrary(Constants.JNI_LIBRARY_HELLO);
    }
    private native int connectSmartSpace(String name, String ip, int port);
    private native void disconnectSmartSpace();
    private native void subscribeForPatients(long nodeDescriptor);

    //    private static final String KP_SS_ADDRESS_LOCAL =  "78.46.130.194";
    private static final String SS_NAME =  "oss.fruct.org/smartcare";
    private static final String KP_SS_ADDRESS_LOCAL =  "192.168.56.1";

    private int nodeDescriptor;

    private static PatientsListApi instance = new PatientsListApi();

    public static PatientsListApi getInstance() {
        return instance;
    }

    private PatientsListApi() {
    }

    public void connectToSmartSpace() {
        nodeDescriptor = connectSmartSpace(SS_NAME, KP_SS_ADDRESS_LOCAL, 10010);
    }
    public void disconnectFromSmartSpace() {
        disconnectSmartSpace();
    }

    public void getResult() {
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
        setChanged();
        notifyObservers(patient);
    }
}
