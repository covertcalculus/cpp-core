#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>

#include <covertcalculus/semantics/_.hpp>
#include <covertcalculus/sdl/v2/Exception.hpp>
#include <covertcalculus/strings/_.hpp>
#include <covertcalculus/classes/mixins/crtp/pointers/smart_extensions-T-U.hpp>
#include <covertcalculus/classes/object.hpp>

#include <covertcalculus/tags/throwing.hpp>

#include <covertcalculus/sdl/v2/raii/__/namespace.hpp>

#include <SDL2/SDL.h>

#include <memory>
#include <string>
#include <string_view>
#include <sstream>

#ifndef CC_SDL_SCREEN_WIDTH
#define CC_SDL_SCREEN_WIDTH 640
#endif

#ifndef CC_SDL_SCREEN_HEIGHT
#define CC_SDL_SCREEN_HEIGHT 480
#endif

namespace covertcalculus::sdl::v2::raii {
    class Window
        : public classes::object
        , public classes::mixins::crtp::pointers::smart_extensions<Window, SDL_Window>
    {
    public:
        using This = Window;
        using Ptr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
        using WrappedType = SDL_Window *;
    private:
        Ptr m_window;
        SDL_Surface *m_rawWindowSurface = nullptr;

        Window(WrappedType rawWindow)
            : m_window{rawWindow, SDL_DestroyWindow}{}

        void _throw_if_bad_(tags::throwing tag) { if (!*this) { throw v2::Exception{tag}; } }

    public:
        class Data {
        public:
            using This = Data;
            using Ptr = const void *;
            using WrappedType = Ptr;
        private:
            WrappedType m_data;
        public:
            explicit Data(WrappedType data): m_data{data}{}
            WrappedType get() const { return m_data; }
            operator WrappedType() const { return get(); }
        };

        Window(Data data)
            : This{SDL_CreateWindowFrom(data)}{}
        Window(strings::cstyle_shortlived<char> title, int x, int y, int w, int h, Uint32 flags = SDL_WINDOW_SHOWN)
            : This{SDL_CreateWindow(title, x, y, w, h, flags)}{}

        Window(strings::cstyle_shortlived<char> title, int w = CC_SDL_SCREEN_WIDTH, int h = CC_SDL_SCREEN_HEIGHT, Uint32 flags = SDL_WINDOW_SHOWN)
            : This{title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags}{}

        Window(tags::throwing tag, Data data)
            : This{data} { _throw_if_bad_(tag); }

        Window(tags::throwing tag, strings::cstyle_shortlived<char> title, int x, int y, int w, int h, Uint32 flags = SDL_WINDOW_SHOWN)
            : This{title, x, y, w, h, flags} { _throw_if_bad_(tag); }

        Window(tags::throwing tag, strings::cstyle_shortlived<char> title, int w = CC_SDL_SCREEN_WIDTH, int h = CC_SDL_SCREEN_HEIGHT, Uint32 flags = SDL_WINDOW_SHOWN)
            : This{title, w, h, flags} { _throw_if_bad_(tag); }

        Window(semantics::copy<This> that) = delete;
        Window(semantics::move<This> that) noexcept:
            m_window{std::move(that.m_window)},
            m_rawWindowSurface{that.m_rawWindowSurface}
        {
            that.m_rawWindowSurface = nullptr;
        }

        WrappedType get() const { return m_window.get(); }

        semantics::chainable<This> operator =(semantics::copy<This> that) = delete;
        semantics::chainable<This> operator =(semantics::move<This> that) noexcept {
            if (this != &that) {
                m_window = std::move(that.m_window);
                m_rawWindowSurface = that.m_rawWindowSurface;
                that.m_rawWindowSurface = nullptr;
            }
            return_this;
        }

        SDL_Surface *GetSurface() noexcept {
            return m_rawWindowSurface
                ? m_rawWindowSurface
                : m_rawWindowSurface = (get()
                    ? GetSurfaceRaw()
                    : nullptr);
        }

        SDL_Surface *GetSurface(tags::throwing tag) noexcept(false) {
            return m_rawWindowSurface
                ? m_rawWindowSurface
                : m_rawWindowSurface = (get()
                    ? GetSurfaceRaw(tag)
                    : nullptr);
        }

        SDL_Surface *GetSurfaceRaw(tags::throwing tag) const {
            if (SDL_Surface *s = GetSurfaceRaw(); s) {
                return s;
            }

            std::stringstream ss;
            if (!tag.string().empty()) {
                ss << tag << "\n\n";
            }
            ss << "Window address: " << get() << '\n';
            ss << "Error";
            throw v2::Exception{ss.str()};
        }

        SDL_Surface *GetSurfaceRaw() const noexcept {
            return SDL_GetWindowSurface(get());
        }

        SDL_Surface *GetSurfaceRawOrCached() const noexcept {
            return m_rawWindowSurface ? m_rawWindowSurface : GetSurfaceRaw();
        }

        SDL_Surface *GetSurfaceRawOrCached(tags::throwing tag) const {
            return m_rawWindowSurface ? m_rawWindowSurface : GetSurfaceRaw(tag);
        }

        semantics::chainable<This> InvalidateSurface() noexcept {
            m_rawWindowSurface = nullptr; return_this;
        }

        semantics::chainable<This> UpdateSurface(tags::throwing tag = tags::throwing::_) noexcept(false) {
            if (int code = SDL_UpdateWindowSurface(get()); code) {
                std::stringstream ss;
                if (!tag.string().empty()) {
                    ss << tag << "\n\n";
                }
                ss << "(Code " << code << ") - ";
                ss << "Error updating window surface at " << get();
                throw v2::Exception{ss.str()};
            }
            return_this;
        }
    };
}