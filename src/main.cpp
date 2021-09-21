#include <iostream>
#include <cstdlib>

#include "une_fonction.hpp"
#include "une_classe.hpp"
#include "Fraction.hpp"


int main(int, char**)
{

/*
    int a = 1, b = 1, c = 1;
    std::cout << "Avant: " << a << ", " << b << ", " << c << std::endl;

    incremente(a, b, &c);
    std::cout << "Apres: " << a << ", " << b << ", " << c << std::endl;

    std::cout << "Vous devriez aimer le passage par reference... " << std::endl;


    une_classe chic("toto", 175, 80);
    std::cout << chic.get_taille() << std::endl; */

    Fraction f1(2.,3.), f2(4.,5.);
    //f2.toString();
    //std::cout<< (f1 == f1) <<std::endl;
    f1+=f1;
    f1.toString();
    //std::cout<<f1;

    return EXIT_SUCCESS;
}
