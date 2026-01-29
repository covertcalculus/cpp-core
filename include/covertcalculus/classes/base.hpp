#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

namespace covertcalculus::classes {
    // This represents the base class of all classes in this library.
    // For now, it effectively serves as a tag saying "this type belongs to this library."
    class base {
    protected:
        base() = default;
    public:
        using This = base;
        ~base() = default;
    };
}