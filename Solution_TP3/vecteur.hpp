#ifndef _Point_HPP_
#define _Point_HPP_
#include <string>

struct Point
{
    Point() = default;
    
    Point( Point const& ) = default;
    Point( Point     && ) = delete;
    ~Point()                = default;

    Point& operator = ( Point const& ) = default;
    Point& operator = ( Point     && ) = delete;

    operator std::string() const
    {
        return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
    double x,y,z;
};
#endif