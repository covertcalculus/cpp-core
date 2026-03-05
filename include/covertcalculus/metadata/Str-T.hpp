#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/metadata/__/namespace.hpp>

#include <covertcalculus/constexpr_utils/copy.hpp>

#include <cstddef>
#include <string_view>

namespace covertcalculus::metadata {
    namespace Str {

        template <std::size_t N>
        class Implementation {
        public:
            using This = Implementation;
        private:
            char m_v[N];
        public:
            explicit constexpr Implementation(const char (&s)[N]) {
                constexpr_utils::copy(s, s + N, m_v);
            }

            constexpr std::size_t capacity() const { return N; }
            constexpr std::size_t size() const { return capacity() - 1; }

            constexpr const char * const c_str() const { return m_v; }
            constexpr std::string_view view()    const { return std::string_view{c_str(), capacity()}; }

            constexpr const char * const cbegin() const { return c_str(); }
            constexpr const char * const cend()   const { return c_str() + capacity(); }

            constexpr const char * const crbegin() const { return c_str() - 1 + capacity(); }
            constexpr const char * const crend()   const { return c_str() - 1; }

            constexpr operator const char * const() const { return c_str(); }

            constexpr const char &operator *() const { return *c_str(); }
        };
        
        template <std::size_t N>
        using Type = Implementation<N>;

        template <std::size_t N>
        using This = Type<N>;

        template <std::size_t N>
        constexpr This<N> make(const char (&s)[N]) {
            return This<N>{s};
        }

        template <std::size_t N>
        using _ = This<N>;

        template <std::size_t N>
        using $ = This<N>;
    }

    template <std::size_t N>
    using Str_ = Str::_<N>;

    template <std::size_t N>
    using Str$ = Str::$<N>;
}