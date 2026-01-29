#pragma once

#include <SDL2/SDL.h>
#include <covertcalculus/classes/base.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/strings/cstyle_shortlived-T.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/From/mixins/__/namespace.hpp>
#include <sstream>

namespace covertcalculus::sdl::v2::raii::Surface::From::mixins {
    template <auto LoaderCallback>
    class Loader : public classes::base {
    protected:
        static SDL_Surface *_load(strings::cstyle_shortlived<char> file) {
            return LoaderCallback(file);
        }
        static SDL_Surface *_load_or_throw(tags::throwing tag, strings::cstyle_shortlived<char> file) {
            if (SDL_Surface *s = Loader::_load(file); s) { return s; }
            std::stringstream ss;
            ss << '(' << file << "): " << tag;
            throw sdl2::Exception{ss.str()};
        }
    };
}