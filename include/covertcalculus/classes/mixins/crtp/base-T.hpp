#pragma once

#include <covertcalculus/classes/mixins/crtp/static_downcaster-T.hpp>

namespace covertcalculus::classes::mixins::crtp {
    template <typename T> using base = static_downcaster<T>;
}