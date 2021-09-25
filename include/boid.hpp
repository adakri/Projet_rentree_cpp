#include <algorithm>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h> 



struct vector{
    double _x,_y;
    vector operator+(const vector& v)
    {
        return {v._x + this->_x, v._y + this->_y};
    };
    vector operator-(const vector& v)
    {
        return {v._x - this->_x, v._y - this->_y};
    };
};



class Boid
{
    private:
        vector _position,_velocity;
    public:
        Boid(vector, vector);
        ~Boid();
        std::string toString();
        static double compute_distance(Boid, Boid);

        void update_velocity(vector);
        void update_position(vector);

        //getters
        vector get_position() const {return _position;};
        vector get_velocity() const {return _velocity;};
};