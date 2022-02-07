#include <iostream>

int main()
{
    for ( int v : {1,5,7,11,13,17,19})
        std::cout << v << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}