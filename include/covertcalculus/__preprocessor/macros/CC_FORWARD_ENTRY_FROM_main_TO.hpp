#pragma once

#include <covertcalculus/memory/span.hpp>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <vector>

#define CC_FORWARD_ENTRY_FROM_main_TO(entryFunctionName, ostreamError)\
    int entryFunctionName(covertcalculus::memory::span<char *> args);\
    int main(int argc, char **argv) {\
        std::ostream &ose = (ostreamError);\
        try {\
            return entryFunctionName(covertcalculus::memory::span{argv, argc});\
        } catch (const std::exception &e) {\
            ose << e.what() << std::endl;\
        }\
        return 1;\
    }
