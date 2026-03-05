#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL.h>
#include <covertcalculus/exception/base.hpp>
#include <covertcalculus/sdl/v2/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>
#include <string>

namespace covertcalculus::sdl::v2 {
    class Exception : public exception::base {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::sdl::v2, Exception);
    public:
        explicit Exception(const std::string &message):
            base(  (message.empty() ? std::string() : message + ": ") + SDL_GetError()  ) {}
    };
}
