#include <iostream>
#include <cstdlib>

class Fraction
{
    private:
        double _numerator,_denominator;
    
    
    public:
        Fraction(double numerator, double denominator);
        //~Fraction();
        void toString();
        bool operator== (const Fraction&);
        bool operator!= (const Fraction&);
        Fraction& operator+=(const Fraction&);
        Fraction& operator-=(const Fraction&);
        Fraction& operator=(const Fraction&);

        //getters and setters
        const double get_numerator() const {return this->_numerator;};
        const double get_denominator() const {return this->_denominator;}
        

};

std::ofstream& operator<<(std::ofstream& ,const Fraction& );



