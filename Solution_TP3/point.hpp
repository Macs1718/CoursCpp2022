#ifndef _Point_HPP_
#define _Point_HPP_
#include <string>
#include <cmath>
#include <iostream>

struct Point
{
    Point() = default;
    Point( double t_x, double t_y, double t_z )
        :   x(t_x),
            y(t_y),
            z(t_z)
    {}
    Point( std::initializer_list<double> const& values )
    {
        auto iter = values.begin();
        x = *iter; ++iter;
        y = *iter; ++iter;
        z = *iter;
    }


    Point( Point const& ) = default;
    Point( Point     && ) = delete;
    ~Point()                = default;

    Point& operator = ( Point const& ) = default;
    Point& operator = ( Point     && ) = delete;

    operator std::string() const
    {
        return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    std::ostream& print(std::ostream& out) const
    {
        out << x << " " << y << " " << z;
        return out;
    }
    double x,y,z;
};

inline std::ostream& 
operator << ( std::ostream& out, Point const& p)
{
    return p.print(out);
}

inline double dist( Point const& p1, Point const& p2 )
{
    double dx = p2.x - p1.x, dy = p2.y - p1.y, dz = p2.z - p1.z;
    return std::sqrt(dx*dx+dy*dy+dz*dz);
}
#endif