#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/tags/throwing.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/sdl/v2/raii/initializers/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>
#include <covertcalculus/classes/views/validator-T-U-V.hpp>

#include <SDL2/SDL_image.h>

namespace covertcalculus::sdl::v2::raii::initializers {
    class Image : public classes::object
    {
        CC_DEFINE_PUBLIC_CLASS_METADATA(::covertcalculus::sdl::v2::raii::initializers, Image);
        CC_DEFINE_PUBLIC_VALIDATOR_MAKERS_AS($v, v2::Exception);
    private:
        static inline int s_nonQueryInstanceCount = 0;
        const int m_inFlags;
        const int m_outFlags;

        struct AssignFieldsAndCount {};
        struct CopyFieldsAndCount {};

        Image(AssignFieldsAndCount, int inFlags, int outFlags)
            : m_inFlags{inFlags}
            , m_outFlags{outFlags}
        {
            _countThisObjectIfNeeded_();
        }

        Image(CopyFieldsAndCount, const This &that)
            : This{AssignFieldsAndCount{}, that.m_inFlags, that.m_outFlags}
        {}

        void _countThisObjectIfNeeded_() {
            s_nonQueryInstanceCount += int(!IsQueryInstance() && good());
        }

    public:
        Image(int flags = 0): This{AssignFieldsAndCount{}, flags, IMG_Init(flags)} {}
        Image(tags::throwing tag, int flags = 0): This{flags} { $v().or_throw(tag.string()); }
        ~Image() {
            if (s_nonQueryInstanceCount > 0) {
                if (--s_nonQueryInstanceCount <= 0) {
                    IMG_Quit();
                    s_nonQueryInstanceCount = 0;
                }
            }
        }

        Image(semantics::copy<This> that): This{CopyFieldsAndCount{}, that} {}
        Image(semantics::move<This> that): This{CopyFieldsAndCount{}, that} {}

        semantics::chainable<This> operator =(semantics::copy<This> i) = delete;
        semantics::chainable<This> operator =(semantics::move<This> i) = delete;

        bool good() const {
            return IsQueryInstance() || InitializedFlags() == m_inFlags;
        }

        bool IsQueryInstance() const { return !m_inFlags; }
        int GetOutputFlags()   const { return m_outFlags; }
        int InitializedFlags() const { return GetOutputFlags() & m_inFlags; }

        static int QueryFlags() { return IMG_Init(0); }
    };
}