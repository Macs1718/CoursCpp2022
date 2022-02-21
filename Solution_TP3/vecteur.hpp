#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_
#include <array>
#include <cmath>
#include <cassert>
#include "point.hpp"

class Vecteur
{
public:
    Vecteur(double x, double y, double z)
        :   m_coefs{x,y,z}
    {}

    Vecteur( std::initializer_list<double> const& values )
    {
        auto iter = values.begin();
        m_coefs[0] = *iter; ++iter;
        m_coefs[1] = *iter; ++iter; 
        m_coefs[2] = *iter;
    }
    Vecteur( Point const& p1, Point const& p2 )
        :   m_coefs{p2.x-p1.x, p2.y-p1.y, p2.z-p1.z}
    {}

    Vecteur ( Vecteur const& ) = default;
    Vecteur ( Vecteur     && ) = delete;
    ~Vecteur() = default;

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

    double operator | ( const Vecteur& v ) const;

    Vecteur operator ^ ( const Vecteur & v ) const;

    Point translate( Point const& p ) const 
    {
        return { p.x + m_coefs[0],
                 p.y + m_coefs[1],
                 p.z + m_coefs[2] };
    }

    operator std::string() const 
    {
        return std::string("<") + std::to_string(m_coefs[0]) + ", "
                                + std::to_string(m_coefs[1]) + ", "
                                + std::to_string(m_coefs[2]) + ">";
    }

private:
    std::array<double,3> m_coefs;
};

inline Vecteur operator * ( double alpha, Vecteur const& u )
{
    return { alpha*u[0], alpha*u[1], alpha*u[2] };
}

#endif