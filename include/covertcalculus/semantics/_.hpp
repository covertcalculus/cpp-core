#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#define return_this return *this
#define mark_as_unused(x) if (&x)

#include "./copy.hpp"
#include "./move.hpp"
#include "./chainable.hpp"