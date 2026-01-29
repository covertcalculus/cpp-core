#pragma once

#include "./CC_CPP_STANDARD.hpp"

#if CC_CPP_STANDARD >= 23
    #define CC_PLATFORM_CPP "C++23"
    #define CC_PLATFORM_CPP23 CC_PLATFORM_CPP
#elif CC_CPP_STANDARD >= 20
    #define CC_PLATFORM_CPP "C++20"
    #define CC_PLATFORM_CPP20 CC_PLATFORM_CPP
#elif CC_CPP_STANDARD >= 17
    #define CC_PLATFORM_CPP "C++17"
    #define CC_PLATFORM_CPP17 CC_PLATFORM_CPP
#elif CC_CPP_STANDARD >= 14
    #define CC_PLATFORM_CPP "C++14"
    #define CC_PLATFORM_CPP14 CC_PLATFORM_CPP
#elif CC_CPP_STANDARD >= 11
    #define CC_PLATFORM_CPP "C++11"
    #define CC_PLATFORM_CPP11 CC_PLATFORM_CPP
#else
    #define CC_PLATFORM_CPP "[pre C++11]"
    #define CC_PLATFORM_PRE_CPP17 CC_PLATFORM_CPP
#endif