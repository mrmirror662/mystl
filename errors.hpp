#pragma once
#include "types.hpp"
namespace mtd
{
    // Error handling for out of bounds access in array
    class exception
    {
    public:
        exception(const char *message) : m_message(message) {}
        const char *what() const noexcept { return m_message; }

    private:
        const char *m_message;
    };
} // namespace mtd