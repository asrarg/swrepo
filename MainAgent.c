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

void setAllCapabilities (jvmtiEnv* env, int capability) {

	jvmtiCapabilities *arg;
	(void)memset(arg, 0,sizeof(jvmtiCapabilities));
	switch(capability){
	case 1:
		fprintf(stderr, "can_tag_objects = 1"); //change this to standard printing
		arg->can_tag_objects = 1;
	break;
	case 2:
		fprintf(stderr, "can_generate_field_modification_events = 1");
	arg->can_generate_field_modification_events = 1;
	break;
	case 3:
		fprintf(stderr, "can_generate_field_access_events = 1");
	arg->can_generate_field_access_events = 1;
	break;
	case 4:
		fprintf(stderr, "can_get_bytecodes = 1");
	arg->can_get_bytecodes = 1;
	break;
	case 5:
		fprintf(stderr, "can_get_synthetic_attribute = 1");
	arg->can_get_synthetic_attribute = 1;
	break;
	case 6:
		fprintf(stderr, "can_get_owned_monitor_info = 1");
	arg->can_get_owned_monitor_info = 1;
	break;
	case 7:
		fprintf(stderr, "can_get_current_contended_monitor = 1");
	arg->can_get_current_contended_monitor = 1;
	break;
	case 8:
		fprintf(stderr, "can_get_monitor_info = 1");
	arg->can_get_monitor_info = 1;
	break;
	case 9:
		fprintf(stderr, "can_pop_frame = 1");
	arg->can_pop_frame = 1;
	break;
	case 10:
		fprintf(stderr, "can_redefine_classes = 1");
	arg->can_redefine_classes = 1;
	break;
	case 11:
		fprintf(stderr,"can_signal_thread = 1");
	arg->can_signal_thread = 1;
	break;
	case 12:
		fprintf(stderr,"can_get_source_file_name = 1");
	arg->can_get_source_file_name = 1;
	break;
	case 13:
		fprintf(stderr,"can_get_line_numbers = 1");
	arg->can_get_line_numbers = 1;
	break;
	case 14:
		fprintf(stderr,"can_get_source_debug_extension = 1");
	arg->can_get_source_debug_extension = 1;
	break;
	case 15:
		fprintf(stderr,"can_access_local_variables = 1");
	arg->can_access_local_variables = 1;
	break;
	case 16:
		fprintf(stderr,"can_maintain_original_method_order = 1");
	arg->can_maintain_original_method_order = 1;
	break;
	case 17:
		fprintf(stderr,"can_generate_single_step_events = 1");
	arg->can_generate_single_step_events = 1;
	break;
	case 18:
		fprintf(stderr,"can_generate_exception_events = 1");
	arg->can_generate_exception_events = 1;
	break;
	case 19:
		fprintf(stderr,"can_generate_frame_pop_events = 1");
	arg->can_generate_frame_pop_events = 1;
	break;
	case 20:
		fprintf(stderr,"can_generate_breakpoint_events = 1");
	arg->can_generate_breakpoint_events = 1;
	break;
	case 21:
		fprintf(stderr,"can_suspend = 1");
	arg->can_suspend = 1;
	break;
	case 22:
		fprintf(stderr,"can_redefine_any_class = 1");
	arg->can_redefine_any_class = 1;
	break;
	case 23:
		fprintf(stderr,"can_get_current_thread_cpu_time = 1");
	arg->can_get_current_thread_cpu_time = 1;
	break;
	case 24:
		fprintf(stderr,"can_get_thread_cpu_time = 1");
	arg->can_get_thread_cpu_time = 1;
	break;
	case 25:
		fprintf(stderr,"can_generate_method_entry_events = 1");
	arg->can_generate_method_entry_events = 1;
	break;
	case 26:
		fprintf(stderr,"can_generate_method_exit_events = 1");
	arg->can_generate_method_exit_events = 1;
	break;
	case 27:
		fprintf(stderr,"can_generate_all_class_hook_events = 1");
	arg->can_generate_all_class_hook_events = 1;
	break;
	case 28:
		fprintf(stderr,"can_generate_compiled_method_load_events = 1");
	arg->can_generate_compiled_method_load_events = 1;
	break;
	case 29:
		fprintf(stderr,"can_generate_monitor_events = 1");
	arg->can_generate_monitor_events = 1;
	break;
	case 30:
		fprintf(stderr,"can_generate_vm_object_alloc_events = 1");
	arg->can_generate_vm_object_alloc_events = 1;
	break;
	case 31:
		fprintf(stderr,"can_generate_native_method_bind_events = 1");
	arg->can_generate_native_method_bind_events = 1;
	break;
	case 32:
		fprintf(stderr,"can_generate_garbage_collection_events = 1");
	arg->can_generate_garbage_collection_events = 1;
	break;
	case 33:
		fprintf(stderr,"can_generate_object_free_events = 1");
	arg->can_generate_object_free_events = 1;
	break;
	case 34:
		fprintf(stderr,"can_force_early_return = 1");
	arg->can_force_early_return = 1;
	break;
	case 35:
		fprintf(stderr,"can_get_owned_monitor_stack_depth_info = 1");
	arg->can_get_owned_monitor_stack_depth_info = 1;
	break;
	case 36:
		fprintf(stderr,"can_get_constant_pool = 1");
	arg->can_get_constant_pool = 1;
	break;
	case 37:
		fprintf(stderr,"can_set_native_method_prefix = 1");
	arg->can_set_native_method_prefix = 1;
	break;
	case 38:
		fprintf(stderr,"can_retransform_classes = 1");
	arg->can_retransform_classes = 1;
	break;
	case 39:
		fprintf(stderr,"can_retransform_any_class = 1");
	arg->can_retransform_any_class = 1;
	break;
	case 40:
		fprintf(stderr,"can_generate_resource_exhaustion_heap_events = 1");
	arg->can_generate_resource_exhaustion_heap_events = 1;
	break;
	case 41:
		fprintf(stderr,"can_generate_resource_exhaustion_threads_events = 1");
	arg->can_generate_resource_exhaustion_threads_events = 1;
	break;
	default:
		printf("Error switch cap\n" );
		//err = (*jvmti)->GetPotentialCapabilities(jvmti, &capa);
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
	
JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *vm, char *options, void *reserved) {
	fprintf(stdout, "Agent was loaded!\n");

	for(int i=1; i<42; i++)
	{
		setAllCapabilities(jvmti,i);
		fprintf(stdout, "Agent IS HERE!\n");

	}



 	return JNI_OK;
}
	
JNIEXPORT jstring JNICALL Java_Test_callAG(JNIEnv *env, jclass clazz,
		jstring arg)
	
{

	JavaVM *vm;
	//jvmtiError jvmtiErrorx;
	jint *result;
	jvmtiError error;
	//jvmtiError error2;
	jthread aThread;
	jvmtiFrameInfo frames[1];
	jint count;
	//jvmtiError err;
	//jvmtiError error3;
	jstring resultx;

	(*env)->GetJavaVM(env, &vm);



	error = (*vm)->GetEnv(vm, (void **) &jvmti, JVMTI_VERSION_1_2);
	if (error != JVMTI_ERROR_NONE) {
		return (*env)->NewStringUTF(env, "Unable to retrieve jvmti ptr.");
	}

 	error = (*vm)->GetEnv(vm, (void **)&jvmti, JVMTI_VERSION_1_2);
 	CheckError(error, "Unable to retrieve jvmti ptr.");
//

 	error = (*jvmti)->GetAvailableProcessors(jvmti, result);
	if (error != JVMTI_ERROR_NONE) {
		return (*env)->NewStringUTF(env, "Error getting available processors.");
	}
//
 	(void)memset(&capa, 0, sizeof(jvmtiCapabilities));
 	capa.can_generate_method_entry_events = 1;
 	error = (*jvmti)->AddCapabilities(jvmti, &capa);
 	CheckError(error, "Unable to get necessary JVMTI capabilities.");
fprintf(stderr, "0\n");

	error = (*jvmti)->GetCurrentThread(jvmti, &aThread);
	if (error != JVMTI_ERROR_NONE) {
		return (*env)->NewStringUTF(env, "Could not fetch current thread.");
	}
//
fprintf(stderr, "1\n");


	error = (*jvmti)->GetStackTrace(jvmti, aThread, 0, 1, frames, &count);
	if (error != JVMTI_ERROR_NONE) {
		fprintf(stderr, "inside Get Stacktrace\n");
		return (*env)->NewStringUTF(env, "getstacktrace.");
	}
//****************************GETTING STACK TRACES*****************************************************

/*
	jvmtiStackInfo *stack_info;
	int MAX_FRAMES = 5;
	jint thread_count;
	int ti;
	jvmtiError errxx;

	errxx = (*jvmti)->GetAllStackTraces(jvmti, MAX_FRAMES, &stack_info, &thread_count);
	(*jvmti)->getallst
	if (errxx != JVMTI_ERROR_NONE) {
		return (*env)->NewStringUTF(env, "Could not GET ALL STACK TRACES.");
	}
	for (ti = 0; ti < thread_count; ++ti) {
	   jvmtiStackInfo *infop = &stack_info[ti];
	   jthread thread = infop->thread;
	   jint state = infop->state;
	   jvmtiFrameInfo *framez = infop->frame_buffer;
	   int fi;

	   fprintf(stderr, thread);
	   fprintf(stderr, "\n");
	   fprintf(stderr, state);
	   for (fi = 0; fi < infop->frame_count; fi++) {
	      fprintf(stderr, framez[fi].method);
	      fprintf(stderr, "\n"  );
	      fprintf(stderr, framez[fi].location);
	   }
	}
	//Deallocating call
	errxx = (*jvmti)->Deallocate(jvmti, stack_info);
*/

//*********************************************************************************

fprintf(stderr, "count: %d\n", count);


//
	if (count >= 1) {
		char *nameptr;
		error = (*jvmti)->GetMethodName(jvmti, frames[0].method, &nameptr, NULL, NULL);
		if (error != JVMTI_ERROR_NONE) {
			fprintf(stderr, "inside Get MethodName\n");
			return (*env)->NewStringUTF(env, "Error GetMethodName");
		}
		//return (*env)->NewStringUTF(env, nameptr);
		 resultx = (*env)->NewStringUTF(env, nameptr);
		(*jvmti)->Deallocate(jvmti, nameptr);
		return resultx;
	}

	return (*env)->NewStringUTF(env, "MethodEnd");
}

