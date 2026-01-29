#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/iterators/bidirectional-T-U.hpp>
#include <covertcalculus/classes/iterators/__/namespace.hpp>
#include <cstddef> // for ptrdiff_t

namespace covertcalculus::classes::iterators {

    template <typename ChildClass, typename ValueType>
    class random_access
        : public bidirectional<ChildClass, ValueType>
        , public mixins::crtp::static_downcaster<ChildClass>
    {
    public:
        using This = random_access;
        using value_type = ValueType;
        using reference = ValueType &;
        using difference_type = std::ptrdiff_t;

        // += n
        constexpr ChildClass& operator+=(difference_type n) {
            this->_downcast().advance(n);
            return this->_downcast();
        }

        // -= n
        constexpr ChildClass& operator-=(difference_type n) {
            this->_downcast().advance(-n);
            return this->_downcast();
        }

        // it + n
        constexpr ChildClass operator+(difference_type n) const {
            ChildClass temp = this->_downcast();
            return temp += n;
        }

        // it - n
        constexpr ChildClass operator-(difference_type n) const {
            ChildClass temp = this->_downcast();
            return temp -= n;
        }

        // distance: it2 - it1
        constexpr difference_type operator-(const ChildClass& other) const {
            return this->_downcast().distance_to(other);
        }

        // indexing: it[n]
        constexpr value_type operator[](difference_type n) const {
            return *(*this + n);
        }

        // ordering
        constexpr bool operator<(const ChildClass& other) const {
            return this->_downcast().less_than(other);
        }

        constexpr bool operator>(const ChildClass& other) const {
            return other < this->_downcast();
        }

        constexpr bool operator<=(const ChildClass& other) const {
            return !(this->_downcast() > other);
        }

        constexpr bool operator>=(const ChildClass& other) const {
            return !(this->_downcast() < other);
        }
    };
}
