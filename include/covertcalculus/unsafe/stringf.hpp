#pragma once

#include <covertcalculus/unsafe/__/namespace.hpp>
#include <covertcalculus/strings/cstyle_shortlived-T.hpp>
#include <string>

namespace covertcalculus::unsafe {
    template <class... Args>
    inline std::string stringf(strings::cstyle_shortlived<char> fmt, Args... args) {
        int size = std::snprintf(nullptr, 0, fmt, args...);
        if (size < 0) { return {}; }

        std::string s(size, '\0');
        std::snprintf(&s[0], size + 1, fmt, args...);
        return s;
    }
}