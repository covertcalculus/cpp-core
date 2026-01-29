#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/__preprocessor/macros/platform/CC_PLATFORM_ARCH.hpp>
#include <covertcalculus/platform/__/namespace.hpp>

namespace covertcalculus::platform {
    class arch final {
    public:
        using This = arch;
    public:
        arch() = delete;

        enum class result : int {
            unknown = 0,
            bits32 = 32,
            bits64 = 64,
        };

        class type final {
        public:
            using This = type;
        public:
            type() = delete;
            inline static constexpr auto unknown = result::unknown;
            inline static constexpr auto bits32  = result::bits32;
            inline static constexpr auto bits64  = result::bits64;
        };

        inline static constexpr auto unknown = type::unknown;
        inline static constexpr auto bits32  = type::bits32;
        inline static constexpr auto bits64  = type::bits64;

        static constexpr auto f() { return get(); }

        inline static constexpr result get() {
            return CC_PLATFORM_ARCH_TYPE;
        }

        static constexpr bool is_unknown() { return _is_(unknown); }
        static constexpr bool is64()       { return _is_(bits64);  }
        static constexpr bool is32()       { return _is_(bits32);  }

        class bits final {
        public:
            using This = bits;
            using T = int;
        public:
            bits() = delete;

            static constexpr T get() {
                return static_cast<T>(arch::get());
            }

            static constexpr auto f() { return get(); }

            static constexpr bool is_unknown() { return _is_(0); }
            static constexpr bool is64()       { return _is_(64); }
            static constexpr bool is32()       { return _is_(32); }

        private:
            static constexpr bool _is_(T n) { return get() == n; }
        };
    
    private:
        static constexpr bool _is_(decltype(type::unknown) k) { return get() == k; }
    };
}