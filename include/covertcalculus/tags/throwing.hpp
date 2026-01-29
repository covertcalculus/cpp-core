#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/classes/object.hpp>
#include <covertcalculus/exception/tag/empty.hpp>
#include <covertcalculus/tags/__/namespace.hpp>
#include <string>

namespace covertcalculus::tags {
    // Tag specifying an intent to throw if something goes wrong.
    // By convention, a function that takes a throwing tag should take the
    // throwing tag as the first argument, so the intent is obvious at the call site.
    class throwing : public classes::object {
    private:
        const std::string m_s;
        explicit throwing(): m_s{}{}

        void _throw_if_empty_() const {
            if (m_s.empty()) { throw exception::tag::empty{"User-defined empty tags are unnecessary and not allowed."}; }
        }
    public:
        explicit throwing(const std::string &s): m_s{s} {_throw_if_empty_();}
        explicit throwing(std::string &&s): m_s{std::move(s)} {_throw_if_empty_();}

        // The underlying string that the tag owns.
        const std::string &string() const { return m_s; }

        operator const char *()        const { return string().c_str(); }
        operator const std::string &() const { return string();         }

        // The empty tag.
        static const throwing &f() {
            static throwing v{};
            return v;
        }

        // A reference to the empty tag.
        inline static auto &v = f();

        // The default object, an alias to the empty tag.
        inline static auto &_ = v;
    };
}