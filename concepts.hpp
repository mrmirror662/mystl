#pragma once
#include "types.hpp"
#include "common.hpp"
namespace mtd
{
    template <typename From, typename To>
    concept convertible_to = requires(From a) {
        { static_cast<To>(a) };
    };
    template <typename T>
    concept Integral = requires(T a) {
        { a + a } -> convertible_to<T>;
        { a - a } -> convertible_to<T>;
        { a * a } -> convertible_to<T>;
        { a / a } -> convertible_to<T>;
        { a % a } -> convertible_to<T>;
    };
    template <typename T>
    concept FloatingPoint = requires(T a) {
        { a + a } -> convertible_to<T>;
        { a - a } -> convertible_to<T>;
        { a * a } -> convertible_to<T>;
        { a / a } -> convertible_to<T>;
    };
    template <typename T>
    concept Arithmetic = Integral<T> || FloatingPoint<T>;
    template <typename T>
    concept container = requires(T a) {
        { a.begin() } -> convertible_to<typename T::iterator>;
        { a.end() } -> convertible_to<typename T::iterator>;
        { a.size() } -> convertible_to<size_t>;
        { a.empty() } -> convertible_to<bool>;
    } && requires {
        T{};
        T{T{}};
        T{move(T{})};
    };
    template <typename T>
    struct is_cstring_impl
    {
        static constexpr bool value = false;
    };

    template <>
    struct is_cstring_impl<const char *>
    {
        static constexpr bool value = true;
    };

    template <typename T>
    concept is_cstring = is_cstring_impl<T>::value;

    template <typename T>
    concept Primitive = Integral<T> || FloatingPoint<T> || is_cstring<T>;
}
