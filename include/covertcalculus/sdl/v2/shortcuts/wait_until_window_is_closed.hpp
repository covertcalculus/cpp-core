#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/sdl/v2/shortcuts/__/namespace.hpp>

#include <SDL2/SDL.h>

namespace covertcalculus::sdl::v2::shortcuts {
    inline void wait_until_window_is_closed(bool running = true) {
        SDL_Event e;
        while ( running ) {
            while ( SDL_PollEvent( &e ) ) {
                if ( e.type == SDL_QUIT ) { running = false; }
            }
        }
    }
}