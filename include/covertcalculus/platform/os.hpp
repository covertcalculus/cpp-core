#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/__preprocessor/macros/platform/CC_PLATFORM_OS.hpp>
#include <covertcalculus/platform/__/namespace.hpp>

#include <string_view>
#include <string>

namespace covertcalculus::platform {
    class os final {
    public:
        os() = delete;

        using This = os;

        enum class result : int {
            unknown = 0,
            windows, linux, bsd,
            apple_unknown,
            apple_darwin,
        };

        class type final {
        public:
            type() = delete;
            static constexpr auto unknown = result::unknown;
            static constexpr auto windows = result::windows;
            static constexpr auto linux   = result::linux;
            static constexpr auto bsd     = result::bsd;

            class apple final {
            public:
                apple() = delete;
                static constexpr auto unknown = result::apple_unknown;
                static constexpr auto darwin  = result::apple_darwin;
                static constexpr auto _ = darwin;
            };
        };

        static constexpr auto f() { return get(); }

        static constexpr bool is_unix()    { return is_apple() || is_linux() || is_bsd(); }

        static constexpr bool is_windows() { return get() == type::windows; }
        static constexpr bool is_linux()   { return get() == type::linux;   }
        static constexpr bool is_bsd()     { return get() == type::bsd;     }
        static constexpr bool is_unknown() { return get() == type::unknown; }

        static constexpr bool is_apple() {
            switch (get()) {
                case type::apple::unknown:
                case type::apple::darwin:
                    return true;
                default:
                    return false;
            }
        }

        static constexpr std::string_view string_view() { return {c_str()}; }
        static           std::string           string() { return {c_str()}; }

        static constexpr const char *c_str() {
            return CC_PLATFORM_OS;
        }

        static constexpr result get() {
            return CC_PLATFORM_OS_TYPE;
        }
    };
}