#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/views/__/namespace.hpp>
#include <covertcalculus/__preprocessor/macros/CC_NAMESPACE_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA.hpp>
#include <covertcalculus/__preprocessor/macros/CC_TEMPLATE_ARGS.hpp>
#include <covertcalculus/__preprocessor/macros/nameof.hpp>

#include <covertcalculus/strings/cstyle_shortlived-T.hpp>

#include <type_traits>
#include <string>
#include <utility>

namespace covertcalculus::classes::views {
    namespace validator {
        CC_NAMESPACE_METADATA(::covertcalculus::classes::views, validator);
    }
    namespace validator {
        template <typename TRef, typename DefaultException, typename CharType = char>
        class Implementation {
            CC_DEFINE_PUBLIC_TEMPLATE_CLASS_METADATA(
                ::covertcalculus::classes::views::validator,
                Implementation,
                CC_TEMPLATE_ARGS(TRef, DefaultException, CharType)
            );
        public:
            using reference_type = TRef;

            static_assert(
                std::is_reference_v<reference_type>,
                nameof(::covertcalculus::classes::views::validator) "::" nameof(Implementation)
                "<TRef, DefaultException, CharType>"
                " requires the type aliased by member "
                nameof(reference_type)
                " to be a reference type."
            );

            using value_type = std::remove_reference_t<reference_type>;

            static_assert(
                std::is_convertible_v<decltype( std::declval<value_type &>().good() ), bool>,
                nameof(::covertcalculus::classes::views::validator) "::" nameof(Implementation)
                "<TRef, DefaultException, CharType>"
                " requires the type aliased by member "
                nameof(value_type)
                " to implement "
                "bool good() const."
            );

            using exception_type = DefaultException;

        private:
            reference_type m_ref;

            template <typename ExceptionType>
            reference_type _or_throw_as_impl_(strings::cstyle_shortlived<CharType> msg) const {
                // if (!m_ref.good()) {
                if (!*this) {
                    throw ExceptionType(static_cast<std::string>(msg));
                }
                return m_ref;
            }

        public:
            explicit Implementation(const reference_type r) : m_ref(r) {}

            bool good() const {
                return m_ref.good();
            }

            bool bad() const {
                return !good();
            }

            operator bool() const {
                return good();
            }

            bool operator!() const {
                return bad();
            }

            template <typename ExceptionType>
            reference_type or_throw_as(strings::cstyle_shortlived<CharType> msg = "") const & {
                return _or_throw_as_impl_<ExceptionType>(msg);
            }

            template <typename ExceptionType>
            value_type or_throw_as(strings::cstyle_shortlived<CharType> msg = "") const && {
                return std::move(_or_throw_as_impl_<ExceptionType>(msg));
            }

            reference_type or_throw(strings::cstyle_shortlived<CharType> msg = "") const & {
                return or_throw_as<DefaultException>(msg);
            }

            value_type or_throw(strings::cstyle_shortlived<CharType> msg = "") const && {
                return std::move(or_throw_as<DefaultException>(msg));
            }

            // Do we really need to apply the semantic sigil/shortcut pattern here?
            // Some sigils are necessary from a semantic/shortcut perspective, but
            // we don't want to overload users with a large library of $ terms where
            // they aren't necessary.

            // reference_type $ok(strings::cstyle_shortlived<CharType> msg = "") const {
            //     return or_throw(msg);
            // }

            // reference_type $t(strings::cstyle_shortlived<CharType> msg = "") const {
            //     return or_throw(msg);
            // }

            // template <typename E>
            // reference_type $t_as(strings::cstyle_shortlived<CharType> msg = "") const {
            //     return or_throw_as<E>(msg);
            // }
        };

        template <typename TRef, typename DefaultException, typename CharType = char>
        using Type = Implementation<TRef, DefaultException, CharType>;

        template <typename TRef, typename DefaultException, typename CharType = char>
        using This = Type<TRef, DefaultException, CharType>;

        template <typename TRef, typename DefaultException, typename CharType = char>
        using _ = This<TRef, DefaultException, CharType>;

        template <typename TRef, typename DefaultException, typename CharType = char>
        using $ = This<TRef, DefaultException, CharType>;

        template <typename T, typename DefaultException, typename CharType = char>
        inline auto make(T &t) {
            return _<T &, DefaultException, CharType>{t};
        }

        template <typename T, typename DefaultException, typename CharType = char>
        inline auto make(T &&t) {
            return _<T &&, DefaultException, CharType>{std::move(t)};
        }
    }

    template <typename TRef, typename DefaultException, typename CharType = char>
    using validator_ = validator::_<TRef, DefaultException, CharType>;

    template <typename TRef, typename DefaultException, typename CharType = char>
    using validator$ = validator::$<TRef, DefaultException, CharType>;
}

#define CC_MAKE_VALIDATOR_FROM_this(...) \
    ::covertcalculus \
    ::classes \
    ::views \
    ::validator \
    ::make<decltype(*this), __VA_ARGS__>(*this)

#define CC_DEFINE_PUBLIC_VALIDATOR_MAKER_IMPL(const_, qual, validatorMakerMemberName, ...) \
    public: \
        const_ auto validatorMakerMemberName() const_ qual { \
            return CC_MAKE_VALIDATOR_FROM_this(__VA_ARGS__); \
        }

#define CC_DEFINE_PUBLIC_VALIDATOR_MAKERS_AS(validatorMakerMemberName, ...) \
    CC_DEFINE_PUBLIC_VALIDATOR_MAKER_IMPL(, &, validatorMakerMemberName, __VA_ARGS__); \
    CC_DEFINE_PUBLIC_VALIDATOR_MAKER_IMPL(const, &, validatorMakerMemberName, __VA_ARGS__); \
    CC_DEFINE_PUBLIC_VALIDATOR_MAKER_IMPL(, &&, validatorMakerMemberName, __VA_ARGS__); \
    CC_DEFINE_PUBLIC_VALIDATOR_MAKER_IMPL(const, &&, validatorMakerMemberName, __VA_ARGS__)

