#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_
#include <cassert>
#include <vector>
#include <iostream>

double dot(std::vector<double> const& u, std::vector<double> const& v, int incu=1, int incv=1);
std::vector<double>& axpy( double alpha, std::vector<double> const& u, std::vector<double>& v,
                           int incu=1, int incv=1);
std::ostream& operator <<(std::ostream& out, std::vector<double> const& u );
double nrmL2(std::vector<double> const& u, int incu = 1);
std::vector<double>& scal( double alpha, std::vector<double>& u, int incu=1);
#endif