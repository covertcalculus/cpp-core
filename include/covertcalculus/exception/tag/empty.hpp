#pragma once

#include <covertcalculus/exception/base.hpp>
#include <covertcalculus/exception/tag/__/namespace.hpp>

#include <string>

namespace covertcalculus::exception::tag {
    // This exception gets thrown on an empty tag, if the tag type doesn't allow empty tags.
    class empty : public exception::base {
    public:
        using This = empty;
    public:
        explicit empty(const std::string &s = ""): covertcalculus::exception::base{s}{}
    };
}