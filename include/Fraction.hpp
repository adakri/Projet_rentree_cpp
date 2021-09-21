#include <ostream>
#include <iostream>
#include <string>




class Fraction
{
    private:

    protected:
        int _numerator,_denominator;
    
    
    public:
        Fraction(int numerator, int denominator);
        Fraction(){};
        virtual ~Fraction(){};
        std::string toString();
        bool operator== (const Fraction&);
        bool operator!= (const Fraction&);
        Fraction& operator+=(const Fraction&);
        Fraction& operator-=(const Fraction&);
        Fraction& operator=(const Fraction&);
        friend std::ofstream& operator<<(std::ofstream& ,const Fraction& );


        //getters and setters
        virtual int get_numerator() const {return _numerator;};
        virtual int get_denominator() const {return _denominator;};
        

};


class Reduced_Fraction : public Fraction
{
    private:
        int _reduced_numerator, _reduced_denominator;
    public:
        Reduced_Fraction(int, int);
        virtual ~Reduced_Fraction(){};
        int get_numerator() const {return _reduced_numerator;};
        int get_denominator() const {return _reduced_denominator;};

};





