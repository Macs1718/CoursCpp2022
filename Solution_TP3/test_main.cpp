#include "point.hpp"
#include "vecteur.hpp"

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

    Vecteur u{1.,0.,-1.};
    std::cout << "u : " << std::string(u) << std::endl;
    Vecteur v{2.,2.,0.};
    std::cout << "v : " << std::string(v) << std::endl;
    std::cout << "u+v : " << std::string(u+v) << std::endl;
    std::cout << "u^v : " << std::string(u^v) << std::endl;
    std::cout << "<u|v> = " << (u|v) << std::endl;
    std::cout << "2.u : " << std::string(2.*u) << std::endl;
    std::cout << "translation de p1 par u : " << std::string(u.translate(p1)) << std::endl;
    return EXIT_SUCCESS;
}