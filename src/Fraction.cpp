#include "Fraction.hpp"


Fraction::Fraction(double numerator, double denominator) : 
_numerator(numerator), _denominator(denominator)
{
}

void Fraction::toString()
{
    //add memory adress and object type
    std::cout<<this->_numerator<<" / "<<this->_denominator<<std::endl;    
}


bool Fraction::operator==(const Fraction& f1)
{
    return f1._numerator == this->_numerator && f1._denominator == this->_denominator;
}


bool Fraction::operator!=(const Fraction& f1)
{
    return f1._numerator != this->_numerator || f1._denominator != this->_denominator;
}

Fraction& Fraction::operator+=(const Fraction& f1)
{
    this->_numerator += f1._numerator;
    this->_denominator += f1._denominator;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& f1)
{
    this->_numerator -= f1._numerator;
    this->_denominator -= f1._denominator;
    return *this;
}

Fraction& Fraction::operator=(const Fraction& f1)
{
    this->_numerator = f1._numerator;
    this->_denominator = f1._denominator;
    return *this;
}

std::ofstream& operator<<(std::ofstream& os ,const Fraction& f1)
{
    //os << f1.get_numerator();
    return os;
}
