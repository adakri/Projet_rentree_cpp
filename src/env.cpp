#include "env.hpp"



env::env(){}

env::~env(){}

void env::associer(std::string nom, double valeur)
{
    if (_m.find(nom) != _m.end())
    {
        std::cout << "map contains key !\n";
    }
    _m[nom]=valeur;
}


double env::obtenirValeur(std::string nom)
{
    double value = _m.at(nom);
    //assert(value != _m.end());
    return value;
}

std::string env::toStringInfixe()
{
    std::string str;
    std::map<std::string, double>::iterator it = _m.begin();
    while(it != _m.end())
    {
        str += it->first + " :: " +  std::to_string(it->second);
        it++;
    }
    return str;
}