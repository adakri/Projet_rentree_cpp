#include "Fraction.hpp"
#include <algorithm>


Fraction::Fraction(int numerator, int denominator) : 
_numerator(numerator), _denominator(denominator)
{
}


std::string Fraction::toString()
{
    //add memory adress and object type
    std::string str = std::to_string(this->_numerator) + " / " + std::to_string(this->_denominator);
    std::cout<<std::to_string(this->_numerator) + " / " + std::to_string(this->_denominator);
    return str;
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


//Fix this crap, it either works or doesn't
std::ofstream& operator<<(std::ofstream& out ,const Fraction& f1)
{
    //out << "h";
    //out<< "/" <<f1.get_numerator();
    return out;
}




//------------------------------------------------------------------------------

Reduced_Fraction::Reduced_Fraction(int numerator, int denominator) : _reduced_denominator(denominator), _reduced_numerator(numerator)
{
    //std::cout<<"*"<<std::__gcd(numerator,denominator)<<std::endl;
    if(std::__gcd(numerator,denominator)  == 1. )
    {
        _reduced_numerator = numerator;
        _reduced_denominator = denominator;
    }else{
        _reduced_denominator = denominator / std::__gcd(numerator,denominator);
        _reduced_numerator = numerator / std::__gcd(numerator,denominator);
    }
    //std::cout<<_reduced_numerator<<std::endl;

}
