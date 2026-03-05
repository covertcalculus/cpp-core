#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/strings/__/namespace.hpp>
#include <memory>
#include <string>
#include <string_view>

namespace covertcalculus::strings {
    template <typename CharType = char> class cstyle_shortlived : public classes::object {
    public:
        using This = cstyle_shortlived;
    private:
        std::basic_string<CharType> m_str;
        const CharType *m_cstr;
    public:
        cstyle_shortlived(const CharType * const s):             m_str{}, m_cstr{s}         {}
        cstyle_shortlived(const std::basic_string<CharType> &s): m_str{}, m_cstr{s.c_str()} {}

        cstyle_shortlived(std::basic_string_view<CharType> sv):            m_str{sv},           m_cstr{m_str.c_str()} {}
        cstyle_shortlived(semantics::move<std::basic_string<CharType>> s): m_str{std::move(s)}, m_cstr{m_str.c_str()} {}

        cstyle_shortlived(semantics::copy<This> that): m_str{}, m_cstr{that.m_cstr}{}
        cstyle_shortlived(semantics::move<This> that) = delete;

        semantics::chainable<This> operator =(semantics::copy<This> that) {
            if (this != &that) {
                m_str  = {};
                m_cstr = that.m_cstr;
            }
            return_this;
        }
        semantics::chainable<This> operator =(semantics::move<This> that) = delete;

        const CharType     *c_str() const { return m_cstr;  }
        operator const CharType *() const { return c_str(); }
    };
}