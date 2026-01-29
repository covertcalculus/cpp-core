#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL.h>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/initializers/__/namespace.hpp>

namespace covertcalculus::sdl::v2::raii::initializers {
    class Main : public classes::object {
    public:
        using This = Main;
    private:
        static inline int s_instanceCounter = 0;
        int m_errorCode = 0;
    public:
        Main(Uint32 flags) {
            s_instanceCounter = s_instanceCounter < 1
                ? ( m_errorCode = SDL_Init(flags), int(bool(*this)) )
                : s_instanceCounter + 1;
        }
        ~Main() {
            s_instanceCounter = s_instanceCounter > 1
                ? s_instanceCounter - 1
                : ( SDL_Quit(), 0 );
        }

        Main(tags::throwing tag, Uint32 flags): This{flags} {
            if (!*this) { throw v2::Exception{tag}; }
        }

        Main(semantics::copy<This> i) = delete;
        Main(semantics::move<This> i) = delete;

        semantics::chainable<This> operator =(semantics::copy<This> i) = delete;
        semantics::chainable<This> operator =(semantics::move<This> i) = delete;

        operator bool() const { return GetErrorCode() >= 0; }
        int GetErrorCode() const { return m_errorCode; }
    };

    using _ = Main;
}
