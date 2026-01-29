#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/classes/polymorphic/object.hpp>
#include <stdexcept>

namespace covertcalculus::exception {
    // The base class of all exceptions in this library.  It derives from `std::runtime_error` not for its
    // semantic meaning, but for its functionality.
    class base : public classes::polymorphic::object, public std::runtime_error {
    public:
        using This = base;
        explicit base(const std::string &s = ""): std::runtime_error{s}{}
    };
}