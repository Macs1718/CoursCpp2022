#include "nuage_de_points.hpp"
#include <cstdlib>

int main()
{
    NuageDePoints nuage1(10);
    NuageDePoints nuage2(nuage1);

    return EXIT_SUCCESS;
}