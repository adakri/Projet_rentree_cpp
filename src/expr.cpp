#include "expr.hpp"

#include <algorithm>



Exp_abstract::Exp_abstract(){}

Exp_abstract::~Exp_abstract(){}

Variable::Variable(std::string nom) : Exp_abstract(), _nom(nom)
{
}

std::string Variable::toString()
{
    return " Une variable de nom/ " + _nom ;
}

Constante::Constante(double x) : Exp_abstract(), _valeur(x)
{
}

std::string Constante::toString()
{
    
}


