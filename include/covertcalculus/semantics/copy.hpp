#pragma once

#include <covertcalculus/semantics/__/namespace.hpp>

namespace covertcalculus::semantics {
    template <typename T> using copy = const T &;
}