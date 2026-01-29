#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/sdl/v2/wrapped_macros/__/namespace.hpp>

#include <SDL2/SDL.h>

namespace covertcalculus::sdl::v2::wrapped_macros {
    inline SDL_Surface *LoadBMP(strings::cstyle_shortlived<char> file) {
        return SDL_LoadBMP(file);
    }
}