#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/base-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class input
        : public classes::iterators::base<ChildClass, ValueType>
        , public mixins::crtp::static_downcaster<ChildClass>
    {
    public:
        using This = input;
        using value_type = ValueType;

        constexpr value_type operator *() const {
            return this->_downcast().read();
        }
    };
}