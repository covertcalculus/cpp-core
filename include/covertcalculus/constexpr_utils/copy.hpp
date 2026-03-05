#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/constexpr_utils/__/namespace.hpp>

#include <cstddef>

namespace covertcalculus::constexpr_utils {
    template <typename T>
    constexpr void copy(const T *src_begin, const T *src_end, T *dest) noexcept {
        for (T *src = src_begin; src != src_end; ++src, ++dest) {
            *dest = *src;
        }
    }
}