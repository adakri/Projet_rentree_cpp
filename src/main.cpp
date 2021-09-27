#include <iostream>
#include <cstdlib>

#include "une_fonction.hpp"
#include "une_classe.hpp"
#include "Fraction.hpp"
#include "Matrix.hpp"
#include "expr.hpp"




#include "simulation.hpp"




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
    std::cout << chic.get_taille() << std::endl; 

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
*/


    //test singulier
    Variable* var;
    var = new Variable("x");
    std::cout<<var->toStringInfixe()<<std::endl;

    Exp_abstract* expr;
    expr = new BinaireMult(new BinairePlus(new Variable("x"), new Variable("y")), new Constante(3));

    //test affichage
    std::cout<<expr->toStringInfixe()<<std::endl;

    //test evaluation
    //env* Env;
    env* Env = new env();
    Env->associer("x",4.);
    Env->associer("y",5.);

    std::cout<<expr->evaluer(*Env)<<std::endl;


    //------------------------Boids--------------------------------

    //boids methods testing
    vector p1 = {20., 30.};
    vector v1 = { 5., 7.};

    vector p2 = { 15.,10.};
    vector v2 = { 8., 11.};

    Boid* b = new Boid(p1,v1);

    std::cout<< b->toString() <<std::endl;

    //boids struct methods

    b= new Boid(p1+p2, v1+v2);

    std::cout<<"sum boid \n" << b->toString() <<std::endl;

    Simulation Sim(50,1000,1000);

    //Sim.initialise_positions();

    //std::cout<<"Initialise the boid"<<std::endl;

    //Sim.print_boids();

    //Sim.move_boids_shapes();
   

    //sfml stuff testing
    //Sim.show_boids();
    
    Sim.launch_simulation();


    return EXIT_SUCCESS;
}
