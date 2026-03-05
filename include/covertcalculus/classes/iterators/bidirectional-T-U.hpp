#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/iterators/forward-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class bidirectional : public forward<ChildClass, ValueType> {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::iterators,
            bidirectional,
            CC_TEMPLATE_ARGS(ChildClass, ValueType)
        );
    public:
        using value_type = ValueType;

        constexpr ChildClass& operator--() {
            this->_downcast_().advance(-1);
            return this->_downcast_();
        }

        constexpr ChildClass operator--(int) {
            ChildClass temp = this->_downcast_();
            this->_downcast_().advance(-1);
            return temp;
        }
    };

}
