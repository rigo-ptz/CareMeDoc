/**
 * Actions with SIB for getting patient list
 *
 * @author Yamushev Igor
 * @since 23.04.2016
 */

#include <string.h>
#include <jni.h>
#include "smartcare.h"
#include "patients-jni.h"
#include <android/log.h>
#include <stdlib.h>
#include <errno.h>

#define KP_SS_NAME "X"
//#define KP_SS_ADDRESS "194.85.173.9"  // Public PetrSU SIB
//#define KP_SS_ADDRESS "127.0.0.1"
#define KP_SS_ADDRESS "78.46.130.194" // Local SIB
#define KP_SS_PORT 10010



jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_6) != JNI_OK)
        return -1;

    jclass *patientClassObj = getJClass(env, "Patient");
    patientClass = (jclass *)(*env)->NewGlobalRef(env, patientClassObj);

    jclass apiClassObj = (*env) -> FindClass(env, "com/jollypanda/caremedoc/api/interaction/PatientsListApi");
    apiClass = (jclass *)(*env)->NewGlobalRef(env, apiClassObj);

    JVM = vm;
    return JNI_VERSION_1_6;
}

JNIEXPORT jint JNICALL Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_connectSmartSpace(JNIEnv * env, jobject thiz, jstring hostname, jstring ip, jint port) {
    const char *hostname_ = (*env) -> GetStringUTFChars(env, hostname, NULL);
    const char *ip_ = (*env) -> GetStringUTFChars(env, ip, NULL);
    sslog_node_t *node;
    sslog_init();

    __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "sslog_init");

    node = sslog_new_node("HelloWorldHigh_KP", hostname_, ip_, (int)port);

    register_ontology();

    __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "register_ontology");

    if (sslog_node_join(node) != SSLOG_ERROR_NO) {
        __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "Can't join to SS");
        return -1;
    } else{
        __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "KP joins to SS.");
        __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "The value is %lu", (unsigned long*)node);
        __android_log_print(ANDROID_LOG_INFO, TAG_CONNECT, "The value is %p", node);
        return (jlong) node;
    }

    //if((*env)->GetJavaVM(env, &JVM) != 0)
    //    __android_log_print(ANDROID_LOG_ERROR, TAG_CONNECT, "Get java VM failed");
}

void Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_disconnectSmartSpace(JNIEnv* env, jobject thiz ) {
    __android_log_print(ANDROID_LOG_INFO, TAG_DISCONNECT,"KP leaves SS");

    sslog_sbcr_unsubscribe_all(NODE, true);
    sslog_node_leave(NODE);
    sslog_shutdown();
}

void Java_com_jollypanda_caremedoc_api_interaction_PatientsListApi_subscribeForPatients(JNIEnv * env, jobject thiz, jlong nodeDescriptor) {

    extern void patientSubscriptionHandler(sslog_subscription_t *);
    void (*pPatientHandler)(sslog_subscription_t *) = &patientSubscriptionHandler;

    sslog_node_t *node = (sslog_node_t *) nodeDescriptor;
    NODE = node;

    // In the smart space the name of the KP must be unique, if you try to
    // join without leave, then you received an error.
    if (sslog_node_join(node) != SSLOG_ERROR_NO) {
        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Can't join to SS: %s\n", sslog_error_get_last_text());
        return 0;
    }

    __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "KP join to SS\n");

    // Used for the first time getting all patients from Smart Space
    list_t *patientList = sslog_node_get_individuals_by_class(node, CLASS_PATIENT);

    if (patientList != NULL) {
        list_head_t* list_walker = NULL;

        list_for_each(list_walker, &patientList -> links) {
            list_t *list_node = list_entry(list_walker, list_t, links);
            sslog_individual_t *ind = (sslog_individual_t *) list_node -> data;

            __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Indiviual URI: %s\n", sslog_entity_get_uri(ind));

            const char *name = (const char *) sslog_node_get_property(node, ind, PROPERTY_NAME);
            const char *surname = (const char *) sslog_node_get_property(node, ind, PROPERTY_SURNAME);

            __android_log_print(ANDROID_LOG_ERROR, TAG_SUBSCRIBE, "Name: %s, Surname: %s\n", name, surname);

            if (name != NULL && surname != NULL)
                returnPatientToJava(env, name, surname);
        }
    }

    // Create a new subscription and add class to it.
    sslog_subscription_t *subscription = sslog_new_subscription(node, true); // false

    sslog_sbcr_add_class(subscription, CLASS_PATIENT);
    sslog_sbcr_set_changed_handler(subscription, pPatientHandler);

    // Try to subscribe, after this we will subscribe to class
    // and will get notifications about inserting or removing
    // individuals of the subscribed class in the smart space.
    if (sslog_sbcr_subscribe(subscription) != SSLOG_ERROR_NO) {
        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Can't subscribe.\n");
        sslog_shutdown();
        return 0;
    }
    __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Subscribtion successfull\n");

    // Checking information about subscription.
//    process_subscription(node, subscription);
    __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Subscribtion processing ends\n");

    // This function is used to show how to usubscribe all subscription for node.
    // In this demo it is not so useful and sslog_free_subscription can be used.
    //sslog_sbcr_unsubscribe_all(node, true);

    // __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Before node leave\n");

    //sslog_node_leave(node);

     //__android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Before shutdown \n");

    return 0;
}

void process_subscription(sslog_node_t *node, sslog_subscription_t *subscription) {

    __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "INSIDE Subscribtion \n");
    if (subscription == NULL) {
        return;
    }

    while (sslog_sbcr_is_active(subscription) == true) {
        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Wait \n");
        sslog_sbcr_wait(subscription);
        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "After wiat \n");
        sslog_sbcr_changes_t *changes = sslog_sbcr_get_changes_last(subscription);
        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Get changes \n");

        sslog_sbcr_ch_print(changes);
        const list_t *patients = sslog_sbcr_ch_get_individual_all(changes);

        const list_t *inserted_ind = sslog_sbcr_ch_get_individual_by_action(changes, SSLOG_ACTION_INSERT);

        __android_log_print(ANDROID_LOG_INFO, TAG_SUBSCRIBE, "Inserted individuals \n");
        printf("\n---- Inserted individuals:\n");
        print_patients(node, inserted_ind);
    }

}

void print_patients(sslog_node_t *node, const list_t *persons) {

    __android_log_print(ANDROID_LOG_INFO, TAG_PRINT, "\n Start printing patients \n");

    if (persons == NULL) {
        return;
    }

    list_head_t *list_walker = NULL;

    list_for_each(list_walker, &persons->links) {
        list_t *list_node = list_entry(list_walker, list_t, links);
        char *uri = (char *) list_node->data;

        // After subscription new individuals will be created, and here
        // get individual from the repository.
        sslog_individual_t *ind = sslog_get_individual(uri);

        if (ind == NULL) {
            __android_log_print(ANDROID_LOG_INFO, TAG_PRINT, "No individual in the local store.\n");
            continue;
        }

        __android_log_print(ANDROID_LOG_INFO, TAG_PRINT, "Indiviual URI: %s\n", sslog_entity_get_uri(ind));

        const char *name = (const char *) sslog_node_get_property(node, ind, PROPERTY_NAME);
        const char *surname = (const char *) sslog_node_get_property(node, ind, PROPERTY_SURNAME);

        __android_log_print(ANDROID_LOG_INFO, TAG_PRINT, "Name: %s, Surname: %s\n", name, surname);
    }

}

/**
 * @brief Handles patient subscription
 *
 * @param subscription - subscription from Smart Space
 */
void patientSubscriptionHandler(sslog_subscription_t *subscription) {
    JNIEnv *env = NULL;
    bool attached = JNI_FALSE;

    if (*JVM == NULL)
        __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n JVMlocal NULL \n");
    __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n before JVM \n");
    /* Initialize `env` pointer in current thread */
    switch((*JVM)->GetEnv(JVM, (void **)&env, JNI_VERSION_1_6)) {
        case JNI_OK:
            break;
        case JNI_EDETACHED:
            __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n before attach \n");
            (*JVM)->AttachCurrentThread(JVM, &env, NULL);
            attached = JNI_TRUE;
            break;
        case JNI_EVERSION:
            __android_log_print(ANDROID_LOG_ERROR, TAG_HANDLER, "invalid JNI version");
            break;
    }

    __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n after JVM \n");

    if(!sslog_sbcr_is_active(subscription)) {
        __android_log_print(ANDROID_LOG_ERROR, TAG_HANDLER, "Subscription is not active");
        return 0;
    }

    __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n before get changes \n");
    sslog_sbcr_changes_t *changes = sslog_sbcr_get_changes_last(subscription);
    list_t *list = sslog_sbcr_ch_get_individual_by_action(changes, SSLOG_ACTION_INSERT);

    __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n after get changes \n");

    if(list != NULL) {
        list_head_t *list_walker = NULL;

        __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "\n inside changes list \n");

        list_for_each(list_walker, &list->links) {
            list_t *list_node = list_entry(list_walker, list_t, links);
            char *uri = (char *) list_node->data;
            sslog_individual_t *ind = sslog_get_individual(uri);

            if (ind == NULL) {
                __android_log_print(ANDROID_LOG_ERROR, TAG_HANDLER, "No individual in the local store.\n");
                continue;
            }

            __android_log_print(ANDROID_LOG_INFO, TAG_HANDLER, "Indiviual URI: %s\n", sslog_entity_get_uri(ind));

            const char *name = (const char *) sslog_node_get_property(NODE, ind, PROPERTY_NAME);
            const char *surname = (const char *) sslog_node_get_property(NODE, ind, PROPERTY_SURNAME);

            __android_log_print(ANDROID_LOG_ERROR, TAG_HANDLER, "Name: %s, Surname: %s\n", name, surname);

            if (name != NULL && surname != NULL)
                returnPatientToJava(env, name, surname);

            break;
        }
    }

     //sslog_free_triples(list);

    if(attached)
        (*JVM)->DetachCurrentThread(JVM);
}

/**
 * @brief Used for returning Patient object to Java
 *
 * @param subscription - subscription from Smart Space
 */
void returnPatientToJava(JNIEnv *env, char *name, char *surname) {
    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Start return to java\n");

    //jclass *patientClass = getJClass(env, "Patient");
    jmethodID patientConstructor = (*env) -> GetMethodID(env, patientClass, "<init>", "()V");
    if (patientConstructor == NULL)
        return 0;
    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Create Patient object\n");

    jobject patient = (*env) -> NewObject(env, patientClass, patientConstructor);
    jmethodID setName = (*env) -> GetMethodID(env, patientClass, "setName", "(Ljava/lang/String;)V");
    jmethodID setSurname = (*env) -> GetMethodID(env, patientClass, "setSurname", "(Ljava/lang/String;)V");

    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Set name and surname\n");
    (*env) -> CallVoidMethod(env, patient, setName, (*env) -> NewStringUTF(env, name));
    (*env) -> CallVoidMethod(env, patient, setSurname, (*env) -> NewStringUTF(env, surname));

    //jclass apiClass = (*env) -> FindClass(env, "com/jollypanda/caremedoc/api/interaction/PatientsListApi");
    if (apiClass == NULL)
        return 0;
    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "getInstance\n");
    jmethodID getInstance = (*env) -> GetStaticMethodID(env, apiClass, "getInstance", "()Lcom/jollypanda/caremedoc/api/interaction/PatientsListApi;");
    jobject patientsListApi = (*env) -> CallStaticObjectMethod(env, apiClass, getInstance);
    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "handle patient\n");
    jmethodID handlePatientFromNative = (*env) -> GetMethodID(env, apiClass, "handlePatientFromNative", "(Lcom/jollypanda/caremedoc/api/model/Patient;)V");

    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Call handler in Java\n");
    (*env) -> CallVoidMethod(env, patientsListApi, handlePatientFromNative, patient);
}

/**
 * @brief Method for getting jclass object
 *
 * @param className - name of class
 * @return JClass in success and NULL otherwise
 */
jclass getJClass(JNIEnv *env, char *className) {

    char *classPath = (char *) malloc (sizeof(char) * strlen("com/jollypanda/caremedoc/api/model/") + strlen(className));

    strcpy(classPath, "com/jollypanda/caremedoc/api/model/");
    strcat(classPath, className);

    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Class path: %s\n", classPath);

    jclass javaClass = (*env) -> FindClass(env, classPath);

    __android_log_print(ANDROID_LOG_ERROR, TAG_RETURN, "Class found: %s\n", classPath);

    if(javaClass == NULL) {
        char *error = (char *) malloc (sizeof(char) * 30);
        strcpy(error, "Can't find ");
        strcat(error, className);
        strcat(error, " class");

        return NULL;
    }

    free(classPath);

    return javaClass;
}

