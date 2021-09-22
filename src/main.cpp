#include <iostream>
#include <cstdlib>

#include "une_fonction.hpp"
#include "une_classe.hpp"
#include "Fraction.hpp"
#include "Matrix.hpp"



#define debug std::cout<<"debug"<<std::endl;

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

    Fraction f1(2,3), f2(4,2);
    //f2.toString();
    //std::cout<< (f1 == f1) <<std::endl;
    f1+=f1;
    f1.toString();
    debug
    std::cout<<"test for denominator get "<<f1.get_denominator()<<std::endl;;
    //std::cout<<f1;

    Reduced_Fraction f3(4,2);
    std::cout<<"Reduced Fraction "<<f3.get_numerator()<<"/"<<f3.get_denominator()<<std::endl;

    Matrix<int> mat1(5,5), mat2(5,5);

    mat1.assign(2,5);
    mat2.assign(8,7);

    mat1.print_mat();

    mat1 += mat2;

    mat1.print_mat();

    return EXIT_SUCCESS;
}
