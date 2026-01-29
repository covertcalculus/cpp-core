#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class base : public classes::base, public mixins::crtp::static_downcaster<ChildClass> {
    public:
        using This = base;
        using value_type = ValueType;

        constexpr ChildClass &operator ++() {
            this->_downcast().advance(1);
            return this->_downcast();
        }

        // assumes iterator is copyable
        constexpr ChildClass operator ++(int) {
            ChildClass temp = *this;
            ++(*this);
            return temp;
        }

        constexpr bool operator !=(const ChildClass &other) const {
            return !this->_downcast().equals(other);
        }
    };
}