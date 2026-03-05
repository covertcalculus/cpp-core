#pragma once

#include <covertcalculus/__preprocessor/macros/CC_WITH_EXCEPTION_HANDLER_FORWARD_ENTRY_FROM_main_TO.hpp>

#define CC_FORWARD_ENTRY_FROM_main_TO(entryFunctionName, ostreamError) \
    CC_WITH_EXCEPTION_HANDLER_FORWARD_ENTRY_FROM_main_TO( \
        entryFunctionName, \
        [](const std::exception &e) { \
            std::ostream &ose = (ostreamError); \
            ose << e.what() << std::endl; \
            return 1;\
        } \
    )
