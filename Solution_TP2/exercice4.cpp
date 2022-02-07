#include <iostream>
auto moyenne( auto const& x, auto const& y )
{
    return decltype(x)((x+y)/2);
}

int main()
{
    std::cout << "Moyenne de 2 et 3 (entiers) : "
              << moyenne(2,3) << std::endl;
    std::cout << "Moyenne de 2. et 3. (reels) : "
              << moyenne(2.,3.) << std::endl;
    return EXIT_SUCCESS;
}