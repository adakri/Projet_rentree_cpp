#include <ostream>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>


class env
{
    private:
        std::map<std::string, double> _m; //normally maps do not need to be initialized, here's hoping.
    public:
        env();
        ~env();
        void associer(std::string, double);
        double obtenirValeur(std::string);
        std::string toStringInfixe();
};