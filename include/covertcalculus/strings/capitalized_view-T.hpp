#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/strings/transformed_view-T-U.hpp>
#include <covertcalculus/strings/__/namespace.hpp>
#include <iostream>
#include <cctype>
#include <string>

namespace covertcalculus::strings {
    template <typename CharType = char>
    class capitalized_view : public transformed_view<capitalized_view<CharType>, CharType> {
    public:
        using This = capitalized_view;
    private:
        const CharType *m_buffer{};
        static bool not_empty(const CharType *s) { return s && *s; }

    public:
        friend inline std::ostream &operator <<(std::ostream &os, const capitalized_view &v) {
            return v.empty() ? os : os << v.first() << v.rest();
        }

        explicit capitalized_view():                  m_buffer{}                           {}
        explicit capitalized_view(const CharType *s): m_buffer{not_empty(s) ? s : nullptr} {}

        CharType transform_at(size_t index) const { return empty() ? CharType{} : (index == 0 ? first() : m_buffer[index]); }

        CharType        first()                     const { return empty() ? nullptr : std::toupper(*m_buffer); }
        const CharType *rest(size_t rest_index = 0) const { return empty() ? nullptr : &m_buffer[1 + rest_index];  }

        size_t size() const { return empty() ? 0 : std::char_traits<CharType>::length(m_buffer); }
        bool  empty() const { return !m_buffer;                                                  }

        operator bool() const { return m_buffer != nullptr; }
        This     next() const { return This{rest()};        }

        operator std::basic_string<CharType>() const {
            return empty() ? std::basic_string<CharType>{} : std::basic_string<CharType>{first()} + rest();
        }
    };
}