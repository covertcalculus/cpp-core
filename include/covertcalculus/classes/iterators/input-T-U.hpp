#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/iterators/base-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class input : public classes::iterators::base<ChildClass, ValueType>
    {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::iterators,
            input,
            CC_TEMPLATE_ARGS(ChildClass, ValueType)
        );
    public:
        using value_type = ValueType;

        constexpr value_type operator *() const {
            return this->_downcast_().read();
        }
    };
}