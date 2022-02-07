#include <cstdlib>
#include <list>
#include <string>
#include <iostream>

int main(int nargs, char* argv[])
{
    int n = 100;
    if (nargs > 1)
    {
        n = std::stoi(argv[1]);
    }
    std::list<int> premiers;
    for (int i = 0; i < n-1; ++i)
    {
        premiers.emplace_back(i+2);
    }

    auto iter = premiers.begin();
    while ((*iter)*(*iter) <= n)
    {
        premiers.remove_if([iter](int n){ return ( (n%(*iter) == 0) && ((*iter) != n)); });
        ++iter;
    }

    for (auto l : premiers)
    {
        std::cout << l << " ";
    }
    std::cout << std::endl << std::flush;
    return EXIT_SUCCESS;
}