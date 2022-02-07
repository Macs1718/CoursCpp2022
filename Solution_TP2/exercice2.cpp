#include <vector>
#include "vecteur.hpp"

int main()
{
    std::vector u{1.,2.,3.,4.};
    std::vector v{5.,6.,2.,1.};

    axpy(-2.,u,v);
    std::cout << v << std::endl;

    std::cout << "(u|v) = " << dot(u,v) << std::endl;

    return EXIT_SUCCESS;
}