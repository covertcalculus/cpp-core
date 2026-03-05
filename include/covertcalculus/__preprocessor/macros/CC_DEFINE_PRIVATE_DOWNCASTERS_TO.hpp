#pragma once

#include <covertcalculus/__preprocessor/macros/CC_AS.hpp>
#include <type_traits>

#define CC_DEFINE_PRIVATE_DOWNCASTERS_TO(Type, name) \
    private:\
        Type       &name()       { return static_cast<      Type &>(*this); } \
        const Type &name() const { return static_cast<const Type &>(*this); }

