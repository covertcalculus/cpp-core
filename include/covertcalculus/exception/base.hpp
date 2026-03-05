#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/classes/polymorphic/object.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_This.hpp>
#include <stdexcept>

namespace covertcalculus::exception {
    // The base class of all exceptions in this library.  It derives from `std::runtime_error` not for its
    // semantic meaning, but for its functionality.
    class base : public classes::polymorphic::object, public std::runtime_error {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::exception, base);
    public:
        explicit base(const std::string &s = ""): std::runtime_error{s}{}
    };
}