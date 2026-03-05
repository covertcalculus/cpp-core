#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <SDL2/SDL.h>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/initializers/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_This.hpp>

#include <covertcalculus/classes/views/validator-T-U-V.hpp>

#include <cstddef>

namespace covertcalculus::sdl::v2::raii::initializers {
    class Main : public classes::object {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::sdl::v2::raii::initializers, Main);
        CC_DEFINE_PUBLIC_VALIDATOR_MAKERS_AS($v, v2::Exception);
    private:
        static inline int s_instanceCounter = 0;
        int m_errorCode = 0;

        struct AssignFields {};
        Main(AssignFields, int errorCode): m_errorCode{errorCode} {}

        struct CopyFields {};
        Main(CopyFields, const This &that): This{AssignFields{}, that.m_errorCode} {}

        int _countThisIfGood_(int scale) {
            return s_instanceCounter = std::max(s_instanceCounter, 0) + (int(good()) * scale);
        }

    public:
        Main(Uint32 flags): This{AssignFields{}, SDL_Init(flags)} { _countThisIfGood_(1); }
        Main(semantics::copy<This> that): This{CopyFields{}, that} { _countThisIfGood_(1); }
        Main(semantics::move<This> that): This{CopyFields{}, that} { _countThisIfGood_(1); }

        Main(tags::throwing tag, Uint32 flags): This{flags} { $v().or_throw(tag.string()); }

        ~Main() {
            if (s_instanceCounter > 1) {
                if (_countThisIfGood_(-1) == 0) {
                    SDL_Quit();
                }
            }
            if (s_instanceCounter < 0) {
                s_instanceCounter = 0;
            }
        }

        semantics::chainable<This> operator =(semantics::copy<This> i) = delete;
        semantics::chainable<This> operator =(semantics::move<This> i) = delete;

        bool good() const { return GetErrorCode() >= 0; }
        int GetErrorCode() const { return m_errorCode; }

        operator bool() const { return $v(); }
    };

    using _ = Main;
}
