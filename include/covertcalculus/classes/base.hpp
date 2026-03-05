#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>

namespace covertcalculus::classes {
    // This represents the base class of all classes in this library.
    // For now, it effectively serves as a tag saying "this type belongs to this library."
    class base {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::classes, base);
    protected:
        base() = default;   // don't allow direct instantiation.
    public:
        ~base() = default;
    };
}