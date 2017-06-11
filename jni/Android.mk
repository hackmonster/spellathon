LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := spellcheck
LOCAL_SRC_FILES := $(LOCAL_PATH)/../driver.cpp

include $(BUILD_SHARED_LIBRARY)
