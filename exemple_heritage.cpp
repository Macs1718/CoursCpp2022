#include <iostream>
#include <cstring>

class Quadrilatere
{
public:
    Quadrilatere() = default;
    Quadrilatere( Quadrilatere const& ) = default;
    virtual ~Quadrilatere() = default;

    virtual double calculAire() const = 0;
};

class Carre : public Quadrilatere
{
public:
    Carre( double length )
        :   m_length(length)
    {}
    Carre( Carre const& ) = default;
    virtual ~Carre() = default;

    Carre& operator = ( const Carre& c ) = default;

    virtual double calculAire() const override 
    {
        return m_length*m_length;
    }
private:
    double m_length;
};

class Rectangle : public Quadrilatere 
{
public:
    Rectangle( double largeur, double longueur )
        :   m_largeur(largeur),
            m_longueur(longueur)
    {}
    Rectangle( Rectangle const& ) = default;
    virtual ~Rectangle() = default;

    virtual double calculAire() const override
    {
        return m_largeur*m_longueur;
    }
private:
    double m_largeur, m_longueur;
};

int main()
{
    Carre carre(10);
    Rectangle rectangle(10,20);

    std::cout << "Aire carre : " << carre.calculAire() << " et aire rectangle :"
              << rectangle.calculAire() << std::endl;
    return EXIT_SUCCESS;
}