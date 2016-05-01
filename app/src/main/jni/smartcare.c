#include "smartcare.h"



#if INCLUDE_CLASS_THING
sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_ALARM
sslog_class_t *CLASS_ALARM;
#endif
#if INCLUDE_CLASS_DOCTOR
sslog_class_t *CLASS_DOCTOR;
#endif
#if INCLUDE_CLASS_NURSE
sslog_class_t *CLASS_NURSE;
#endif
#if INCLUDE_CLASS_ECGTWAVE
sslog_class_t *CLASS_ECGTWAVE;
#endif
#if INCLUDE_CLASS_ECGDIAGNOSIS
sslog_class_t *CLASS_ECGDIAGNOSIS;
#endif
#if INCLUDE_CLASS_LOCATION
sslog_class_t *CLASS_LOCATION;
#endif
#if INCLUDE_CLASS_ECGWAVECOMPONENT
sslog_class_t *CLASS_ECGWAVECOMPONENT;
#endif
#if INCLUDE_CLASS_ECGDATA
sslog_class_t *CLASS_ECGDATA;
#endif
#if INCLUDE_CLASS_ADVICE
sslog_class_t *CLASS_ADVICE;
#endif
#if INCLUDE_CLASS_PATIENTMETRICS
sslog_class_t *CLASS_PATIENTMETRICS;
#endif
#if INCLUDE_CLASS_MEDICALRECORDSCARD
sslog_class_t *CLASS_MEDICALRECORDSCARD;
#endif
#if INCLUDE_CLASS_PHARMACY
sslog_class_t *CLASS_PHARMACY;
#endif
#if INCLUDE_CLASS_NOTHING
sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_HOSPITAL
sslog_class_t *CLASS_HOSPITAL;
#endif
#if INCLUDE_CLASS_MEASURMENT
sslog_class_t *CLASS_MEASURMENT;
#endif
#if INCLUDE_CLASS_RHYTHM
sslog_class_t *CLASS_RHYTHM;
#endif
#if INCLUDE_CLASS_PROFILE
sslog_class_t *CLASS_PROFILE;
#endif
#if INCLUDE_CLASS_SERVEY
sslog_class_t *CLASS_SERVEY;
#endif
#if INCLUDE_CLASS_DISEASE
sslog_class_t *CLASS_DISEASE;
#endif
#if INCLUDE_CLASS_ECGSERVEY
sslog_class_t *CLASS_ECGSERVEY;
#endif
#if INCLUDE_CLASS_DOCUMENT
sslog_class_t *CLASS_DOCUMENT;
#endif
#if INCLUDE_CLASS_BED
sslog_class_t *CLASS_BED;
#endif
#if INCLUDE_CLASS_ECGLEAD
sslog_class_t *CLASS_ECGLEAD;
#endif
#if INCLUDE_CLASS_ECGQRSCOMPLEX
sslog_class_t *CLASS_ECGQRSCOMPLEX;
#endif
#if INCLUDE_CLASS_PATIENTMAP
sslog_class_t *CLASS_PATIENTMAP;
#endif
#if INCLUDE_CLASS_MEDIC
sslog_class_t *CLASS_MEDIC;
#endif
#if INCLUDE_CLASS_ANOMALY
sslog_class_t *CLASS_ANOMALY;
#endif
#if INCLUDE_CLASS_USHSERVEY
sslog_class_t *CLASS_USHSERVEY;
#endif
#if INCLUDE_CLASS_CARING
sslog_class_t *CLASS_CARING;
#endif
#if INCLUDE_CLASS_AMBULANCE
sslog_class_t *CLASS_AMBULANCE;
#endif
#if INCLUDE_CLASS_CRITERIA
sslog_class_t *CLASS_CRITERIA;
#endif
#if INCLUDE_CLASS_WAVEFORMSTRUCTURE
sslog_class_t *CLASS_WAVEFORMSTRUCTURE;
#endif
#if INCLUDE_CLASS_EQUIPMENT
sslog_class_t *CLASS_EQUIPMENT;
#endif
#if INCLUDE_CLASS_DRUG
sslog_class_t *CLASS_DRUG;
#endif
#if INCLUDE_CLASS_HEARTRATE
sslog_class_t *CLASS_HEARTRATE;
#endif
#if INCLUDE_CLASS_ECGXAXIS
sslog_class_t *CLASS_ECGXAXIS;
#endif
#if INCLUDE_CLASS_ECGPWAVE
sslog_class_t *CLASS_ECGPWAVE;
#endif
#if INCLUDE_CLASS_PERSON
sslog_class_t *CLASS_PERSON;
#endif
#if INCLUDE_CLASS_PATIENT
sslog_class_t *CLASS_PATIENT;
#endif
#if INCLUDE_CLASS_ECGYAXIS
sslog_class_t *CLASS_ECGYAXIS;
#endif
#if INCLUDE_CLASS_AUTHREQUEST
sslog_class_t *CLASS_AUTHREQUEST;
#endif


#if INCLUDE_PROPERTY_HASTHEARTRHYTHM
sslog_property_t *PROPERTY_HASTHEARTRHYTHM;
#endif
#if INCLUDE_PROPERTY_VENTICULARRYTHM
sslog_property_t *PROPERTY_VENTICULARRYTHM;
#endif
#if INCLUDE_PROPERTY_HASSTATIONAREQUIPMENT
sslog_property_t *PROPERTY_HASSTATIONAREQUIPMENT;
#endif
#if INCLUDE_PROPERTY_TAKEDRUGTIME
sslog_property_t *PROPERTY_TAKEDRUGTIME;
#endif
#if INCLUDE_PROPERTY_HASPATIENTMAP
sslog_property_t *PROPERTY_HASPATIENTMAP;
#endif
#if INCLUDE_PROPERTY_RESPONSETOALARM
sslog_property_t *PROPERTY_RESPONSETOALARM;
#endif
#if INCLUDE_PROPERTY_ISPATIENTDRUGADDICTED
sslog_property_t *PROPERTY_ISPATIENTDRUGADDICTED;
#endif
#if INCLUDE_PROPERTY_STARTWAVECOMP
sslog_property_t *PROPERTY_STARTWAVECOMP;
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
#if INCLUDE_PROPERTY_HASCRITERIA
sslog_property_t *PROPERTY_HASCRITERIA;
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
#if INCLUDE_PROPERTY_PATIENTWEIGHT
sslog_property_t *PROPERTY_PATIENTWEIGHT;
#endif
#if INCLUDE_PROPERTY_READYTOHELP
sslog_property_t *PROPERTY_READYTOHELP;
#endif
#if INCLUDE_PROPERTY_IMG
sslog_property_t *PROPERTY_IMG;
#endif
#if INCLUDE_PROPERTY_PASSAUTH
sslog_property_t *PROPERTY_PASSAUTH;
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
#if INCLUDE_PROPERTY_HASQRSCOMPLEX
sslog_property_t *PROPERTY_HASQRSCOMPLEX;
#endif
#if INCLUDE_PROPERTY_ECGDATAURL
sslog_property_t *PROPERTY_ECGDATAURL;
#endif
#if INCLUDE_PROPERTY_HASMEASURMENT
sslog_property_t *PROPERTY_HASMEASURMENT;
#endif
#if INCLUDE_PROPERTY_SENDALARM
sslog_property_t *PROPERTY_SENDALARM;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOMEDICINE
sslog_property_t *PROPERTY_HASDRUGTOMEDICINE;
#endif
#if INCLUDE_PROPERTY_SPECIALLITY
sslog_property_t *PROPERTY_SPECIALLITY;
#endif
#if INCLUDE_PROPERTY_ADVICETEXT
sslog_property_t *PROPERTY_ADVICETEXT;
#endif
#if INCLUDE_PROPERTY_XPOINT
sslog_property_t *PROPERTY_XPOINT;
#endif
#if INCLUDE_PROPERTY_HASYAXIS
sslog_property_t *PROPERTY_HASYAXIS;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOTAKE
sslog_property_t *PROPERTY_HASDRUGTOTAKE;
#endif
#if INCLUDE_PROPERTY_HASMEDICALRECORDSCARD
sslog_property_t *PROPERTY_HASMEDICALRECORDSCARD;
#endif
#if INCLUDE_PROPERTY_HASACCESS
sslog_property_t *PROPERTY_HASACCESS;
#endif
#if INCLUDE_PROPERTY_VENTICULARRATE
sslog_property_t *PROPERTY_VENTICULARRATE;
#endif
#if INCLUDE_PROPERTY_CONTAINECGSURVEYS
sslog_property_t *PROPERTY_CONTAINECGSURVEYS;
#endif
#if INCLUDE_PROPERTY_DRUGNAME
sslog_property_t *PROPERTY_DRUGNAME;
#endif
#if INCLUDE_PROPERTY_SENDADVICE
sslog_property_t *PROPERTY_SENDADVICE;
#endif
#if INCLUDE_PROPERTY_HASPWAVE
sslog_property_t *PROPERTY_HASPWAVE;
#endif
#if INCLUDE_PROPERTY_HASDOCUMENT
sslog_property_t *PROPERTY_HASDOCUMENT;
#endif
#if INCLUDE_PROPERTY_ISPATIENTMEDICINEADDICTED
sslog_property_t *PROPERTY_ISPATIENTMEDICINEADDICTED;
#endif
#if INCLUDE_PROPERTY_SERVEYDATE
sslog_property_t *PROPERTY_SERVEYDATE;
#endif
#if INCLUDE_PROPERTY_DATAVALUE
sslog_property_t *PROPERTY_DATAVALUE;
#endif
#if INCLUDE_PROPERTY_LEADDESCRIPTION
sslog_property_t *PROPERTY_LEADDESCRIPTION;
#endif
#if INCLUDE_PROPERTY_AGE
sslog_property_t *PROPERTY_AGE;
#endif
#if INCLUDE_PROPERTY_ALARMSTATUS
sslog_property_t *PROPERTY_ALARMSTATUS;
#endif
#if INCLUDE_PROPERTY_DRUGANNOTATION
sslog_property_t *PROPERTY_DRUGANNOTATION;
#endif
#if INCLUDE_PROPERTY_PATIENTBLOODTYPE
sslog_property_t *PROPERTY_PATIENTBLOODTYPE;
#endif
#if INCLUDE_PROPERTY_PHARMNAME
sslog_property_t *PROPERTY_PHARMNAME;
#endif
#if INCLUDE_PROPERTY_ATRIALRYTHM
sslog_property_t *PROPERTY_ATRIALRYTHM;
#endif
#if INCLUDE_PROPERTY_HASPERSLOCATION
sslog_property_t *PROPERTY_HASPERSLOCATION;
#endif
#if INCLUDE_PROPERTY_PATIENTRHFACTOR
sslog_property_t *PROPERTY_PATIENTRHFACTOR;
#endif
#if INCLUDE_PROPERTY_SURVEYECGINFO
sslog_property_t *PROPERTY_SURVEYECGINFO;
#endif
#if INCLUDE_PROPERTY_CONTAINUSHSURVEYS
sslog_property_t *PROPERTY_CONTAINUSHSURVEYS;
#endif
#if INCLUDE_PROPERTY_HASAMBLOCATION
sslog_property_t *PROPERTY_HASAMBLOCATION;
#endif
#if INCLUDE_PROPERTY_DISEASEDESCRIPTION
sslog_property_t *PROPERTY_DISEASEDESCRIPTION;
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSALE
sslog_property_t *PROPERTY_HASDRUGTOSALE;
#endif
#if INCLUDE_PROPERTY_SERVEYRESULT
sslog_property_t *PROPERTY_SERVEYRESULT;
#endif
#if INCLUDE_PROPERTY_PATIENTHEIGHT
sslog_property_t *PROPERTY_PATIENTHEIGHT;
#endif
#if INCLUDE_PROPERTY_HASLEAD
sslog_property_t *PROPERTY_HASLEAD;
#endif
#if INCLUDE_PROPERTY_WORKHOSPITAL
sslog_property_t *PROPERTY_WORKHOSPITAL;
#endif
#if INCLUDE_PROPERTY_ALARMTIME
sslog_property_t *PROPERTY_ALARMTIME;
#endif
#if INCLUDE_PROPERTY_PHONE
sslog_property_t *PROPERTY_PHONE;
#endif
#if INCLUDE_PROPERTY_HASHOSPLOCATION
sslog_property_t *PROPERTY_HASHOSPLOCATION;
#endif
#if INCLUDE_PROPERTY_STARTTIME
sslog_property_t *PROPERTY_STARTTIME;
#endif
#if INCLUDE_PROPERTY_HASHEARTRATE
sslog_property_t *PROPERTY_HASHEARTRATE;
#endif
#if INCLUDE_PROPERTY_HASTWAVE
sslog_property_t *PROPERTY_HASTWAVE;
#endif
#if INCLUDE_PROPERTY_MEASURMENTDESCRIPTION
sslog_property_t *PROPERTY_MEASURMENTDESCRIPTION;
#endif
#if INCLUDE_PROPERTY_HASPHARMLOCATION
sslog_property_t *PROPERTY_HASPHARMLOCATION;
#endif
#if INCLUDE_PROPERTY_MEASURMENTVALUE
sslog_property_t *PROPERTY_MEASURMENTVALUE;
#endif
#if INCLUDE_PROPERTY_SERVEYDATALINK
sslog_property_t *PROPERTY_SERVEYDATALINK;
#endif
#if INCLUDE_PROPERTY_HASANOMALY
sslog_property_t *PROPERTY_HASANOMALY;
#endif
#if INCLUDE_PROPERTY_INTERVALSCALE
sslog_property_t *PROPERTY_INTERVALSCALE;
#endif
#if INCLUDE_PROPERTY_ISPATIENTSMOKE
sslog_property_t *PROPERTY_ISPATIENTSMOKE;
#endif
#if INCLUDE_PROPERTY_HASXAXIS
sslog_property_t *PROPERTY_HASXAXIS;
#endif
#if INCLUDE_PROPERTY_HASPATIENTMETRICS
sslog_property_t *PROPERTY_HASPATIENTMETRICS;
#endif
#if INCLUDE_PROPERTY_ENDWAVECOMP
sslog_property_t *PROPERTY_ENDWAVECOMP;
#endif
#if INCLUDE_PROPERTY_DOSAGE
sslog_property_t *PROPERTY_DOSAGE;
#endif
#if INCLUDE_PROPERTY_SERVEYTYPE
sslog_property_t *PROPERTY_SERVEYTYPE;
#endif
#if INCLUDE_PROPERTY_DOCUMENTNUMBERFULL
sslog_property_t *PROPERTY_DOCUMENTNUMBERFULL;
#endif
#if INCLUDE_PROPERTY_PEAK
sslog_property_t *PROPERTY_PEAK;
#endif
#if INCLUDE_PROPERTY_LONG
sslog_property_t *PROPERTY_LONG;
#endif
#if INCLUDE_PROPERTY_ISPATIENTALCOHOLADDICTED
sslog_property_t *PROPERTY_ISPATIENTALCOHOLADDICTED;
#endif
#if INCLUDE_PROPERTY_SERVEYDESCRIPTION
sslog_property_t *PROPERTY_SERVEYDESCRIPTION;
#endif
#if INCLUDE_PROPERTY_DOCUMENTTYPE
sslog_property_t *PROPERTY_DOCUMENTTYPE;
#endif
#if INCLUDE_PROPERTY_HASDIAGNOSIS
sslog_property_t *PROPERTY_HASDIAGNOSIS;
#endif
#if INCLUDE_PROPERTY_LAT
sslog_property_t *PROPERTY_LAT;
#endif
#if INCLUDE_PROPERTY_SURNAME
sslog_property_t *PROPERTY_SURNAME;
#endif
#if INCLUDE_PROPERTY_DOCUMENTRELEASEDATE
sslog_property_t *PROPERTY_DOCUMENTRELEASEDATE;
#endif
#if INCLUDE_PROPERTY_AUTHREQUESTSTATUS
sslog_property_t *PROPERTY_AUTHREQUESTSTATUS;
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
#if INCLUDE_PROPERTY_ATRIALRATE
sslog_property_t *PROPERTY_ATRIALRATE;
#endif
#if INCLUDE_PROPERTY_WORKAMBULANCE
sslog_property_t *PROPERTY_WORKAMBULANCE;
#endif
#if INCLUDE_PROPERTY_NAME
sslog_property_t *PROPERTY_NAME;
#endif
#if INCLUDE_PROPERTY_ENDTIME
sslog_property_t *PROPERTY_ENDTIME;
#endif
#if INCLUDE_PROPERTY_ADVICETIME
sslog_property_t *PROPERTY_ADVICETIME;
#endif
#if INCLUDE_PROPERTY_HASWAVEFORMSTRUCTURE
sslog_property_t *PROPERTY_HASWAVEFORMSTRUCTURE;
#endif
#if INCLUDE_PROPERTY_HASWAVECOMPONENT
sslog_property_t *PROPERTY_HASWAVECOMPONENT;
#endif
#if INCLUDE_PROPERTY_DISEASETYPE
sslog_property_t *PROPERTY_DISEASETYPE;
#endif
#if INCLUDE_PROPERTY_SERVEYUSHINFO
sslog_property_t *PROPERTY_SERVEYUSHINFO;
#endif
#if INCLUDE_PROPERTY_CONTAINDISEASES
sslog_property_t *PROPERTY_CONTAINDISEASES;
#endif



/**
 * @brief Register ontology.
 *
 * It creates all structures, such as classes and properties. Use it firs in your propgramm.
 */
void register_ontology()
{    
#if INCLUDE_PROPERTY_HASTHEARTRHYTHM
PROPERTY_HASTHEARTRHYTHM =  sslog_new_property("http://oss.fruct.org/smartcare#hastHeartRhythm", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_VENTICULARRYTHM
PROPERTY_VENTICULARRYTHM =  sslog_new_property("http://oss.fruct.org/smartcare#venticularRythm", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASSTATIONAREQUIPMENT
PROPERTY_HASSTATIONAREQUIPMENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasStationarEquipment", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_TAKEDRUGTIME
PROPERTY_TAKEDRUGTIME =  sslog_new_property("http://oss.fruct.org/smartcare#takeDrugTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPATIENTMAP
PROPERTY_HASPATIENTMAP =  sslog_new_property("http://oss.fruct.org/smartcare#hasPatientMap", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_RESPONSETOALARM
PROPERTY_RESPONSETOALARM =  sslog_new_property("http://oss.fruct.org/smartcare#responseToAlarm", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ISPATIENTDRUGADDICTED
PROPERTY_ISPATIENTDRUGADDICTED =  sslog_new_property("http://oss.fruct.org/smartcare#isPatientDrugAddicted", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_STARTWAVECOMP
PROPERTY_STARTWAVECOMP =  sslog_new_property("http://oss.fruct.org/smartcare#startWaveComp", SSLOG_PROPERTY_TYPE_DATA);
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
#if INCLUDE_PROPERTY_HASCRITERIA
PROPERTY_HASCRITERIA =  sslog_new_property("http://oss.fruct.org/smartcare#hasCriteria", SSLOG_PROPERTY_TYPE_OBJECT);
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
#if INCLUDE_PROPERTY_PATIENTWEIGHT
PROPERTY_PATIENTWEIGHT =  sslog_new_property("http://oss.fruct.org/smartcare#patientWeight", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_READYTOHELP
PROPERTY_READYTOHELP =  sslog_new_property("http://oss.fruct.org/smartcare#readyToHelp", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_IMG
PROPERTY_IMG =  sslog_new_property("http://oss.fruct.org/smartcare#img", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PASSAUTH
PROPERTY_PASSAUTH =  sslog_new_property("http://oss.fruct.org/smartcare#passAuth", SSLOG_PROPERTY_TYPE_OBJECT);
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
#if INCLUDE_PROPERTY_HASQRSCOMPLEX
PROPERTY_HASQRSCOMPLEX =  sslog_new_property("http://oss.fruct.org/smartcare#hasQRSComplex", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ECGDATAURL
PROPERTY_ECGDATAURL =  sslog_new_property("http://oss.fruct.org/smartcare#ecgDataUrl", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASMEASURMENT
PROPERTY_HASMEASURMENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasMeasurment", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_SENDALARM
PROPERTY_SENDALARM =  sslog_new_property("http://oss.fruct.org/smartcare#sendAlarm", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOMEDICINE
PROPERTY_HASDRUGTOMEDICINE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToMedicine", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_SPECIALLITY
PROPERTY_SPECIALLITY =  sslog_new_property("http://oss.fruct.org/smartcare#speciallity", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ADVICETEXT
PROPERTY_ADVICETEXT =  sslog_new_property("http://oss.fruct.org/smartcare#adviceText", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_XPOINT
PROPERTY_XPOINT =  sslog_new_property("http://oss.fruct.org/smartcare#xPoint", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASYAXIS
PROPERTY_HASYAXIS =  sslog_new_property("http://oss.fruct.org/smartcare#hasYAxis", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOTAKE
PROPERTY_HASDRUGTOTAKE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToTake", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASMEDICALRECORDSCARD
PROPERTY_HASMEDICALRECORDSCARD =  sslog_new_property("http://oss.fruct.org/smartcare#hasMedicalRecordsCard", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASACCESS
PROPERTY_HASACCESS =  sslog_new_property("http://oss.fruct.org/smartcare#hasAccess", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_VENTICULARRATE
PROPERTY_VENTICULARRATE =  sslog_new_property("http://oss.fruct.org/smartcare#venticularRate", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_CONTAINECGSURVEYS
PROPERTY_CONTAINECGSURVEYS =  sslog_new_property("http://oss.fruct.org/smartcare#containECGSurveys", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DRUGNAME
PROPERTY_DRUGNAME =  sslog_new_property("http://oss.fruct.org/smartcare#drugName", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SENDADVICE
PROPERTY_SENDADVICE =  sslog_new_property("http://oss.fruct.org/smartcare#sendAdvice", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASPWAVE
PROPERTY_HASPWAVE =  sslog_new_property("http://oss.fruct.org/smartcare#hasPWave", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASDOCUMENT
PROPERTY_HASDOCUMENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasDocument", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ISPATIENTMEDICINEADDICTED
PROPERTY_ISPATIENTMEDICINEADDICTED =  sslog_new_property("http://oss.fruct.org/smartcare#isPatientMedicineAddicted", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SERVEYDATE
PROPERTY_SERVEYDATE =  sslog_new_property("http://oss.fruct.org/smartcare#serveyDate", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DATAVALUE
PROPERTY_DATAVALUE =  sslog_new_property("http://oss.fruct.org/smartcare#dataValue", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_LEADDESCRIPTION
PROPERTY_LEADDESCRIPTION =  sslog_new_property("http://oss.fruct.org/smartcare#leadDescription", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_AGE
PROPERTY_AGE =  sslog_new_property("http://oss.fruct.org/smartcare#age", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ALARMSTATUS
PROPERTY_ALARMSTATUS =  sslog_new_property("http://oss.fruct.org/smartcare#alarmStatus", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DRUGANNOTATION
PROPERTY_DRUGANNOTATION =  sslog_new_property("http://oss.fruct.org/smartcare#drugAnnotation", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PATIENTBLOODTYPE
PROPERTY_PATIENTBLOODTYPE =  sslog_new_property("http://oss.fruct.org/smartcare#patientBloodType", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PHARMNAME
PROPERTY_PHARMNAME =  sslog_new_property("http://oss.fruct.org/smartcare#pharmName", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ATRIALRYTHM
PROPERTY_ATRIALRYTHM =  sslog_new_property("http://oss.fruct.org/smartcare#atrialRythm", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPERSLOCATION
PROPERTY_HASPERSLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasPersLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_PATIENTRHFACTOR
PROPERTY_PATIENTRHFACTOR =  sslog_new_property("http://oss.fruct.org/smartcare#patientRhFactor", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SURVEYECGINFO
PROPERTY_SURVEYECGINFO =  sslog_new_property("http://oss.fruct.org/smartcare#surveyEcgInfo", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_CONTAINUSHSURVEYS
PROPERTY_CONTAINUSHSURVEYS =  sslog_new_property("http://oss.fruct.org/smartcare#containUSHSurveys", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASAMBLOCATION
PROPERTY_HASAMBLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasAmbLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DISEASEDESCRIPTION
PROPERTY_DISEASEDESCRIPTION =  sslog_new_property("http://oss.fruct.org/smartcare#diseaseDescription", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASDRUGTOSALE
PROPERTY_HASDRUGTOSALE =  sslog_new_property("http://oss.fruct.org/smartcare#hasDrugToSale", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_SERVEYRESULT
PROPERTY_SERVEYRESULT =  sslog_new_property("http://oss.fruct.org/smartcare#serveyResult", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PATIENTHEIGHT
PROPERTY_PATIENTHEIGHT =  sslog_new_property("http://oss.fruct.org/smartcare#patientHeight", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASLEAD
PROPERTY_HASLEAD =  sslog_new_property("http://oss.fruct.org/smartcare#hasLead", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_WORKHOSPITAL
PROPERTY_WORKHOSPITAL =  sslog_new_property("http://oss.fruct.org/smartcare#workHospital", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ALARMTIME
PROPERTY_ALARMTIME =  sslog_new_property("http://oss.fruct.org/smartcare#alarmTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PHONE
PROPERTY_PHONE =  sslog_new_property("http://oss.fruct.org/smartcare#phone", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASHOSPLOCATION
PROPERTY_HASHOSPLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasHospLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_STARTTIME
PROPERTY_STARTTIME =  sslog_new_property("http://oss.fruct.org/smartcare#startTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASHEARTRATE
PROPERTY_HASHEARTRATE =  sslog_new_property("http://oss.fruct.org/smartcare#hasHeartRate", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASTWAVE
PROPERTY_HASTWAVE =  sslog_new_property("http://oss.fruct.org/smartcare#hasTWave", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_MEASURMENTDESCRIPTION
PROPERTY_MEASURMENTDESCRIPTION =  sslog_new_property("http://oss.fruct.org/smartcare#measurmentDescription", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASPHARMLOCATION
PROPERTY_HASPHARMLOCATION =  sslog_new_property("http://oss.fruct.org/smartcare#hasPharmLocation", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_MEASURMENTVALUE
PROPERTY_MEASURMENTVALUE =  sslog_new_property("http://oss.fruct.org/smartcare#measurmentValue", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SERVEYDATALINK
PROPERTY_SERVEYDATALINK =  sslog_new_property("http://oss.fruct.org/smartcare#serveyDataLink", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASANOMALY
PROPERTY_HASANOMALY =  sslog_new_property("http://oss.fruct.org/smartcare#hasAnomaly", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_INTERVALSCALE
PROPERTY_INTERVALSCALE =  sslog_new_property("http://oss.fruct.org/smartcare#intervalScale", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ISPATIENTSMOKE
PROPERTY_ISPATIENTSMOKE =  sslog_new_property("http://oss.fruct.org/smartcare#isPatientSmoke", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASXAXIS
PROPERTY_HASXAXIS =  sslog_new_property("http://oss.fruct.org/smartcare#hasXAxis", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASPATIENTMETRICS
PROPERTY_HASPATIENTMETRICS =  sslog_new_property("http://oss.fruct.org/smartcare#hasPatientMetrics", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ENDWAVECOMP
PROPERTY_ENDWAVECOMP =  sslog_new_property("http://oss.fruct.org/smartcare#endWaveComp", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DOSAGE
PROPERTY_DOSAGE =  sslog_new_property("http://oss.fruct.org/smartcare#dosage", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SERVEYTYPE
PROPERTY_SERVEYTYPE =  sslog_new_property("http://oss.fruct.org/smartcare#serveyType", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DOCUMENTNUMBERFULL
PROPERTY_DOCUMENTNUMBERFULL =  sslog_new_property("http://oss.fruct.org/smartcare#documentNumberFull", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_PEAK
PROPERTY_PEAK =  sslog_new_property("http://oss.fruct.org/smartcare#peak", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_LONG
PROPERTY_LONG =  sslog_new_property("http://oss.fruct.org/smartcare#long", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ISPATIENTALCOHOLADDICTED
PROPERTY_ISPATIENTALCOHOLADDICTED =  sslog_new_property("http://oss.fruct.org/smartcare#isPatientAlcoholAddicted", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SERVEYDESCRIPTION
PROPERTY_SERVEYDESCRIPTION =  sslog_new_property("http://oss.fruct.org/smartcare#serveyDescription", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DOCUMENTTYPE
PROPERTY_DOCUMENTTYPE =  sslog_new_property("http://oss.fruct.org/smartcare#documentType", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASDIAGNOSIS
PROPERTY_HASDIAGNOSIS =  sslog_new_property("http://oss.fruct.org/smartcare#hasDiagnosis", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_LAT
PROPERTY_LAT =  sslog_new_property("http://oss.fruct.org/smartcare#lat", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SURNAME
PROPERTY_SURNAME =  sslog_new_property("http://oss.fruct.org/smartcare#surname", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DOCUMENTRELEASEDATE
PROPERTY_DOCUMENTRELEASEDATE =  sslog_new_property("http://oss.fruct.org/smartcare#documentReleaseDate", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_AUTHREQUESTSTATUS
PROPERTY_AUTHREQUESTSTATUS =  sslog_new_property("http://oss.fruct.org/smartcare#authRequestStatus", SSLOG_PROPERTY_TYPE_DATA);
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
#if INCLUDE_PROPERTY_ATRIALRATE
PROPERTY_ATRIALRATE =  sslog_new_property("http://oss.fruct.org/smartcare#atrialRate", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_WORKAMBULANCE
PROPERTY_WORKAMBULANCE =  sslog_new_property("http://oss.fruct.org/smartcare#workAmbulance", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_NAME
PROPERTY_NAME =  sslog_new_property("http://oss.fruct.org/smartcare#name", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ENDTIME
PROPERTY_ENDTIME =  sslog_new_property("http://oss.fruct.org/smartcare#endTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_ADVICETIME
PROPERTY_ADVICETIME =  sslog_new_property("http://oss.fruct.org/smartcare#adviceTime", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_HASWAVEFORMSTRUCTURE
PROPERTY_HASWAVEFORMSTRUCTURE =  sslog_new_property("http://oss.fruct.org/smartcare#hasWaveFormStructure", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASWAVECOMPONENT
PROPERTY_HASWAVECOMPONENT =  sslog_new_property("http://oss.fruct.org/smartcare#hasWaveComponent", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DISEASETYPE
PROPERTY_DISEASETYPE =  sslog_new_property("http://oss.fruct.org/smartcare#diseaseType", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SERVEYUSHINFO
PROPERTY_SERVEYUSHINFO =  sslog_new_property("http://oss.fruct.org/smartcare#serveyUshInfo", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_CONTAINDISEASES
PROPERTY_CONTAINDISEASES =  sslog_new_property("http://oss.fruct.org/smartcare#containDiseases", SSLOG_PROPERTY_TYPE_OBJECT);
#endif



#if INCLUDE_CLASS_THING
CLASS_THING = sslog_new_class("http://www.w3.org/2002/07/owl#Thing");
#endif
#if INCLUDE_CLASS_ALARM
CLASS_ALARM = sslog_new_class("http://oss.fruct.org/smartcare#Alarm");
#endif
#if INCLUDE_CLASS_DOCTOR
CLASS_DOCTOR = sslog_new_class("http://oss.fruct.org/smartcare#Doctor");
#endif
#if INCLUDE_CLASS_NURSE
CLASS_NURSE = sslog_new_class("http://oss.fruct.org/smartcare#Nurse");
#endif
#if INCLUDE_CLASS_ECGTWAVE
CLASS_ECGTWAVE = sslog_new_class("http://oss.fruct.org/smartcare#EcgTWave");
#endif
#if INCLUDE_CLASS_ECGDIAGNOSIS
CLASS_ECGDIAGNOSIS = sslog_new_class("http://oss.fruct.org/smartcare#ECGDiagnosis");
#endif
#if INCLUDE_CLASS_LOCATION
CLASS_LOCATION = sslog_new_class("http://oss.fruct.org/smartcare#Location");
#endif
#if INCLUDE_CLASS_ECGWAVECOMPONENT
CLASS_ECGWAVECOMPONENT = sslog_new_class("http://oss.fruct.org/smartcare#EcgWaveComponent");
#endif
#if INCLUDE_CLASS_ECGDATA
CLASS_ECGDATA = sslog_new_class("http://oss.fruct.org/smartcare#ECGData");
#endif
#if INCLUDE_CLASS_ADVICE
CLASS_ADVICE = sslog_new_class("http://oss.fruct.org/smartcare#Advice");
#endif
#if INCLUDE_CLASS_PATIENTMETRICS
CLASS_PATIENTMETRICS = sslog_new_class("http://oss.fruct.org/smartcare#PatientMetrics");
#endif
#if INCLUDE_CLASS_MEDICALRECORDSCARD
CLASS_MEDICALRECORDSCARD = sslog_new_class("http://oss.fruct.org/smartcare#MedicalRecordsCard");
#endif
#if INCLUDE_CLASS_PHARMACY
CLASS_PHARMACY = sslog_new_class("http://oss.fruct.org/smartcare#Pharmacy");
#endif
#if INCLUDE_CLASS_NOTHING
CLASS_NOTHING = sslog_new_class("http://www.w3.org/2002/07/owl#Nothing");
#endif
#if INCLUDE_CLASS_HOSPITAL
CLASS_HOSPITAL = sslog_new_class("http://oss.fruct.org/smartcare#Hospital");
#endif
#if INCLUDE_CLASS_MEASURMENT
CLASS_MEASURMENT = sslog_new_class("http://oss.fruct.org/smartcare#Measurment");
#endif
#if INCLUDE_CLASS_RHYTHM
CLASS_RHYTHM = sslog_new_class("http://oss.fruct.org/smartcare#Rhythm");
#endif
#if INCLUDE_CLASS_PROFILE
CLASS_PROFILE = sslog_new_class("http://oss.fruct.org/smartcare#Profile");
#endif
#if INCLUDE_CLASS_SERVEY
CLASS_SERVEY = sslog_new_class("http://oss.fruct.org/smartcare#Servey");
#endif
#if INCLUDE_CLASS_DISEASE
CLASS_DISEASE = sslog_new_class("http://oss.fruct.org/smartcare#Disease");
#endif
#if INCLUDE_CLASS_ECGSERVEY
CLASS_ECGSERVEY = sslog_new_class("http://oss.fruct.org/smartcare#ECGServey");
#endif
#if INCLUDE_CLASS_DOCUMENT
CLASS_DOCUMENT = sslog_new_class("http://oss.fruct.org/smartcare#Document");
#endif
#if INCLUDE_CLASS_BED
CLASS_BED = sslog_new_class("http://oss.fruct.org/smartcare#Bed");
#endif
#if INCLUDE_CLASS_ECGLEAD
CLASS_ECGLEAD = sslog_new_class("http://oss.fruct.org/smartcare#EcgLead");
#endif
#if INCLUDE_CLASS_ECGQRSCOMPLEX
CLASS_ECGQRSCOMPLEX = sslog_new_class("http://oss.fruct.org/smartcare#EcgQRSComplex");
#endif
#if INCLUDE_CLASS_PATIENTMAP
CLASS_PATIENTMAP = sslog_new_class("http://oss.fruct.org/smartcare#PatientMap");
#endif
#if INCLUDE_CLASS_MEDIC
CLASS_MEDIC = sslog_new_class("http://oss.fruct.org/smartcare#Medic");
#endif
#if INCLUDE_CLASS_ANOMALY
CLASS_ANOMALY = sslog_new_class("http://oss.fruct.org/smartcare#Anomaly");
#endif
#if INCLUDE_CLASS_USHSERVEY
CLASS_USHSERVEY = sslog_new_class("http://oss.fruct.org/smartcare#USHServey");
#endif
#if INCLUDE_CLASS_CARING
CLASS_CARING = sslog_new_class("http://oss.fruct.org/smartcare#Caring");
#endif
#if INCLUDE_CLASS_AMBULANCE
CLASS_AMBULANCE = sslog_new_class("http://oss.fruct.org/smartcare#Ambulance");
#endif
#if INCLUDE_CLASS_CRITERIA
CLASS_CRITERIA = sslog_new_class("http://oss.fruct.org/smartcare#Criteria");
#endif
#if INCLUDE_CLASS_WAVEFORMSTRUCTURE
CLASS_WAVEFORMSTRUCTURE = sslog_new_class("http://oss.fruct.org/smartcare#WaveFormStructure");
#endif
#if INCLUDE_CLASS_EQUIPMENT
CLASS_EQUIPMENT = sslog_new_class("http://oss.fruct.org/smartcare#Equipment");
#endif
#if INCLUDE_CLASS_DRUG
CLASS_DRUG = sslog_new_class("http://oss.fruct.org/smartcare#Drug");
#endif
#if INCLUDE_CLASS_HEARTRATE
CLASS_HEARTRATE = sslog_new_class("http://oss.fruct.org/smartcare#HeartRate");
#endif
#if INCLUDE_CLASS_ECGXAXIS
CLASS_ECGXAXIS = sslog_new_class("http://oss.fruct.org/smartcare#EcgXAxis");
#endif
#if INCLUDE_CLASS_ECGPWAVE
CLASS_ECGPWAVE = sslog_new_class("http://oss.fruct.org/smartcare#EcgPWave");
#endif
#if INCLUDE_CLASS_PERSON
CLASS_PERSON = sslog_new_class("http://oss.fruct.org/smartcare#Person");
#endif
#if INCLUDE_CLASS_PATIENT
CLASS_PATIENT = sslog_new_class("http://oss.fruct.org/smartcare#Patient");
#endif
#if INCLUDE_CLASS_ECGYAXIS
CLASS_ECGYAXIS = sslog_new_class("http://oss.fruct.org/smartcare#EcgYAxis");
#endif
#if INCLUDE_CLASS_AUTHREQUEST
CLASS_AUTHREQUEST = sslog_new_class("http://oss.fruct.org/smartcare#AuthRequest");
#endif



}


