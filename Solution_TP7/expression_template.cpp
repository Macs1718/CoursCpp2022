#include <vector>
#include <type_traits>
#include <cstdlib>
#include <iostream>


auto add( double const& x1, double const& x2)
{
    return x1 + x2;
}

auto mul( double const& x1, double const& x2 )
{
    return x1 * x2;
}

template<typename K, typename K1, typename K2, 
         typename Op, typename ... KnOp>
void
evaluer( std::vector<K>& res, 
         K1 const& x1, K2 const& x2, Op op1,
         KnOp... knop)
{
    for (int i = 0; i < res.size(); ++i )
    {
        if constexpr ( std::is_scalar<K1>::value && 
                       std::is_scalar<K2>::value )
        {
            res[i] = op1(x1,x2);
        }
        else if constexpr( std::is_scalar<K1>::value &&
                          !std::is_scalar<K2>::value)
        {
            res[i] = op1(x1,x2[i]);
        }
        else if constexpr(!std::is_scalar<K1>::value &&
                           std::is_scalar<K2>::value)
        {
            res[i] = op1(x1[i],x2);
        }
        else
        {
            res[i] = op1(x1[i],x2[i]);
        }
    }
    if constexpr (sizeof...(KnOp) > 0)
    {
        evaluer(res, res, knop...);
    }
}

std::ostream& operator << ( std::ostream& out,
                            std::vector<double>& u )
{
    out << "< ";
    for (auto const& val : u )
        out << val << " ";
    out << ">";
    return out; 
}

int main()
{
    std::vector<double> u{1.,3.,5.,7.,9.};
    std::vector<double> v{2.,4.,6.,8.,10.};
    std::vector<double> w{-2.,4.,-6.,8.,-10.};

    std::vector<double> res(u.size(),0.);

    evaluer(res, u, v, add, 2, mul, w, add);
    std::cout << "2*(" << u << " + " << v << ") + "
              << w << " = " << res << std::endl;
    return EXIT_SUCCESS;
}