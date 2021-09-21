#include "une_classe.hpp"


une_classe::une_classe(std::string nom, int taille, int poids)
	: taille(taille), nom(nom)
{
	this->poids = poids;
}

int une_classe::get_taille() const
{
	return taille;
}
