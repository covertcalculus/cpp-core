#include "../cpp.hpp"
#include <covertcalculus/__preprocessor/macros/platform/CC_CPP_STANDARD.hpp>

#if CC_CPP_STANDARD < 20
#error "C++20 is required."
#endif
