#include <complex>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std::complex_literals;

std::vector<std::complex<double>>
racine_nieme( std::complex<double> const& z, int n)
{
    constexpr double two_pi{6.283185307179586};
    assert(n>0);
    double zmod = std::abs(z);
    double arg  = std::arg(z);

    double znmod = std::pow(zmod, 1./n);
    double znarg = arg/n;

    std::vector<std::complex<double>> racines;
    racines.reserve(n);
    for (int i = 0; i < n; ++i )
    {
        racines.emplace_back(znmod*
                            std::exp(1.i*(znarg+i*two_pi/n)));
    }
    return racines;
}

int main(int nargs, char* argv[])
{
    int n =3;
    std::complex<double> z{1.,1.};
    if (nargs >= 4)
    {
        double re = std::stod(argv[1]);
        double im = std::stod(argv[2]);
        n = std::stoi(argv[3]);
        z = std::complex<double>(re,im);
    }
    auto racines = racine_nieme(z, n);

    for (auto rz : racines)
        std::cout << rz << "\t";
    std::cout << std::endl;    
    return EXIT_SUCCESS;
}