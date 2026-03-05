#pragma once

#include <covertcalculus/classes/views/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>

namespace covertcalculus::classes::views {
    template <typename T>
    class nonzero {
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::views,
            nonzero,
            CC_TEMPLATE_ARGS(T)
        );
    private:
        T m_value;
    public:
        explicit nonzero(T value): m_value{value}{}

        T value() { return m_value; }
        operator T() { return value(); }

        const T value() const { return m_value; }
        operator const T() const { return value(); }

        bool good() const { return !!m_value; }
    };
}