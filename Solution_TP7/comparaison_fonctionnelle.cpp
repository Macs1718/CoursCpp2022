#include <cmath>
#include <cstdlib>
#include <iostream>

struct Cospn
{
    Cospn( double lambda ) : m_lambda{lambda}
    {}

    double operator () ( double x )
    {
        return std::cos(x) + m_lambda;
    }
private:
    double m_lambda;
};

double dsin(double x)
{
    return std::sin(x);
}


template<typename F1, typename K1, typename F2, typename K2, typename ... FKn>
bool compare( F1 f1, K1 x1, F2 f2, K2 x2, FKn... fkn)
{
    if constexpr (sizeof...(fkn) == 0)
    {
        return ( f1(x1) == f2(x2) );
    }
    else 
    {
        return ( f1(x1) == f2(x2) ) && compare(fkn...);
    }
}

int main()
{
    constexpr double pi = 3.141592653589793;
    Cospn func(1.);
    std::cout << "Comparaison..." << std::endl << std::flush;
    bool is_equals = compare( dsin, 0, func, pi, 
                              [] (int x) { return x*x-1; }, 3,
                              [] (float x) { return x*x*x; }, 2 );
    
    std::cout << "Fin Comparaison..." << std::endl << std::flush;
    std::cout << std::boolalpha << "Equals ? " << is_equals << std::endl;
    return EXIT_SUCCESS;
}