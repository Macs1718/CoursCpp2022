#ifndef _NUAGE_DE_POINTS_HPP_
#define _NUAGE_DE_POINTS_HPP_
#include <vector>
#include <iostream>
#include "point.hpp"

class NuageDePoints
{
public:
    NuageDePoints()
    {
#       if defined(TRACE)
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#       endif
    }

    NuageDePoints( std::size_t t_nombre_de_points )
        : m_points(t_nombre_de_points)
    {
#       if defined(TRACE)
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#       endif
    }

    NuageDePoints( NuageDePoints const& nuage )
        :   m_points(nuage.m_points)
    {
#       if defined(TRACE)        
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#       endif
    }

    NuageDePoints( std::size_t debut, std::size_t fin, NuageDePoints const& nuage )
        :   m_points(nuage.m_points.begin()+debut, nuage.m_points.begin()+fin)
    {
        assert(fin>debut);
        assert(fin < nuage.size());
#       if defined(TRACE)        
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#       endif
    }

    std::size_t size() const
    {
        return this->m_points.size();
    }

private:
    std::vector<Point> m_points;
};

#endif