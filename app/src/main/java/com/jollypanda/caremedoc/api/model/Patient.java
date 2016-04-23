package com.jollypanda.caremedoc.api.model;

/**
 * Class describing patient
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */
public class Patient {

    private String mName;
    private String mSurname;
    private String mMiddleName;
    private String mDescription;

    public Patient() {
    }

    public String getName() {
        return mName;
    }

    public void setName(String name) {
        mName = name;
    }

    public String getSurname() {
        return mSurname;
    }

    public void setSurname(String surname) {
        mSurname = surname;
    }

    public String getMiddleName() {
        return mMiddleName;
    }

    public void setMiddleName(String middleName) {
        mMiddleName = middleName;
    }

    public String getDescription() {
        return mDescription;
    }

    public void setDescription(String description) {
        mDescription = description;
    }
}
