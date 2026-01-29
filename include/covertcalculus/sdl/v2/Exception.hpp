#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL.h>
#include <covertcalculus/exception/base.hpp>
#include <covertcalculus/sdl/v2/__/namespace.hpp>
#include <string>

namespace covertcalculus::sdl::v2 {
    class Exception : public exception::base {
    public:
        using This = Exception;
        explicit Exception(const std::string &message):
            base(  (message.empty() ? std::string() : message + ": ") + SDL_GetError()  ) {}
    };
}
