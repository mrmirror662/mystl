#pragma once
#include "logger.hpp"
#include "concepts.hpp"
#include "types.hpp"
#include "initializer_list.hpp"
#include "errors.hpp"
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
        // write a initializer list constructor
        array() = default;
        array(const mtd::initializer_list<T> &list)
            : m_size(list.size())
        {
            if (m_size > N)
            {
                error << "Initializer list size exceeds array size";
                throw mtd::exception("Initializer list size exceeds array size");
            }
            mtd::size_t i = 0;
            for (const auto &item : list)
            {
                m_data[i++] = item;
            }
        }
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
        struct Iterator
        {
            T *ptr;
            Iterator(T *p) : ptr(p) {}
            T *operator*() const
            {
                return *this->ptr;
            }
            Iterator &operator++()
            {
                ++ptr;
                return *this;
            }
            bool operator!=(const Iterator &other) const
            {
                return ptr != other.ptr;
            }
        };
        Iterator begin()
        {
            return Iterator(m_data);
        }
        Iterator end()
        {
            return Iterator(m_data + m_size);
        }

    private:
    };
} // namespace mtd
