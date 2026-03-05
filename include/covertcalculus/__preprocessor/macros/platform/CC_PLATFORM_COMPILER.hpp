#pragma once

#include <covertcalculus/__preprocessor/require/cpp.hpp>

#if defined(__EMSCRIPTEN__)
    #define CC_PLATFORM_COMPILER_C_STR            "emscripten"
    #define CC_PLATFORM_COMPILER_SYMBOL_EMSCRIPTEN CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT            covertcalculus::platform::compiler::type::emscripten
#elif defined(_MSC_VER)
    #define CC_PLATFORM_COMPILER_C_STR       "msvc"
    #define CC_PLATFORM_COMPILER_SYMBOL_MSVC CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT      covertcalculus::platform::compiler::type::msvc
#elif defined(__clang__)
    #define CC_PLATFORM_COMPILER_C_STR        "clang"
    #define CC_PLATFORM_COMPILER_SYMBOL_CLANG CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT       covertcalculus::platform::compiler::type::clang
#elif defined(__MINGW64__)
    #define CC_PLATFORM_COMPILER_C_STR          "mingw64"
    #define CC_PLATFORM_COMPILER_SYMBOL_MINGW64 CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_SYMBOL_MINGW   CC_PLATFORM_COMPILER_SYMBOL_MINGW64
    #define CC_PLATFORM_COMPILER_RESULT         covertcalculus::platform::compiler::type::mingw64
#elif defined (__MINGW32__)
    #define CC_PLATFORM_COMPILER_C_STR          "mingw32"
    #define CC_PLATFORM_COMPILER_SYMBOL_MINGW32 CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_SYMBOL_MINGW   CC_PLATFORM_COMPILER_SYMBOL_MINGW32
    #define CC_PLATFORM_COMPILER_RESULT         covertcalculus::platform::compiler::type::mingw32
#elif defined(__GNUC__)
    #define CC_PLATFORM_COMPILER_C_STR      "gcc"
    #define CC_PLATFORM_COMPILER_SYMBOL_GCC CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT     covertcalculus::platform::compiler::type::gcc
#elif defined(__WATCOMC__)
    #define CC_PLATFORM_COMPILER_C_STR         "watcom"
    #define CC_PLATFORM_COMPILER_SYMBOL_WATCOM CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT        covertcalculus::platform::compiler::type::watcom
#else
    #define CC_PLATFORM_COMPILER_C_STR          "[unknown]"
    #define CC_PLATFORM_COMPILER_SYMBOL_UNKNOWN CC_PLATFORM_COMPILER_C_STR
    #define CC_PLATFORM_COMPILER_RESULT         covertcalculus::platform::compiler::type::unknown
#endif