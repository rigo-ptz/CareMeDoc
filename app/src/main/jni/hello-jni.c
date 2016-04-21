/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include "hello.h"
#include <android/log.h>
#include <stdlib.h>
#include <errno.h>

#define KP_SS_NAME "X"
//#define KP_SS_ADDRESS "194.85.173.9"  // Public PetrSU SIB
//#define KP_SS_ADDRESS "127.0.0.1"     // Local SIB
#define KP_SS_ADDRESS_CARE "78.46.130.194"
//#define KP_SS_ADDRESS_LOCAL "192.168.56.1"
#define KP_SS_PORT 10010

#define TAG "SS"

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
jstring
Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
    //return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI ");
    sslog_init();

    sslog_node_t *node = sslog_new_node("HelloWorldHigh_KP", KP_SS_NAME, KP_SS_ADDRESS_CARE, KP_SS_PORT);

    register_ontology(node);

    // In the smart space the name of the KP must be unique, if you try to
    // join without leave, then you received an error.
    if (sslog_node_join(node) != SSLOG_ERROR_NO) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"Can't join to SS");
        return 0;
    }

    printf("KP join to SS\n");

//    sslog_individual_t *universum = sslog_new_individual(CLASS_UNIVERSUM, "http://testclass.ru#universum1");
    sslog_individual_t *patient = sslog_new_individual(CLASS_PATIENT, "http://testclass.ru#patient");

    if (patient == NULL) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"Error");
        return 0;
    }

    sslog_subscription_t *subcription = sslog_new_subscription(node, false);

    list_t *properties = list_new();
    list_add_data(properties, PROPERTY_HAS);

    sslog_sbcr_add_individual(subcription, patient, properties);

    if (sslog_sbcr_subscribe(subcription) != 0) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"Can't subscribe");
        sslog_free_subscription(subcription);
        sslog_node_leave(node);
        return 0;
    }

    const char *p_val = (const char *) sslog_get_property(patient, PROPERTY_HAS);

    if (p_val != NULL) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"Now string is: %s", p_val);
    }

    sslog_sbcr_unsubscribe_all(node, true);

    sslog_node_leave(node);

    __android_log_print(ANDROID_LOG_INFO, TAG,"KP leave SS...");

    sslog_shutdown();

    return (*env)->NewStringUTF(env, p_val);
}
