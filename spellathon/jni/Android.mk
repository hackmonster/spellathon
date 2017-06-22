LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := spellcheck
LOCAL_SRC_FILES := driver.cpp \
                   trie.cpp


include $(BUILD_SHARED_LIBRARY)

