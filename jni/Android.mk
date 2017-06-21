LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../inc
LOCAL_MODULE    := spellChecker
LOCAL_SRC_FILES += $(LOCAL_PATH)/../src/trieDS_spellathon.cpp \
                   $(LOCAL_PATH)/../src/driver.cpp
                    
LOCAL_LDLIBS := -fPIC
include $(BUILD_EXECUTABLE)
