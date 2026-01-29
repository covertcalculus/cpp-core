#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/classes/mixins/crtp/__/namespace.hpp>

namespace covertcalculus::classes::mixins::crtp {
    template <typename ChildClass>
    class static_downcaster : public base {
    protected:
        ChildClass       &_downcast()       { return static_cast<      ChildClass &>(*this); }
        const ChildClass &_downcast() const { return static_cast<const ChildClass &>(*this); }
    };
}