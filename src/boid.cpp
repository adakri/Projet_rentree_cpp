#include "boid.hpp"


Boid::Boid(vector pos, vector v) 
{
    _position._x = pos._x;
    _position._y = pos._y;
    _velocity._x = v._x;
    _velocity._y = v._y;
}

Boid::~Boid(){}

std::string Boid::toString()
{
    return "Boid: \n position:" +  std::to_string( _position._x) + "," + std::to_string( _position._y) + " \n velocity: " 
        + std::to_string(_velocity._x) + "," + std::to_string(_velocity._y);
}



