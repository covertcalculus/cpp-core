#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/strings/cstyle_shortlived-T.hpp>
#include <covertcalculus/strings/capitalized_view-T.hpp>
#include <covertcalculus/strings/__/namespace.hpp>
#include <string>

namespace covertcalculus::strings {
    inline std::string capitalize(cstyle_shortlived<char> s) {
        return {covertcalculus::strings::capitalized_view<char>{s}};
    }
}