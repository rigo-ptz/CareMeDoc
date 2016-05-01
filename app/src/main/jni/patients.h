/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jollypanda_caremedoc_api_interaction_PatientsListApi */

#ifndef _Included_com_jollypanda_caremedoc_api_interaction_PatientsListApi
#define _Included_com_jollypanda_caremedoc_api_interaction_PatientsListApi
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jollypanda_caremedoc_api_interaction_PatientsListApi
 * Method:    connectSmartSpace
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_connectSmartSpace
  (JNIEnv *, jobject, jstring, jstring, jint);

/*
 * Class:     com_jollypanda_caremedoc_api_interaction_PatientsListApi
 * Method:    disconnectSmartSpace
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_disconnectSmartSpace
  (JNIEnv *, jobject);

/*
 * Class:     com_jollypanda_caremedoc_api_interaction_PatientsListApi
 * Method:    subscribeForPatients
 * Signature: (J)Lcom/jollypanda/caremedoc/api/model/Patient;
 */
JNIEXPORT jobject JNICALL Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_subscribeForPatients
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
