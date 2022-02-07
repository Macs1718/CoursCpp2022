#include <vector>
#include <iostream>

int main(int nargs, char* argv[])
{
    int deg;
    if (nargs < 2)
    {
        std::cout << "Usage : ./exercice3.exe <degree demande>" << std::endl;
        return EXIT_FAILURE;
    }
    deg = std::stoi(argv[1]);
    std::vector<int> p_new = std::vector({1,1});
    std::vector<int> p_old;
    for (int i = 1; i < deg; ++i )
    {
        p_old.swap(p_new);
        std::vector<int>(p_old.size()+1).swap(p_new);
        p_new.front() = 1;
        for (int j = 1; j < p_new.size()-1; ++j )
            p_new[j] = p_old[j-1] + p_old[j];
        p_new.back() = 1;
    }

    std::cout << "Developpement du binome : ";
    std::cout << p_new[0] << "x^" << deg;
    for ( int i = 1; i < p_new.size()-1; ++i )
    {
        std::cout << " + " << p_new[i] << ".x^" << deg-i << ".y^" << i;
    }
    std::cout << " + " << p_new.back() << "y^" << deg << std::endl;
    return EXIT_SUCCESS;
}