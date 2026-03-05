#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/classes/polymorphic/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>


namespace covertcalculus::classes::polymorphic {
    class object : public classes::object {     // for classes representing polymorphic objects
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::classes::polymorphic, object);
    public:
        object() = default;
        virtual ~object() = default;
    };
}