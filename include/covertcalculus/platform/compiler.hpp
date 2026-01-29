#pragma once

#include <covertcalculus/__preprocessor/macros/platform/CC_PLATFORM_COMPILER.hpp>
#include <covertcalculus/platform/__/namespace.hpp>

namespace covertcalculus::platform {
    // Compiler introspection.  This class is not instantiable or derivable.
    class compiler final {
    public:
        compiler() = delete;

        enum class result_from_get : int {
            unknown = 0,    // Returned by get() when the compiler is unknown.  Use `type::unknown` instead.
            emscripten,     // Returned by get() when the compiler is Emscripten.  Use `type::emscripten` instead.
            msvc,           // Returned by get() when the compiler is Microsoft Visual C++.  Use `type::msvc` instead.
            clang,          // Returned by get() when the compiler is Clang.  Use `type::clang` instead.
            mingw64,        // Returned by get() when the compiler is MinGW64.  Use `type::mingw64` instead.
            mingw32,        // Returned by get() when the compiler is MinGW32.  Use `type::mingw32` instead.
            gcc,            // Returned by get() when the compiler is *nix GCC.  Use `type::gcc` instead.
            watcom,         // Returned by get() when the compiler is Watcom C++.  Use `type::watcom` instead.
        };

        // Aliases to the `result_from_get` enum, which should be treated as an implementation
        // detail.  Use of this class is encouraged.
        class type final {
        public:
            type() = delete;

            static constexpr auto unknown    = result_from_get::unknown;    // Returned by `get()` when the compiler is unknown.
            static constexpr auto emscripten = result_from_get::emscripten; // Returned by `get()` when the compiler is Emscripten.
            static constexpr auto msvc       = result_from_get::msvc;       // Returned by `get()` when the compiler is Microsoft Visual C++.
            static constexpr auto clang      = result_from_get::clang;      // Returned by `get()` when the compiler is Clang.
            static constexpr auto mingw64    = result_from_get::mingw64;    // Returned by `get()` when the compiler is MinGW64.
            static constexpr auto mingw32    = result_from_get::mingw32;    // Returned by `get()` when the compiler is MinGW32.
            static constexpr auto gcc        = result_from_get::gcc;        // Returned by `get()` when the compiler is *nix GCC.
            static constexpr auto watcom     = result_from_get::watcom;     // Returned by `get()` when the compiler is Watcom C++.
        };

        static constexpr auto unknown    = type::unknown;       // Alias for `type::unknown`.
        static constexpr auto emscripten = type::emscripten;    // Alias for `type::emscripten`.
        static constexpr auto msvc       = type::msvc;          // Alias for `type::msvc`.
        static constexpr auto clang      = type::clang;         // Alias for `type::clang`.
        static constexpr auto mingw64    = type::mingw64;       // Alias for `type::mingw64`.
        static constexpr auto mingw32    = type::mingw32;       // Alias for `type::mingw32`.
        static constexpr auto gcc        = type::gcc;           // Alias for `type::gcc`.
        static constexpr auto watcom     = type::watcom;        // Alias for `type::watcom`.

        // An alias for `get()`.  A workaround for there being no `static operator()` in C++.
        static constexpr auto f() { return get(); }

        // Returns a constant describing the compiler.
        static constexpr result_from_get get() {
            return static_cast<result_from_get>(CC_PLATFORM_COMPILER_RESULT);
        }

        // Returns a C-style string describing the compiler.
        static constexpr const char *c_str() {
            return CC_PLATFORM_COMPILER_C_STR;
        }

    private:
        static constexpr bool _is_(result_from_get r) { return get() == r; }

    public:
        static constexpr bool is_emscripten() { return _is_(emscripten); }
        static constexpr bool is_msvc()       { return _is_(msvc);       }
        static constexpr bool is_clang()      { return _is_(clang);      }
        static constexpr bool is_mingw64()    { return _is_(mingw64);    }
        static constexpr bool is_mingw32()    { return _is_(mingw32);    }
        static constexpr bool is_watcom()     { return _is_(watcom);     }
        static constexpr bool is_gcc()        { return _is_(gcc);        }

        static constexpr bool is_mingw()   { return is_mingw64() || is_mingw32(); }
        static constexpr bool is_any_gcc() { return is_mingw()   || is_gcc();     }
        static constexpr bool is_gnuc()    { return is_any_gcc() || is_clang();   }
    };
}
