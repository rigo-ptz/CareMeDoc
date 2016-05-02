package com.jollypanda.caremedoc.api.model;

/**
 * Contains information about ecg records, like date or some description.
 *
 * @author Yamushev Igor
 * @since 01.05.2016
 */
public class EcgItem {

    private String mDate;
    private String mDescription;

    public EcgItem(String date, String description) {
        mDate = date;
        mDescription = description;
    }

    public String getDate() {
        return mDate;
    }

    public String getDescription() {
        return mDescription;
    }
}
