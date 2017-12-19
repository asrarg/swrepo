/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdint.h>
#include <jni.h>
#include <jvmti.h>
#include <stdio.h>
#include <memory.h>
#include "Test.h"

static jvmtiEnv *jvmti = NULL;
static jvmtiCapabilities capa;
static jvmtiEventCallbacks callbacks;

void CheckError(jvmtiError error, const char *mesg)

{
	if (error != JVMTI_ERROR_NONE) {
		fprintf(stderr, "Error: %d / %s\n", error, mesg);
	}
}
/*
 void JNICALL MethodEntry(jvmtiEnv *jvmti, JNIEnv* jnienv, jthread thread, jmethodID method)

 {
 char *nameptr;
 jvmtiError error = (*jvmti)->GetMethodName(jvmti, method, &nameptr, NULL, NULL);
 CheckError(error, "Couldn't get method name\n");
 fprintf(stderr, "%d %s\n", thread, nameptr);
 (*jvmti)->Deallocate(jvmti, nameptr);
 }

 JNIEXPORT jint JNICALL
 Agent_OnLoad(JavaVM *vm, char *options, void *reserved)

 {
 jvmtiError error;

 error = (*vm)->GetEnv(vm, (void **)&jvmti, JVMTI_VERSION_1_2);
 CheckError(error, "Unable to retrieve jvmti ptr.");

 (void)memset(&capa, 0, sizeof(jvmtiCapabilities));
 capa.can_generate_method_entry_events = 1;
 error = (*jvmti)->AddCapabilities(jvmti, &capa);
 CheckError(error, "Unable to get necessary JVMTI capabilities.");

 error = (*jvmti)->SetEventNotificationMode
 (jvmti, JVMTI_ENABLE, JVMTI_EVENT_METHOD_ENTRY, (jthread)NULL);
 CheckError(error, "Cannot set event notification for method entry");

 error = (*jvmti)->SetEventNotificationMode
 (jvmti, JVMTI_ENABLE, JVMTI_EVENT_VM_INIT, (jthread)NULL);
 CheckError(error, "Cannot set event notification for vm init");

 (void)memset(&callbacks, 0, sizeof(jvmtiEventCallbacks));
 callbacks.MethodEntry = MethodEntry;
 error = (*jvmti)->SetEventCallbacks(jvmti, &callbacks, sizeof(jvmtiEventCallbacks));
 CheckError(error, "Cannot set event callbacks");
 fprintf(stderr, "Agent was loaded!\n");
 return JNI_OK;
 }
 */

JNIEXPORT jstring JNICALL Java_Test_callAG(JNIEnv *env, jclass clazz,
		jstring arg)

{
	/*jboolean copy;
	 const char *data = (*env)->GetStringUTFChars(env, arg, NULL);
	 fprintf(stderr, "The arg is: %s\n", data);
	 (*env)->ReleaseStringUTFChars(env, arg, data);*/

	//JavaVM *vm = (*env)->GetJavaVM();
	//jvmti->GetVersionNumber();
	/**const char *name = (*env)->GetStringUTFChars(env,arg, NULL);
	 char msg[60] = "Hello ";
	 jstring result;

	 strcat(msg, name);
	 (*env)->ReleaseStringUTFChars(env,arg, name);
	 puts(msg);
	 result = (*env)->NewStringUTF(env,msg);
	 return result;*/

	JavaVM *vm;
	(*env)->GetJavaVM(env, &vm);
	jvmtiError error;

	error = (*vm)->GetEnv(vm, (void **) &jvmti, JVMTI_VERSION_1_2);
	//CheckError(error, "Unable to retrieve jvmti ptr.");
	if (error != JVMTI_ERROR_NONE) {
		//return (*env)->NewStringUTF(env, "Unable to retrieve jvmti ptr.");
	}

	jvmtiError jvmtiErrorx;

	jint *result;
	jvmtiErrorx = (*jvmti)->GetAvailableProcessors(jvmti, result);
	if (jvmtiErrorx != JVMTI_ERROR_NONE) {
		//return (*env)->NewStringUTF(env, "Error getting available processors.");
	}

	jvmtiError error2;
	jthread aThread;
	error2 = (*jvmti)->GetCurrentThread(jvmti, &aThread);
	if (error2 != JVMTI_ERROR_NONE) {
		//return (*env)->NewStringUTF(env, "Could not fetch current thread.");
	}

	jvmtiFrameInfo frames[1];
	jint count;
	jvmtiError err;

	err = (*jvmti)->GetStackTrace(jvmti, aThread, 0, 1, frames, &count);
	if (err != JVMTI_ERROR_NONE) {
		//return (*env)->NewStringUTF(env, "getstacktrace.");
	}

	char *methodName;
	if (err == JVMTI_ERROR_NONE && count >= 1) {
		err = (*jvmti)->GetMethodName(jvmti, frames[0].method, &methodName,
		NULL, NULL);
		if (err != JVMTI_ERROR_NONE) {
			//printf("Executing method: %s", methodName);
			//return (*env)->NewStringUTF(env, "Error GetMethodName");
		}
	}

	//Agent_OnLoad(vm, NULL, NULL);

	//return (*env)->NewStringUTF(env, "Hello from native.1111222xxx");
	//return jvmtiErrorx;
	return (*env)->NewStringUTF(env, methodName);
}

