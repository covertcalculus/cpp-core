#pragma once

#if defined(_WIN32)
    #define CC_PLATFORM_OS "windows"
    #define CC_PLATFORM_OS_WINDOWS CC_PLATFORM_OS
    #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::windows
#elif defined(__APPLE__)
    #if defined(__MACH__)
        #define CC_PLATFORM_OS "apple::darwin"
        #define CC_PLATFORM_OS_APPLE_DARWIN CC_PLATFORM_OS
        #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::apple::darwin
    #else
        #define CC_PLATFORM_OS "apple"
        #define CC_PLATFORM_OS_APPLE_UNKNOWN CC_PLATFORM_OS
        #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::apple::unknown
    #endif
#elif defined(__linux__)
    #define CC_PLATFORM_OS "linux"
    #define CC_PLATFORM_OS_LINUX CC_PLATFORM_OS
    #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::linux
#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
    #define CC_PLATFORM_OS "bsd"
    #define CC_PLATFORM_OS_BSD CC_PLATFORM_OS
    #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::bsd
#else
    #define CC_PLATFORM_OS "[unknown]"
    #define CC_PLATFORM_OS_UNKNOWN CC_PLATFORM_OS
    #define CC_PLATFORM_OS_TYPE covertcalculus::platform::os::type::unknown
#endif