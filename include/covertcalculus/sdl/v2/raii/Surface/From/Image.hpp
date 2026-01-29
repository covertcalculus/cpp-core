#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL_image.h>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/Wrapper.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/From/mixins/Loader.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/From/__/namespace.hpp>

namespace covertcalculus::sdl::v2::raii::Surface::From {
    class Image : public Surface::_, private mixins::Loader<&IMG_Load> {
    public:
        using This = Image;

        Image(strings::cstyle_shortlived<char> file)
            : _{_load(file)} {}
        Image(tags::throwing tag, strings::cstyle_shortlived<char> file)
            : _{_load_or_throw(tag, file)} {}

        Image(semantics::copy<This> that) = delete;
        Image(semantics::move<This> that): _{std::move(that)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            Surface::_::operator =(std::move(that));
            return_this;
        }
    };
}
