#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>

#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_This.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_JOIN_PAIR.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class base
        : public classes::base
    {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::iterators,
            base,
            CC_TEMPLATE_ARGS(ChildClass, ValueType)
        );
    public:
        using value_type = ValueType;

        constexpr ChildClass &operator ++() {
            this->_downcast_().advance(1);
            return this->_downcast_();
        }

        // assumes iterator is copyable
        constexpr ChildClass operator ++(int) {
            ChildClass temp = *this;
            ++(*this);
            return temp;
        }

        constexpr bool operator !=(const ChildClass &other) const {
            return !this->_downcast_().equals(other);
        }
    };
}