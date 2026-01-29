#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/__preprocessor/require/header/SDL2/SDL_image.h>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/initializers/__/namespace.hpp>

#include <SDL2/SDL_image.h>

namespace covertcalculus::sdl::v2::raii::initializers {
    class Image : public classes::object {
    public:
        using This = Image;
    private:
        static inline int s_nonQueryInstanceCount = 0;
        const int m_inFlags;
        const int m_outFlags;
    public:
        Image(int flags = 0): m_inFlags{flags}, m_outFlags{IMG_Init(flags)} {
            s_nonQueryInstanceCount += int(!IsQueryInstance() && *this);
        }
        Image(tags::throwing tag, int flags): This(flags) {
            if (!*this) {
                throw v2::Exception{tag};
            }
        }
        ~Image() {
            if (s_nonQueryInstanceCount > 0) {
                if (--s_nonQueryInstanceCount <= 0) {
                    IMG_Quit();
                    s_nonQueryInstanceCount = 0;
                }
            }
        }

        Image(semantics::copy<This> i) = delete;
        Image(semantics::move<This> i) = delete;

        semantics::chainable<This> operator =(semantics::copy<This> i) = delete;
        semantics::chainable<This> operator =(semantics::move<This> i) = delete;

        operator bool() const {
            return IsQueryInstance() || InitializedFlags() == m_inFlags;
        }

        bool IsQueryInstance() const { return !m_inFlags; }
        int GetOutputFlags()   const { return m_outFlags; }
        int InitializedFlags() const { return GetOutputFlags() & m_inFlags; }

        static int QueryFlags() { return IMG_Init(0); }
    };
}