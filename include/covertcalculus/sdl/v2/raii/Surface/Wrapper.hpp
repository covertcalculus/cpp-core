#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/classes/mixins/crtp/pointers/smart_extensions-T-U.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/Surface/__/namespace.hpp>

#include <SDL2/SDL.h>

#include <memory>

namespace covertcalculus::sdl::v2::raii::Surface {
    class Wrapper : public classes::object, public classes::mixins::crtp::pointers::smart_extensions<Wrapper, SDL_Surface> {
    public:
        using This = Wrapper;
        using Ptr = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
        using WrappedType = SDL_Surface *;
    private:
        Ptr m_surface;
    public:
        Wrapper(WrappedType surface): m_surface{surface, SDL_FreeSurface} {}

        Wrapper(tags::throwing tag, WrappedType surface): This{surface} {
            if (!*this) {
                throw v2::Exception{tag};
            }
        }

        Wrapper(semantics::copy<This> that) = delete;
        Wrapper(semantics::move<This> that)
            : m_surface{std::move(that.m_surface)} {}

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) {
            if (this != &that) {
                m_surface = std::move(that.m_surface);
            }
            return_this;
        }

        WrappedType get() const { return m_surface.get(); }
    };

    using _ = Wrapper;
    using Base = _;
}
