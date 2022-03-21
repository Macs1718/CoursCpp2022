#include <cstdlib>
#include <iostream>
#include <cmath>

double sqsin( double x )
{
    double z = std::sin(x);
    return z*z;
}


template<typename F1, typename... Fn>
double evaluerComposition( double x, F1 f1, Fn... fn)
{
    if constexpr (sizeof...(fn) == 1)
    {
        return f1(fn(x)...);
    }
    else
    {
        return f1(evaluerComposition(x, fn...));
    }
}

int main()
{
    constexpr double val = 2.141592653589793;
    // Evalue sqrt(1-sqsin(val+1) = sqrt(1-sin²(val+1)) = |cos(val+1)|
    double y = evaluerComposition( val, 
                                   [](double x) { return std::sqrt(1-x); }, 
                                   sqsin,
                                   [](double x) { return x+1; } );
    std::cout << "y = " << y << std::endl;
    return EXIT_SUCCESS;
}
