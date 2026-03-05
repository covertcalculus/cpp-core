#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/iterators/bidirectional-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <cstddef> // for ptrdiff_t
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_This.hpp>
#include <covertcalculus/__preprocessor/macros/CC_JOIN_PAIR.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>

namespace covertcalculus::classes::iterators {

    template <typename ChildClass, typename ValueType>
    class random_access : public bidirectional<ChildClass, ValueType>
    {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::iterators,
            random_access,
            CC_TEMPLATE_ARGS(ChildClass, ValueType)
        );
    public:
        using value_type = ValueType;
        using reference = ValueType &;
        using difference_type = std::ptrdiff_t;

        // += n
        constexpr ChildClass& operator+=(difference_type n) {
            this->_downcast_().advance(n);
            return this->_downcast_();
        }

        // -= n
        constexpr ChildClass& operator-=(difference_type n) {
            this->_downcast_().advance(-n);
            return this->_downcast_();
        }

        // it + n
        constexpr ChildClass operator+(difference_type n) const {
            ChildClass temp = this->_downcast_();
            return temp += n;
        }

        // it - n
        constexpr ChildClass operator-(difference_type n) const {
            ChildClass temp = this->_downcast_();
            return temp -= n;
        }

        // distance: it2 - it1
        constexpr difference_type operator-(const ChildClass& other) const {
            return this->_downcast_().distance_to(other);
        }

        // indexing: it[n]
        constexpr value_type operator[](difference_type n) const {
            return *(*this + n);
        }

        // ordering
        constexpr bool operator<(const ChildClass& other) const {
            return this->_downcast_().less_than(other);
        }

        constexpr bool operator>(const ChildClass& other) const {
            return other < this->_downcast_();
        }

        constexpr bool operator<=(const ChildClass& other) const {
            return !(this->_downcast_() > other);
        }

        constexpr bool operator>=(const ChildClass& other) const {
            return !(this->_downcast_() < other);
        }
    };
}
