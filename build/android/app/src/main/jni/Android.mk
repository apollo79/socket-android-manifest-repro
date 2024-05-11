LOCAL_PATH := $(call my-dir)

## libuv.a
include $(CLEAR_VARS)
LOCAL_MODULE := libuv

LOCAL_SRC_FILES = ../libs/$(TARGET_ARCH_ABI)/libuv.a
include $(PREBUILT_STATIC_LIBRARY)

## libsocket-runtime.a
include $(CLEAR_VARS)
LOCAL_MODULE := libsocket-runtime-static

LOCAL_SRC_FILES = ../libs/$(TARGET_ARCH_ABI)/libsocket-runtime.a
include $(PREBUILT_STATIC_LIBRARY)

## Injected extensions


## libsocket-runtime.so
include $(CLEAR_VARS)
LOCAL_MODULE := socket-runtime

LOCAL_CFLAGS +=              \
  -std=c++2a                 \
  -g                         \
  -I$(LOCAL_PATH)/include    \
  -I$(LOCAL_PATH)            \
  -pthreads                  \
  -fexceptions               \
  -fPIC                      \
  -frtti                     \
  -fsigned-char              \
  -O0

LOCAL_CFLAGS += -g -DDEBUG=1 -DANDROID=1 -DSSC_SETTINGS="" -DSSC_VERSION=0.5.4 -DSSC_VERSION_HASH=f90ba121  

LOCAL_LDLIBS := -landroid -llog
LOCAL_SRC_FILES =         \
  android/bridge.cc       \
  android/runtime.cc      \
  android/string_wrap.cc  \
  android/window.cc       \
  init.cc

LOCAL_STATIC_LIBRARIES := \
  libuv                   \
  libsocket-runtime-static

include $(BUILD_SHARED_LIBRARY)

## Custom userspace Android NDK