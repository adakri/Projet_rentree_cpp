#include <ostream>
#include <iostream>
#include <string>
#include <vector>


#include "env.hpp"


class Exp_abstract
{
    public:
        Exp_abstract();
        virtual ~Exp_abstract();
        virtual std::string toStringInfixe() = 0;
        virtual double evaluer(env) = 0;
};

class Variable : public Exp_abstract
{
    private:
        std::string _nom;
    public:
        Variable(std::string);
        std::string toStringInfixe();
        double evaluer(env);

        std::string get_variable() const {return _nom;};
};

class Constante : public Exp_abstract
{
    private:
        double _valeur;
    public:
        Constante(double);
        std::string toStringInfixe();
        double evaluer(env);
        double get_constante() const {return _valeur;};
};

class Expr_binaire : public Exp_abstract
{
    protected:
        Exp_abstract* _opGauche;
        Exp_abstract* _opDroit;
    public:
        Expr_binaire(Exp_abstract*, Exp_abstract*);
        virtual ~Expr_binaire();
};

class BinaireMult : public Expr_binaire
{
    public:
        BinaireMult(Exp_abstract*,Exp_abstract*);
        std::string toStringInfixe();
        double evaluer(env);
};

class BinairePlus : public Expr_binaire
{
    public:
        BinairePlus(Exp_abstract*,Exp_abstract*);
        std::string toStringInfixe();
        double evaluer(env);

};