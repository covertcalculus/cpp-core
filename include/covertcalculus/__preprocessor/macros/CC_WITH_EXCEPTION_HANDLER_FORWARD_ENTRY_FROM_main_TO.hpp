#pragma once

#include <covertcalculus/memory/span.hpp>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <vector>
#include <cstddef>
#include <type_traits>
#include <covertcalculus/__preprocessor/macros/nameof.hpp>

#define CC_WITH_EXCEPTION_HANDLER_FORWARD_ENTRY_FROM_main_TO(entryFunctionName, ...)\
    int entryFunctionName(covertcalculus::memory::span<char *> args);\
    int main(int argc, char **argv) { \
        auto handler = (__VA_ARGS__); \
        \
        using type_of_handler_function_call = decltype( \
            std::declval<decltype(handler)>() (  std::declval<const std::exception &>()  ) \
        ); \
        \
        static_assert( \
            std::is_convertible_v<type_of_handler_function_call, int>, \
            "\n\n" \
            "Error calling macro " \
            nameof(CC_WITH_EXCEPTION_HANDLER_FORWARD_ENTRY_FROM_main_TO) \
            "(entryFunctionName, ...)" \
            ":\n" \
            "   Exception handler must be callable with (const std::exception &) and return int.\n" \
            "\n" \
        ); \
        \
        namespace mem = covertcalculus::memory; \
        \
        try { \
            return entryFunctionName(mem::span{argv, static_cast<std::size_t>(argc)}); \
        } catch (const std::exception &e) { \
            return handler(e); \
        } \
    }
