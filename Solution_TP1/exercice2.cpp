#include <cstdlib>
#include <ostream>
#include <string>
#include <iostream>
#include <cctype>


int main()
{
    std::string phrase;
    std::cout << "Rentrez une phrase sans espace : " << std::flush;
    std::cin >> phrase;

    int cpteur_lettre = 0, cpteur_numero = 0, cpteur_autre = 0;
    for (auto c : phrase )
    {
        if (std::isalpha(c))
        {
            cpteur_lettre++;
        }
        else if (std::isalnum(c))
        {
            cpteur_numero++;
        }
        else
        {
            cpteur_autre ++;
        }
    }
    std::cout << "Votre phrase contient : " << std::endl
              << "\t" << cpteur_lettre << " lettres." << std::endl
              << "\t" << cpteur_numero << " chiffres." << std::endl 
              << "\t" << cpteur_autre << " autres caracteres." << std::endl;
    return EXIT_SUCCESS;
}