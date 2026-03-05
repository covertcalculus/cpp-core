#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/iterators/base-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <cstddef>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>


namespace covertcalculus::classes::iterators {
    template <typename ChildClass, typename ValueType>
    class output : public classes::iterators::base<ChildClass, ValueType>
    {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::iterators,
            output,
            CC_TEMPLATE_ARGS(ChildClass, ValueType)
        );
    public:
        using value_type      = ValueType;
        using difference_type = std::ptrdiff_t;

        // *it = value;
        constexpr ChildClass &operator =(const value_type &v) {
            this->_downcast_().write(v);
            return this->_downcast_();
        }

        // Dereference returns the iterator itself (STL convention).
        constexpr ChildClass &operator*() {
            return this->_downcast_();
        }
    };
}
