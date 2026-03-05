#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/mixins/crtp/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/nameof.hpp>

#include <type_traits>

namespace covertcalculus::classes::mixins::crtp {
    template <typename Child, typename Parent>
    struct NoExtraState : public Parent {
        // static_assert(
        //     std::is_base_of_v<Parent, Child>,
        //     nameof(Child)
        //     " must be a child class of "
        //     nameof(Parent)
        //     "."
        // );
        static_assert(
            sizeof(Parent) == sizeof(Child),
            nameof(Child)
            " must not add any explicit or implicit data members."
        );

        using Parent::Parent;
    };
}