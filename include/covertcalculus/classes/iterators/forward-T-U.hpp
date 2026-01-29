#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/input-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <cstddef>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class forward
        : public classes::iterators::base<ChildClass, ValueType>
        , public mixins::crtp::static_downcaster<ChildClass>
    {
    public:
        using This = forward;
        using value_type = ValueType;
        using reference  = ValueType &;
        using difference_type = std::ptrdiff_t;

        constexpr reference operator *() const {
            return this->_downcast().read_ref();
        }

        constexpr value_type *operator ->() const {
            return &(**this);
        }
    };
}
