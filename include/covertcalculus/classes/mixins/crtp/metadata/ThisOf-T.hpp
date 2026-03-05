#pragma once

#include <covertcalculus/classes/mixins/crtp/metadata/__/namespace.hpp>

namespace covertcalculus::classes::mixins::crtp::metadata {
    template <typename T>
    struct ThisOf {
        ThisOf() = delete;
        using This = T;
    };
}