//
// Created by Игорь on 30.04.2016.
//

#ifndef DOCTOR_KP_PATIENTS_JNI_H
#define DOCTOR_KP_PATIENTS_JNI_H

#define TAG_CONNECT "SS_CONNECT"
#define TAG_DISCONNECT "SS_DISCONNECT"
#define TAG_SUBSCRIBE "SS_SUBSCRIBE"
#define TAG_PRINT "SS_PRINT"
#define TAG_HANDLER "SS_HANDLER"
#define TAG_RETURN "SS_RETURN_TO_JAVA"

static sslog_node_t *NODE;
JavaVM *JVM = NULL;

jclass *patientClass;
jclass *apiClass;

jclass getJClass(JNIEnv *, char *);

#endif //DOCTOR_KP_PATIENTS_JNI_H
