#include <cstdlib>
#include <memory>
#include <iostream>
#include <random>

struct binary_tree
{
    int value;
    std::shared_ptr<binary_tree> left = nullptr, right = nullptr;// CEla permet que lorsqu'on crée une variable de ce type, les pointeurs sont automatiquement nuls
};

std::shared_ptr<binary_tree> inserer_valeur( std::shared_ptr<binary_tree>& arbre, int valeur )
{
    if (not arbre)
    {
        arbre = std::make_shared<binary_tree>();
        arbre->value = valeur;
        return arbre;
    }
    if (valeur < arbre->value)
    {
        if (arbre->left == nullptr)
        {
            arbre->left = std::make_shared<binary_tree>();
            arbre->left->value = valeur;
        }
        else
        {
            inserer_valeur(arbre->left, valeur);
        }
    }
    else
    {
        if (arbre->right == nullptr)
        {
            arbre->right = std::make_shared<binary_tree>();
            arbre->right->value = valeur;
        }
        else
        {
            inserer_valeur(arbre->right, valeur);
        }
    }
    return arbre;
}

void affiche(std::shared_ptr<binary_tree> const& arbre)
{
    if (not arbre) return;
    affiche(arbre->left);
    std::cout << arbre->value << " ";
    affiche(arbre->right);
}


int main(int nargs, char* argv[])
{
    int n;
    if (nargs < 2)
    {
        std::cout << "Usage : exercice4.exe <nombre d'entiers a generer>" << std::endl << std::flush;
        return EXIT_FAILURE;
    }
    n = std::stoi(argv[1]);
    std::shared_ptr<binary_tree> arbre = nullptr;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100000);

    for (int i=0; i<n; ++i)
    {
        arbre = inserer_valeur(arbre, distribution(generator));
    }

    affiche(arbre);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}