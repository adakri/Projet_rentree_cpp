#include <string>

class une_classe
{
private:
	int taille, poids;
	std::string nom;

public:
	une_classe(std::string nom, int taille, int poids);
	int get_taille() const;
};
