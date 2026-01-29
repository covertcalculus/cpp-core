#include "../cpp.hpp"
#include <covertcalculus/__preprocessor/macros/platform/CC_CPP_STANDARD.hpp>

#if CC_CPP_STANDARD < 17
#error "C++17 is required."
#endif
