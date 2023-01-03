LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder

LOCAL_SRC_FILES := ../example_binder_interface/ExampleBinderInterface.cpp 
LOCAL_SRC_FILES += ExampleBinderBody.cpp ExampleBinderServer.cpp

LOCAL_C_INCLUDES += frameworks/native/include \
		    system/core/include

LOCAL_LDLIBS := -llog					
LOCAL_MODULE := example_binder_server

include $(BUILD_EXECUTABLE)



