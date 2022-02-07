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
    std::vector<std::vector<int>> binome(deg);
    binome[0] = std::vector({1,1});
    for (int i = 1; i < deg; ++i )
    {
        std::vector<int>(binome[i-1].size()+1).swap(binome[i]);
        binome[i][0] = 1;
        for (int j = 1; j < binome[i].size()-1; ++j )
            binome[i][j] = binome[i-1][j-1] + binome[i-1][j];
        binome[i].back() = 1;
    }

    std::vector<int>& polynome = binome.back();
    std::cout << "Developpement du binome : ";
    std::cout << polynome[0] << "x^" << deg;
    for ( int i = 1; i < polynome.size()-1; ++i )
    {
        std::cout << " + " << polynome[i] << ".x^" << deg-i << ".y^" << i;
    }
    std::cout << " + " << polynome.back() << "y^" << deg << std::endl;
    return EXIT_SUCCESS;
}