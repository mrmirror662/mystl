#pragma once
#include "types.hpp"

namespace mtd
{
    template <typename T>
    class initializer_list
    {
    private:
        const T *_begin;
        mtd::size_t _size;

    public:
        constexpr initializer_list(const T *begin, mtd::size_t size)
            : _begin(begin), _size(size) {}

        constexpr const T *begin() const noexcept { return _begin; }
        constexpr const T *end() const noexcept { return _begin + _size; }
        constexpr std::size_t size() const noexcept { return _size; }
    };
}
