#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL.h>
#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/Wrapper.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/From/mixins/Loader.hpp>
#include <covertcalculus/sdl/v2/wrapped_macros/SDL_LoadBMP.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/From/__/namespace.hpp>

namespace covertcalculus::sdl::v2::raii::Surface::From {
    class Bmp : public Surface::_, private mixins::Loader<&wrapped_macros::LoadBMP> {
    public:
        using This = Bmp;

        Bmp(strings::cstyle_shortlived<char> file)
            : _{_load(file)} {}
        Bmp(tags::throwing tag, strings::cstyle_shortlived<char> file)
            : _{_load_or_throw(tag, file)} {}

        Bmp(semantics::copy<This> that) = delete;
        Bmp(semantics::move<This> that): _{std::move(that)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            Surface::_::operator =(std::move(that));
            return_this;
        }
    };
}
