#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/Wrapper.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/__/namespace.hpp>

#include <SDL2/SDL.h>

namespace covertcalculus::sdl::v2::raii::Surface {
    class Converted : public Surface::_ {
    public:
        using This = Converted;

        Converted(SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags = 0)
            : _{SDL_ConvertSurface(src, fmt, flags)} {}

        Converted(tags::throwing tag, SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags = 0): This{src, fmt, flags} {
            if (!*this) {
                throw v2::Exception{tag};
            }
        }

        Converted(semantics::copy<This> that) = delete;
        Converted(semantics::move<This> that): _{std::move(that)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            Surface::_::operator =(std::move(that));
            return_this;
        }
    };
}
