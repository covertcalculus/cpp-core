#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>
#include <covertcalculus/classes/mixins/crtp/pointers/__/namespace.hpp>

namespace covertcalculus::classes::mixins::crtp::pointers {
    template <typename ChildClass_SmartPointerType, typename TypeBeingPointedTo>
    class smart_extensions : public base, public static_downcaster<ChildClass_SmartPointerType> {
    public:
        TypeBeingPointedTo *get() const { return this->_downcast().get(); }

        operator TypeBeingPointedTo *()   const { return get(); }
        TypeBeingPointedTo *operator ->() const { return get(); }

        operator bool () const { return get() != nullptr; }

        bool operator ==(const TypeBeingPointedTo *that) const { return get() == that; }
        bool operator !=(const TypeBeingPointedTo *that) const { return get() != that; }

        TypeBeingPointedTo &operator *() const { return *get(); }
    };
}