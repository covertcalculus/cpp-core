#pragma once

#if defined (_WIN64) || defined(__x86_64__) || defined(__ppc64__) || defined(__aarch64__)
    #define CC_PLATFORM_ARCH_64
    #define CC_PLATFORM_ARCH 64
    #define CC_PLATFORM_ARCH_TYPE covertcalculus::platform::arch::type::bits64
#else
    #define CC_PLATFORM_ARCH_32
    #define CC_PLATFORM_ARCH 32
    #define CC_PLATFORM_ARCH_TYPE covertcalculus::platform::arch::type::bits32
#endif