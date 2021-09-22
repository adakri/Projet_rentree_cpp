#include <ostream>
#include <iostream>
#include <string>
#include <vector>


class Exp_abstract
{
    public:
        Exp_abstract();
        virtual ~Exp_abstract();
        virtual std::string toString() = 0;
};

class Variable : public Exp_abstract
{
    private:
        std::string _nom;
    public:
        Variable(std::string);
        std::string toString();
};

class Constante : public Exp_abstract
{
    private:
        double _valeur;
    public:
        Constante(double);
        std::string toString();
};