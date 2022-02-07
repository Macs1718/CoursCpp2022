#include "vecteur.hpp"
using Vecteur=std::vector<double>;

inline void gram_schmidt( std::vector<Vecteur>& famille )
{
    assert(famille.size() <= famille[0].size());
    for (int i = 0; i < famille.size(); ++i)
    {
        for (int j = 0; j < i; ++j )
        {
            axpy(-dot(famille[i],famille[j]),famille[j],famille[i]);
        }
        famille[i] = scal(1./nrmL2(famille[i]),famille[i]);        
    }
}

int main()
{
    std::vector famille{ std::vector{1.,1.,1.},
                                    {0.,1.,1.},
                                    {0.,0.,1.}};
    gram_schmidt(famille);
    std::cout << "Famille orthonormalisee :";
    for ( auto const& f : famille )
    {
        std::cout << f << std::endl;
    }
    std::cout << "Verification : ";
    for (int i = 0; i < famille.size(); ++i )
    {
        for (int j = 0; j <= i; ++j )
        {
            std::cout << "(f[" << i << "]|f[" << j << "]) = "
                      << dot(famille[i],famille[j]) << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
