#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/forward-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class bidirectional : public forward<ChildClass, ValueType>, public mixins::crtp::static_downcaster<ChildClass> {
    public:
        using This = bidirectional;
        using value_type = ValueType;

        constexpr ChildClass& operator--() {
            this->_downcast().advance(-1);
            return this->_downcast();
        }

        constexpr ChildClass operator--(int) {
            ChildClass temp = this->_downcast();
            this->_downcast().advance(-1);
            return temp;
        }
    };

}
