#pragma once
#include "logger.hpp"
#include "concepts.hpp"
#include "types.hpp"

namespace mtd
{
    template <typename T, size_t N>
    class array
    {
    public:
    private:
        T m_data[N];
        mtd::size_t m_size = N;

    public:
        mtd::size_t size() const noexcept
        {
            return m_size;
        }
        bool empty() const noexcept
        {
            return m_size == 0;
        }
        T &operator[](mtd::size_t index)
        {
#ifdef NDEBUG
            if (index >= m_size)
            {
                error << "Index out of bounds: " << index << " for array of size " << m_size;
                throw mtd::exception("Index out of bounds");
            }
#endif
            return m_data[index];
        }

    private:
    };
} // namespace mtd
