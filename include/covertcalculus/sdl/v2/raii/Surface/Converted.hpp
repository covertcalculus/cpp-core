#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/Wrapper.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>

#include <SDL2/SDL.h>
#include <type_traits>
#include <cstddef>

namespace covertcalculus::sdl::v2::raii::Surface {
    class Converted
        : public Surface::_
    {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::sdl::v2::raii::Surface, Converted);
        CC_DEFINE_PUBLIC_VALIDATOR_MAKERS_AS($v, v2::Exception);

    private:
        using Parent0 = Surface::_;

    public:
        template <std::size_t N>
        using Parent = std::conditional_t<N == 0, Parent0, std::nullptr_t>;

    public:
        Converted(SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags = 0)
            : Parent<0>{SDL_ConvertSurface(src, fmt, flags)} {}

        Converted(tags::throwing tag, SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags = 0)
            : This{src, fmt, flags}
        {
            $v().or_throw(tag.string());
        }

        Converted(semantics::copy<This> that) = delete;
        Converted(semantics::move<This> that): Parent<0>{std::move(that)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            Surface::_::operator =(std::move(that));
            return_this;
        }
    };

    static_assert(
        sizeof(Converted) == sizeof(Converted::Parent<0>),
        nameof(Converted) " must not add any implicit or explicit data members."
    );
}
