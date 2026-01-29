#pragma once

#include <covertcalculus/__preprocessor/require/cpp/17.hpp>
#include <covertcalculus/__preprocessor/macros/platform/CC_CPP_STANDARD.hpp>
#include <cstddef>

#if CC_CPP_STANDARD >= 20
    #include <span>
    namespace covertcalculus::memory {
        template <typename T, std::size_t Extent = std::dynamic_extent>
        using span = std::span<T, Extent>;
    }
#else
    #include <type_traits>
    #include <array>
    #include <cassert>

    // covertcalculus::memory::span does not inherit from covertcalculus::classes::base.
    // the intent of covertcalculus::memory::span is to look, walk, and quack like a C++20
    // std::span if it isn't available.

    namespace covertcalculus::memory {

        inline constexpr std::size_t dynamic_extent = static_cast<std::size_t>(-1);

        template <class T, std::size_t Extent = dynamic_extent>
        class span;

        namespace detail {

            template <class T, std::size_t Extent>
            struct span_storage {
                T* ptr;

                constexpr span_storage() noexcept : ptr(nullptr) {}
                constexpr span_storage(T* p) noexcept : ptr(p) {}
                constexpr span_storage(T* p, std::size_t) noexcept : ptr(p) {}

                static constexpr std::size_t size() noexcept { return Extent; }
            };

            template <class T>
            struct span_storage<T, dynamic_extent> {
                T* ptr;
                std::size_t size_;

                constexpr span_storage() noexcept : ptr(nullptr), size_(0) {}
                constexpr span_storage(T* p, std::size_t size) noexcept : ptr(p), size_(size) {}

                constexpr std::size_t size() const noexcept { return size_; }
            };

        } // namespace detail

        template <class T, std::size_t Extent>
        class span {
        public:
            using element_type = T;
            using value_type = typename std::remove_cv<T>::type;
            using pointer = T*;
            using reference = T&;

            static constexpr std::size_t extent = Extent;

            constexpr span() noexcept {
                static_assert(Extent == 0 || Extent == dynamic_extent,
                            "default constructor only valid for extent == 0 or dynamic_extent");
            }

            constexpr span(pointer ptr, std::size_t count) noexcept : storage_(ptr, count) {
                if constexpr (Extent != dynamic_extent) {
                    assert(count == Extent);
                }
            }

            constexpr span(pointer first, pointer last) noexcept
                : span(first, static_cast<std::size_t>(last - first)) {}

            template <std::size_t N,
                    class = std::enable_if_t<(Extent == dynamic_extent || N == Extent)>>
            constexpr span(element_type (&arr)[N]) noexcept : storage_(arr, N) {}

            template <std::size_t N,
                    class = std::enable_if_t<(Extent == dynamic_extent || N == Extent)>>
            constexpr span(std::array<value_type, N>& arr) noexcept
                : storage_(arr.data(), N) {}

            template <std::size_t N,
                    class = std::enable_if_t<(Extent == dynamic_extent || N == Extent)>>
            constexpr span(const std::array<value_type, N>& arr) noexcept
                : storage_(arr.data(), N) {}

            template <class U, std::size_t E,
                    class = std::enable_if_t<
                        std::is_convertible<U(*)[], T(*)[]>::value &&
                        (Extent == dynamic_extent || Extent == E)>>
            constexpr span(const span<U, E>& other) noexcept
                : storage_(other.data(), other.size()) {}

            constexpr std::size_t size() const noexcept {
                if constexpr (Extent != dynamic_extent) return Extent;
                return storage_.size();
            }

            constexpr bool empty() const noexcept { return size() == 0; }

            constexpr reference operator[](std::size_t idx) const noexcept {
                assert(idx < size());
                return data()[idx];
            }

            constexpr reference front() const noexcept {
                assert(size() > 0);
                return data()[0];
            }

            constexpr reference back() const noexcept {
                assert(size() > 0);
                return data()[size() - 1];
            }

            constexpr pointer data() const noexcept { return storage_.ptr; }

            constexpr pointer begin() const noexcept { return data(); }
            constexpr pointer end() const noexcept { return data() + size(); }

        private:
            detail::span_storage<T, Extent> storage_;
        };

        // deduction guides
        template <class T, std::size_t N>
        span(T (&)[N]) -> span<T, N>;

        template <class T, std::size_t N>
        span(std::array<T, N>&) -> span<T, N>;

        template <class T, std::size_t N>
        span(const std::array<T, N>&) -> span<const T, N>;

        template <class T>
        span(T*, std::size_t) -> span<T, dynamic_extent>;

    } // namespace covertcalculus::memory
#endif // C++17 fallback
