#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/base.hpp>

namespace covertcalculus::classes {
    // for when classes start representing concrete things.
    // classes that effectively don't represent something on their own don't inherit from this class.
    class object : public base {
    public:
        using This = object;
        object() = default;
        ~object() = default;
    };
}