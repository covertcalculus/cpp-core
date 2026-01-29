#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/classes/polymorphic/__/namespace.hpp>

namespace covertcalculus::classes::polymorphic {
    class object : public classes::object {     // for classes representing polymorphic objects
    public:
        using This = object;
    private:
    public:
        object() = default;
        virtual ~object() = default;
    };
}