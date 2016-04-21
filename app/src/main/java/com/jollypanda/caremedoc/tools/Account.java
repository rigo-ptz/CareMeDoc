package com.jollypanda.caremedoc.tools;

import android.content.SharedPreferences;

/**
 * Singleton for account data
 *
 * @author Yamushev Igor
 * @since 21.04.2016
 */
public class Account {

    private static Account instance = new Account();

    public static Account getInstance() {
        return instance;
    }

    public void saveLogin(SharedPreferences sharedPreferences, String login) {
        if (sharedPreferences != null)
            sharedPreferences.edit().putString(Constants.SHARED_PREFS_LOGIN, login).apply();
    }

    public void savePassword(SharedPreferences sharedPreferences, String password) {
        if (sharedPreferences != null)
            sharedPreferences.edit().putString(Constants.SHARED_PREFS_PASS, password).apply();
    }

    public String getLogin(SharedPreferences sharedPreferences) {
        return sharedPreferences == null ? null : sharedPreferences.getString(Constants.SHARED_PREFS_LOGIN, null);
    }

    public String getPassword(SharedPreferences sharedPreferences) {
        return sharedPreferences == null ? null : sharedPreferences.getString(Constants.SHARED_PREFS_PASS, null);
    }
}
