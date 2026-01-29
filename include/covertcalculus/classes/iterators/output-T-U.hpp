#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/base-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <cstddef>

namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class output
        : public classes::iterators::base<ChildClass, ValueType>
        , public mixins::crtp::static_downcaster<ChildClass>
    {
    public:
        using This            = output;
        using value_type      = ValueType;
        using difference_type = std::ptrdiff_t;

        // *it = value;
        constexpr ChildClass &operator =(const value_type &v) {
            this->_downcast().write(v);
            return this->_downcast();
        }

        // Dereference returns the iterator itself (STL convention).
        constexpr ChildClass &operator*() {
            return this->_downcast();
        }
    };
}
