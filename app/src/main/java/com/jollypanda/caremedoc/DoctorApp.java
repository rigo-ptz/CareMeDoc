package com.jollypanda.caremedoc;

import android.app.Application;

import com.jollypanda.caremedoc.api.interaction.PatientsListApi;

/**
 * Application class.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 */
public class DoctorApp extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        PatientsListApi api = PatientsListApi.getInstance();
        api.connectToSmartSpace();
    }
}
