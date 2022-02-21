#include "point.hpp"
#include <cstdlib>

int main()
{
    Point p0;
    Point p1(3.,4.,5.);
    Point p2({1.,2.,3.});
    Point p3(p2);
    p2 = p1;
    std::cout << "Distance entre " << std::string(p1) 
              << " et " << p3 << " = "
              << dist(p1,p3) << std::endl;
    return EXIT_SUCCESS;
}