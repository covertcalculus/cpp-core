#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/mixins/crtp/pointers/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PRIVATE_DOWNCASTERS_TO.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_JOIN_PAIR.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>
#include <covertcalculus/classes/views/validator-T-U-V.hpp>

namespace covertcalculus::classes::mixins::crtp::pointers {
    template <typename ChildClass_SmartPointerType, typename TypeBeingPointedTo, typename DefaultException>
    class smart_extensions {
        CC_DEFINE_PRIVATE_DOWNCASTERS_TO(ChildClass_SmartPointerType, _downcast_);
        CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
            ::covertcalculus::classes::mixins::crtp::pointers, base,
            CC_TEMPLATE_ARGS(ChildClass_SmartPointerType, TypeBeingPointedTo, DefaultException)
        );
    public:
        TypeBeingPointedTo *get() const { return this->_downcast_().get(); }

        operator TypeBeingPointedTo *()   const { return get(); }
        TypeBeingPointedTo *operator ->() const { return get(); }

        bool good() const { return get() != nullptr; }

        bool operator ==(const TypeBeingPointedTo *that) const { return get() == that; }
        bool operator !=(const TypeBeingPointedTo *that) const { return get() != that; }

        TypeBeingPointedTo &operator *() const { return *get(); }
    };
}