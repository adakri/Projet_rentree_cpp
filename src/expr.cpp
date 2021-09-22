#include "expr.hpp"

#include <algorithm>



Exp_abstract::Exp_abstract(){}

Exp_abstract::~Exp_abstract(){}

Variable::Variable(std::string nom) : Exp_abstract(), _nom(nom)
{
}

std::string Variable::toStringInfixe()
{
    return _nom ;
}

Constante::Constante(double x) : Exp_abstract(), _valeur(x)
{
}

std::string Constante::toStringInfixe()
{
    return std::to_string(_valeur) ;
}


Expr_binaire::Expr_binaire(Exp_abstract* opGauche, Exp_abstract* opDroit) : _opGauche(opGauche), _opDroit(opDroit)
{
}

Expr_binaire::~Expr_binaire()
{
}


BinaireMult::BinaireMult(Exp_abstract* opGauche, Exp_abstract* opDroit) : Expr_binaire(opGauche,opDroit)
{
}


std::string BinaireMult::toStringInfixe()
{
    return  _opGauche-> toStringInfixe() + "*" + _opDroit-> toStringInfixe();
}


BinairePlus::BinairePlus(Exp_abstract* opGauche, Exp_abstract* opDroit) : Expr_binaire(opGauche,opDroit)
{
}

std::string BinairePlus::toStringInfixe()
{
    return  _opGauche-> toStringInfixe() + "+" + _opDroit-> toStringInfixe();
}

