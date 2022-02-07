#include <cmath>
#include "vecteur.hpp"

double dot(std::vector<double> const& u, std::vector<double> const& v, int incu, int incv)
{
    assert(incu > 0);
    assert(incv > 0);
    assert(u.size()*incv == incu*v.size());
    double scal = 0.;
    for (std::size_t i = 0; i < u.size()/incu; ++i )
    {
        scal += u[i*incu]*v[i*incv];
    }
    return scal;
}
//
std::vector<double>& axpy( double alpha, std::vector<double> const& u, std::vector<double>& v,
                           int incu, int incv)
{
    assert(incu > 0);
    assert(incv > 0);
    assert(incv*u.size() == incu*v.size());
    for ( std::size_t i = 0; i < u.size()/incu; ++i)
    {
        v[incv*i] += alpha*u[incu*i];
    }
    return v;
}
//
std::ostream& 
operator <<(std::ostream& out, std::vector<double> const& u )
{
    out << "< ";
    for (auto const& val : u)
        out << val << " ";
    out << ">";
    return out;
}
//
double 
nrmL2(std::vector<double> const& u, int incu)
{
    return std::sqrt(dot(u,u,incu,incu));
}
//
std::vector<double>& 
scal( double alpha, std::vector<double>& u, int incu)
{
    assert(incu > 0);
    for (std::size_t i = 0; i < u.size()/incu; ++i)
    {
        u[i*incu] *= alpha;
    }
    return u;
}
