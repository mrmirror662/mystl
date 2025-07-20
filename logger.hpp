#pragma once

#include <iostream>
class FakeStream
{
public:
    template <typename T>
    FakeStream &operator<<(const T &)
    {
        // Do nothing
        return *this;
    }
    FakeStream &operator<<(std::ostream &(&manip)(std::ostream &))
    {
        // Do nothing
        return *this;
    }
};
auto &outStream = std::cout;
auto nullStream = FakeStream();
#ifdef NDEBUG
#define debug outStream << "[DEBUG] "
#else
#define debug nullStream
#endif
#define error outStream << "[ERROR] "