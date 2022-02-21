#include "vecteur.hpp"

double
Vecteur::operator | ( Vecteur const& u ) const 
{
    return this->m_coefs[0]*u[0]+this->m_coefs[1]*u[1]+this->m_coefs[2]*u[2];
}

Vecteur 
Vecteur::operator ^ ( Vecteur const& v ) const
{
    // On prend en référence constante le pointeur sur l'objet ayant appelé l'opérateur
    Vecteur const& u = *this;
    return { u[1]*v[2]-v[1]*u[2], 
             u[2]*v[0]-v[2]*u[0],
             u[0]*v[1]-v[0]*u[1] };
}
