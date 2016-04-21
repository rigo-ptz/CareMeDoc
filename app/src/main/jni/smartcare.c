#include "smartcare.h"



#if INCLUDE_CLASS_DOCTOR
sslog_class_t *CLASS_DOCTOR;
#endif
#if INCLUDE_CLASS_CARING
sslog_class_t *CLASS_CARING;
#endif
#if INCLUDE_CLASS_HOSPITAL
sslog_class_t *CLASS_HOSPITAL;
#endif
#if INCLUDE_CLASS_NURSE
sslog_class_t *CLASS_NURSE;
#endif
#if INCLUDE_CLASS_PERSON
sslog_class_t *CLASS_PERSON;
#endif
#if INCLUDE_CLASS_PHARMACY
sslog_class_t *CLASS_PHARMACY;
#endif
#if INCLUDE_CLASS_PROFILE
sslog_class_t *CLASS_PROFILE;
#endif
#if INCLUDE_CLASS_LOCATION
sslog_class_t *CLASS_LOCATION;
#endif
#if INCLUDE_CLASS_ALARM
sslog_class_t *CLASS_ALARM;
#endif
#if INCLUDE_CLASS_BED
sslog_class_t *CLASS_BED;
#endif
#if INCLUDE_CLASS_PATIENT
sslog_class_t *CLASS_PATIENT;
#endif
#if INCLUDE_CLASS_THING
sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_EQUIPMENT
sslog_class_t *CLASS_EQUIPMENT;
#endif
#if INCLUDE_CLASS_ADVICE
sslog_class_t *CLASS_ADVICE;
#endif
#if INCLUDE_CLASS_DRUG
sslog_class_t *CLASS_DRUG;
#endif
#if INCLUDE_CLASS_AMBULANCE
sslog_class_t *CLASS_AMBULANCE;
#endif
#if INCLUDE_CLASS_MEDIC
sslog_class_t *CLASS_MEDIC;
#endif
#if INCLUDE_CLASS_NOTHING
sslog_class_t *CLASS_NOTHING;
#endif


#if INCLUDE_PROPERTY_HASSTATIONAREQUIPMENT
sslog_property_t *PROPERTY_HASSTATIONAREQUIPMENT;
#endif
#if INCLUDE_PROPERTY_TAKEDRUGTIME
sslog_property_t *PROPERTY_TAKEDRUGTIME;
#endif
#if INCLUDE_PROPERTY_USEEQUIPMENTTIME
sslog_property_t *PROPERTY_USEEQUIPMENTTIME;
#endif
#if INCLUDE_PROPERTY_USERNAME
sslog_property_t *PROPERTY_USERNAME;
#endif
#if INCLUDE_PROPERTY_ISONLINE
sslog_property_t *PROPERTY_ISONLINE;
#endif
#if INCLUDE_PROPERTY_FREEPATIENTCAPACITY
sslog_property_t *PROPERTY_FREEPATIENTCAPACITY;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSAVE
sslog_property_t *PROPERTY_HASDRUGTOSAVE;
#endif
#if INCLUDE_PROPERTY_EQUIPPARAMETER
sslog_property_t *PROPERTY_EQUIPPARAMETER;
#endif
#if INCLUDE_PROPERTY_IMG
sslog_property_t *PROPERTY_IMG;
#endif
#if INCLUDE_PROPERTY_HOSPITALNAME
sslog_property_t *PROPERTY_HOSPITALNAME;
#endif
#if INCLUDE_PROPERTY_HASDOCTOR
sslog_property_t *PROPERTY_HASDOCTOR;
#endif
#if INCLUDE_PROPERTY_CARNUMBER
sslog_property_t *PROPERTY_CARNUMBER;
#endif
#if INCLUDE_PROPERTY_SENDALARM
sslog_property_t *PROPERTY_SENDALARM;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOMEDICINE
sslog_property_t *PROPERTY_HASDRUGTOMEDICINE;
#endif
#if INCLUDE_PROPERTY_ADVICETEXT
sslog_property_t *PROPERTY_ADVICETEXT;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOTAKE
sslog_property_t *PROPERTY_HASDRUGTOTAKE;
#endif
#if INCLUDE_PROPERTY_DRUGNAME
sslog_property_t *PROPERTY_DRUGNAME;
#endif
#if INCLUDE_PROPERTY_SENDADVICE
sslog_property_t *PROPERTY_SENDADVICE;
#endif
#if INCLUDE_PROPERTY_AGE
sslog_property_t *PROPERTY_AGE;
#endif
#if INCLUDE_PROPERTY_DRUGANNOTATION
sslog_property_t *PROPERTY_DRUGANNOTATION;
#endif
#if INCLUDE_PROPERTY_ALARMSTATUS
sslog_property_t *PROPERTY_ALARMSTATUS;
#endif
#if INCLUDE_PROPERTY_PHARMNAME
sslog_property_t *PROPERTY_PHARMNAME;
#endif
#if INCLUDE_PROPERTY_HASPERSLOCATION
sslog_property_t *PROPERTY_HASPERSLOCATION;
#endif
#if INCLUDE_PROPERTY_HASAMBLOCATION
sslog_property_t *PROPERTY_HASAMBLOCATION;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSALE
sslog_property_t *PROPERTY_HASDRUGTOSALE;
#endif
#if INCLUDE_PROPERTY_WORKHOSPITAL
sslog_property_t *PROPERTY_WORKHOSPITAL;
#endif
#if INCLUDE_PROPERTY_ALARMTIME
sslog_property_t *PROPERTY_ALARMTIME;
#endif
#if INCLUDE_PROPERTY_HASHOSPLOCATION
sslog_property_t *PROPERTY_HASHOSPLOCATION;
#endif
#if INCLUDE_PROPERTY_PHONE
sslog_property_t *PROPERTY_PHONE;
#endif
#if INCLUDE_PROPERTY_HASPHARMLOCATION
sslog_property_t *PROPERTY_HASPHARMLOCATION;
#endif
#if INCLUDE_PROPERTY_DOSAGE
sslog_property_t *PROPERTY_DOSAGE;
#endif
#if INCLUDE_PROPERTY_LONG
sslog_property_t *PROPERTY_LONG;
#endif
#if INCLUDE_PROPERTY_LAT
sslog_property_t *PROPERTY_LAT;
#endif
#if INCLUDE_PROPERTY_PERSONINFORMATION
sslog_property_t *PROPERTY_PERSONINFORMATION;
#endif
#if INCLUDE_PROPERTY_PASSWORD
sslog_property_t *PROPERTY_PASSWORD;
#endif
#if INCLUDE_PROPERTY_MBOX
sslog_property_t *PROPERTY_MBOX;
#endif
#if INCLUDE_PROPERTY_HASPORTABLEEQUIPMENT
sslog_property_t *PROPERTY_HASPORTABLEEQUIPMENT;
#endif
#if INCLUDE_PROPERTY_WORKAMBULANCE
sslog_property_t *PROPERTY_WORKAMBULANCE;
#endif
#if INCLUDE_PROPERTY_NAME
sslog_property_t *PROPERTY_NAME;
#endif
#if INCLUDE_PROPERTY_ADVICETIME
sslog_property_t *PROPERTY_ADVICETIME;
#endif



/**
 * @brief Register ontology.
 *
 * It creates all structures, such as classes and properties. Use it firs in your propgramm.
 */
void register_ontology()
{    
#if INCLUDE_PROPERTY_HASSTATIONAREQUIPMENT
PROPERTY_HASSTATIONAREQUIPMENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasStationarEquipment", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_TAKEDRUGTIME
PROPERTY_TAKEDRUGTIME =  sslog_new_property("http://oss.fruct.org/smartcare#takeDrugTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_USEEQUIPMENTTIME
PROPERTY_USEEQUIPMENTTIME =  sslog_new_property("http://oss.fruct.org/smartcare#useEquipmentTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_USERNAME
PROPERTY_USERNAME =  sslog_new_property("http://oss.fruct.org/smartcare#username", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ISONLINE
PROPERTY_ISONLINE =  sslog_new_property("http://oss.fruct.org/smartcare#isOnline", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_FREEPATIENTCAPACITY
PROPERTY_FREEPATIENTCAPACITY =  sslog_new_property("http://oss.fruct.org/smartcare#freePatientCapacity", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSAVE
PROPERTY_HASDRUGTOSAVE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToSave", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_EQUIPPARAMETER
PROPERTY_EQUIPPARAMETER =  sslog_new_property("http://oss.fruct.org/smartcare#equipParameter", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_IMG
PROPERTY_IMG =  sslog_new_property("http://oss.fruct.org/smartcare#img", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HOSPITALNAME
PROPERTY_HOSPITALNAME =  sslog_new_property("http://oss.fruct.org/smartcare#hospitalName", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASDOCTOR
PROPERTY_HASDOCTOR =  sslog_new_property("http://oss.fruct.org/smartcare#hasDoctor", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_CARNUMBER
PROPERTY_CARNUMBER =  sslog_new_property("http://oss.fruct.org/smartcare#carNumber", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SENDALARM
PROPERTY_SENDALARM =  sslog_new_property("http://oss.fruct.org/smartcare#sendAlarm", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOMEDICINE
PROPERTY_HASDRUGTOMEDICINE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToMedicine", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ADVICETEXT
PROPERTY_ADVICETEXT =  sslog_new_property("http://oss.fruct.org/smartcare#adviceText", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOTAKE
PROPERTY_HASDRUGTOTAKE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToTake", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DRUGNAME
PROPERTY_DRUGNAME =  sslog_new_property("http://oss.fruct.org/smartcare#drugName", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SENDADVICE
PROPERTY_SENDADVICE =  sslog_new_property("http://oss.fruct.org/smartcare#sendAdvice", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_AGE
PROPERTY_AGE =  sslog_new_property("http://oss.fruct.org/smartcare#age", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DRUGANNOTATION
PROPERTY_DRUGANNOTATION =  sslog_new_property("http://oss.fruct.org/smartcare#drugAnnotation", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ALARMSTATUS
PROPERTY_ALARMSTATUS =  sslog_new_property("http://oss.fruct.org/smartcare#alarmStatus", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PHARMNAME
PROPERTY_PHARMNAME =  sslog_new_property("http://oss.fruct.org/smartcare#pharmName", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPERSLOCATION
PROPERTY_HASPERSLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasPersLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASAMBLOCATION
PROPERTY_HASAMBLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasAmbLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSALE
PROPERTY_HASDRUGTOSALE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToSale", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_WORKHOSPITAL
PROPERTY_WORKHOSPITAL =  sslog_new_property("http://oss.fruct.org/smartcare#workHospital", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ALARMTIME
PROPERTY_ALARMTIME =  sslog_new_property("http://oss.fruct.org/smartcare#alarmTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASHOSPLOCATION
PROPERTY_HASHOSPLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasHospLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_PHONE
PROPERTY_PHONE =  sslog_new_property("http://oss.fruct.org/smartcare#phone", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPHARMLOCATION
PROPERTY_HASPHARMLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasPharmLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DOSAGE
PROPERTY_DOSAGE =  sslog_new_property("http://oss.fruct.org/smartcare#dosage", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_LONG
PROPERTY_LONG =  sslog_new_property("http://oss.fruct.org/smartcare#long", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_LAT
PROPERTY_LAT =  sslog_new_property("http://oss.fruct.org/smartcare#lat", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PERSONINFORMATION
PROPERTY_PERSONINFORMATION =  sslog_new_property("http://oss.fruct.org/smartcare#personInformation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_PASSWORD
PROPERTY_PASSWORD =  sslog_new_property("http://oss.fruct.org/smartcare#password", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_MBOX
PROPERTY_MBOX =  sslog_new_property("http://oss.fruct.org/smartcare#mbox", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPORTABLEEQUIPMENT
PROPERTY_HASPORTABLEEQUIPMENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasPortableEquipment", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_WORKAMBULANCE
PROPERTY_WORKAMBULANCE =  sslog_new_property("http://oss.fruct.org/smartcare#workAmbulance", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_NAME
PROPERTY_NAME =  sslog_new_property("http://oss.fruct.org/smartcare#name", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ADVICETIME
PROPERTY_ADVICETIME =  sslog_new_property("http://oss.fruct.org/smartcare#adviceTime", SSLOG_PROPERTY_TYPE_DATA);
#endif



#if INCLUDE_CLASS_DOCTOR
CLASS_DOCTOR = sslog_new_class("http://oss.fruct.org/smartcare#Doctor");
#endif
#if INCLUDE_CLASS_CARING
CLASS_CARING = sslog_new_class("http://oss.fruct.org/smartcare#Caring");
#endif
#if INCLUDE_CLASS_HOSPITAL
CLASS_HOSPITAL = sslog_new_class("http://oss.fruct.org/smartcare#Hospital");
#endif
#if INCLUDE_CLASS_NURSE
CLASS_NURSE = sslog_new_class("http://oss.fruct.org/smartcare#Nurse");
#endif
#if INCLUDE_CLASS_PERSON
CLASS_PERSON = sslog_new_class("http://oss.fruct.org/smartcare#Person");
#endif
#if INCLUDE_CLASS_PHARMACY
CLASS_PHARMACY = sslog_new_class("http://oss.fruct.org/smartcare#Pharmacy");
#endif
#if INCLUDE_CLASS_PROFILE
CLASS_PROFILE = sslog_new_class("http://oss.fruct.org/smartcare#Profile");
#endif
#if INCLUDE_CLASS_LOCATION
CLASS_LOCATION = sslog_new_class("http://oss.fruct.org/smartcare#Location");
#endif
#if INCLUDE_CLASS_ALARM
CLASS_ALARM = sslog_new_class("http://oss.fruct.org/smartcare#Alarm");
#endif
#if INCLUDE_CLASS_BED
CLASS_BED = sslog_new_class("http://oss.fruct.org/smartcare#Bed");
#endif
#if INCLUDE_CLASS_PATIENT
CLASS_PATIENT = sslog_new_class("http://oss.fruct.org/smartcare#Patient");
#endif
#if INCLUDE_CLASS_THING
CLASS_THING = sslog_new_class("http://www.w3.org/2002/07/owl#Thing");
#endif
#if INCLUDE_CLASS_EQUIPMENT
CLASS_EQUIPMENT = sslog_new_class("http://oss.fruct.org/smartcare#Equipment");
#endif
#if INCLUDE_CLASS_ADVICE
CLASS_ADVICE = sslog_new_class("http://oss.fruct.org/smartcare#Advice");
#endif
#if INCLUDE_CLASS_DRUG
CLASS_DRUG = sslog_new_class("http://oss.fruct.org/smartcare#Drug");
#endif
#if INCLUDE_CLASS_AMBULANCE
CLASS_AMBULANCE = sslog_new_class("http://oss.fruct.org/smartcare#Ambulance");
#endif
#if INCLUDE_CLASS_MEDIC
CLASS_MEDIC = sslog_new_class("http://oss.fruct.org/smartcare#Medic");
#endif
#if INCLUDE_CLASS_NOTHING
CLASS_NOTHING = sslog_new_class("http://www.w3.org/2002/07/owl#Nothing");
#endif



}


