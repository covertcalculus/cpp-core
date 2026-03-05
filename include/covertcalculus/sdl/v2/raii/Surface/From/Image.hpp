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
#include <covertcalculus/sdl/v2/raii/Surface/Converted.hpp>
#include <covertcalculus/classes/views/validator-T-U-V.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>

namespace covertcalculus::sdl::v2::raii::Surface::From {
    class Image
        : public Surface::_
        , private mixins::Loader<&IMG_Load>
    {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::sdl::v2::raii::Surface::From, Image);
        CC_DEFINE_PUBLIC_VALIDATOR_MAKERS_AS($v, v2::Exception);
    public:

        Image(strings::cstyle_shortlived<char> file)
            : _{_load(file)} {}
        Image(tags::throwing tag, strings::cstyle_shortlived<char> file)
            : This{file}
        {
            $v().or_throw(tag.string());
        }

        Image(semantics::copy<This> that) = delete;
        Image(semantics::move<This> that): _{std::move(that)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            Surface::_::operator =(std::move(that));
            return_this;
        }

        Surface::_ Convert(const SDL_PixelFormat &fmt, Uint32 flags = 0) const {
            return Surface::Converted{*this, &fmt, flags};
        }

        Surface::_ Convert(tags::throwing tag, const SDL_PixelFormat &fmt, Uint32 flags = 0) const {
            return Surface::Converted{tag, *this, &fmt, flags};
        }
    };
}
