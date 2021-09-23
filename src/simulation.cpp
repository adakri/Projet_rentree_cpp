#include "simulation.hpp"

Simulation::Simulation(int n) : _N(n)
{
    _boids = new std::vector<Boid>;
}

Simulation::~Simulation()
{
    delete _boids;
}

void Simulation::initialise_positions()
{

}

void Simulation::move_all_boids_to_new_positions()
{

}

vector Simulation::rule1(Boid* b)
{
    vector perceived_center = {0.,0.};

    //Better mapping to exclude the boid
    /*
    for (int i=0; i<_N; i++)
    {
        perceived_center = perceived_center + 
    }
    */
}


vector Simulation::rule2(Boid* b)
{

}


vector Simulation::rule3(Boid* b)
{

}

//SFML stuff


void Simulation::draw_boids()
{

}