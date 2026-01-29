#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/strings/__/namespace.hpp>
#include <cstddef>
#include <string>
#include <iostream>

namespace covertcalculus::strings {
    template <typename ChildClass, typename CharType = char>
    class transformed_view : public classes::object, public classes::mixins::crtp::static_downcaster<ChildClass>
    {
    public:
        using This = transformed_view;
 
        CharType operator [](size_t index) const {
            return this->_downcast().transform_at(index);
        }

        size_t size() const {
            return this->_downcast().size();
        }

        bool empty() const {
            return size() == 0;
        }

        operator std::basic_string<CharType>() const {
            std::basic_string<CharType> out;
            size_t theSize = size();
            out.reserve(theSize);
            for (size_t i = 0; i < theSize; ++i) {
                out.push_back((*this)[i]);
            }
            return out;
        }

        friend inline std::ostream &operator <<(std::ostream &os, const This &view) {
            for (size_t i = 0, len = view.size(); i < len; i++) {
                os << view[i];
            }
            return os;
        }
    };
}