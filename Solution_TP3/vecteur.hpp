#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_
#include <array>
#include <cmath>
#include <cassert>

class Vecteur
{
public:
    Vecteur(double x, double y, double z);
    Vecteur( std::initializer_list<double> const& values )
    {
        auto iter = values.begin();
        m_coefs[0] = *iter; ++iter;
        m_coefs[1] = *iter; ++iter;
        m_coefs[2] = *iter;
    }

    double& operator[](int i) // u[2] = 3;
    {
        assert(i>=0); assert(i<3);
        return m_coefs[i];
    }

    double const& operator[](int i) const // auto a =u[1]
    {
        assert(i>=0); assert(i<3);
        return m_coefs[i];
    }

    Vecteur operator + ( Vecteur const& u ) const
    {
        return {m_coefs[0]+u.m_coefs[0],
                m_coefs[1]+u.m_coefs[1],
                m_coefs[2]+u.m_coefs[2]};
    }
private:
    std::array<double,3> m_coefs;
};

#endif