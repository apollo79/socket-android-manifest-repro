#ifndef SOCKET_RUNTIME_PLATFORM_H
#define SOCKET_RUNTIME_PLATFORM_H

// when this header is included, this is always `0`
#define SOCKET_RUNTIME_PLATFORM_WASM 0

#if defined(__x86_64__) || defined(_M_X64)
#  define SOCKET_RUNTIME_ARCH_x64 1
#  define SOCKET_RUNTIME_ARCH_ARM64 0
#  define SOCKET_RUNTIME_ARCH_UNKNOWN 0
#elif defined(__aarch64__) || defined(_M_ARM64)
#  define SOCKET_RUNTIME_ARCH_x64 0
#  define SOCKET_RUNTIME_ARCH_ARM64 1
#  define SOCKET_RUNTIME_ARCH_UNKNOWN 0
#elif defined(__i386__) && !defined(__ANDROID__)
#error Socket is not supported on i386.
#else
#  define SOCKET_RUNTIME_ARCH_x64 0
#  define SOCKET_RUNTIME_ARCH_ARM64 0
#  define SOCKET_RUNTIME_ARCH_UNKNOWN 1
#endif

#if defined(_WIN32)
# define SOCKET_RUNTIME_PLATFORM_NAME "win32"
# define SOCKET_RUNTIME_PLATFORM_OS "win32"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 0
# define SOCKET_RUNTIME_PLATFORM_IOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_LINUX 0
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
# define SOCKET_RUNTIME_PLATFORM_WINDOWS 1
#elif defined(__APPLE__)
# include <TargetConditionals.h>
# define SOCKET_RUNTIME_PLATFORM_NAME "darwin"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_LINUX 0
# define SOCKET_RUNTIME_PLATFORM_WINDOWS 0

#if TARGET_OS_IPHONE
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS 1
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_OS "ios"
#elif TARGET_IPHONE_SIMULATOR
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS 1
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 1
# define SOCKET_RUNTIME_PLATFORM_OS "ios"
#else
# define SOCKET_RUNTIME_PLATFORM_MACOS 1
# define SOCKET_RUNTIME_PLATFORM_IOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_OS "mac"
#endif

#if defined(__unix__) || defined(unix) || defined(__unix)
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
#else
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
#endif

#elif defined(__linux__)
# undef linux
# define SOCKET_RUNTIME_PLATFORM_NAME "linux"
# define SOCKET_RUNTIME_PLATFORM_IOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_LINUX 1
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_WINDOWS 0

#ifdef __ANDROID__
# define SOCKET_RUNTIME_PLATFORM_OS "android"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 1
#else
# define SOCKET_RUNTIME_PLATFORM_OS "linux"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 0
#endif

#if defined(__unix__) || defined(unix) || defined(__unix)
# define SOCKET_RUNTIME_PLATFORM_UXIX 1
#else
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
#endif

#elif defined(__FreeBSD__)
# define SOCKET_RUNTIME_PLATFORM_NAME "freebsd"
# define SOCKET_RUNTIME_PLATFORM_OS "freebsd"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 0
# define SOCKET_RUNTIME_PLATFORM_IOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_LINUX 0
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_WINDOWS 0

#if defined(__unix__) || defined(unix) || defined(__unix)
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
#else
# define SOCKET_RUNTIME_PLATFORM_UXIX 1
#endif

#elif defined(BSD)
# define SOCKET_RUNTIME_PLATFORM_NAME "openbsd"
# define SOCKET_RUNTIME_PLATFORM_OS "openbsd"
# define SOCKET_RUNTIME_PLATFORM_ANDROID 0
# define SOCKET_RUNTIME_PLATFORM_IOS 0
# define SOCKET_RUNTIME_PLATFORM_IOS_SIMULATOR 0
# define SOCKET_RUNTIME_PLATFORM_LINUX 0
# define SOCKET_RUNTIME_PLATFORM_MACOS 0
# define SOCKET_RUNTIME_PLATFORM_WINDOWS 0

#if defined(__unix__) || defined(unix) || defined(__unix)
# define SOCKET_RUNTIME_PLATFORM_UXIX 0
#else
# define SOCKET_RUNTIME_PLATFORM_UXIX 1
#endif
#endif

#endif
