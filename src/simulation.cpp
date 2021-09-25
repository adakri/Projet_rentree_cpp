#include "simulation.hpp"

Simulation::Simulation(int n) : _N(n)
{
    //_boids = new std::vector<Boid>;
    _boids.resize(_N);
    //_window = new QWidget;
}

Simulation::~Simulation()
{
    //delete _boids;
}

void Simulation::initialise_positions()
{
    //for now the frame in a 100
    double random_posx,random_posy,random_velocityx,random_velocityy;
    vector pos,vel;

    for (int i=0; i<_N;i++)
    {
        srand (time(NULL));
        random_posx = ( (double)rand() / RAND_MAX ) *99. + 1.;
        random_posy = ( (double)rand() / RAND_MAX ) *99. + 1.;
        random_velocityx = ( (double)rand() / RAND_MAX ) *99. + 1.;
        random_velocityy = ( (double)rand() / RAND_MAX ) *99. + 1.;
        pos = {random_posx,random_posy};
        vel = {random_velocityx,random_velocityy};
        
        _boids[i] = new Boid(pos,vel);
    }

}



vector Simulation::rule1(Boid* b)
{
    vector perceived_center = {0.,0.};

    //Better mapping to exclude the boid
    for (int i=0; i<_N; i++)
    {
        perceived_center = perceived_center + _boids[i]->get_position(); 
    }
    perceived_center = perceived_center - b->get_position();
    perceived_center._x /= double(_N-1);
    perceived_center._y /= double(_N-1);
    
    
    perceived_center = perceived_center - b->get_position();

    perceived_center._x /= 100.;
    perceived_center._y /= 100.;


    return perceived_center; 
}


vector Simulation::rule2(Boid* b)
{
    vector c= {0.,0.};
    for (int i=0; i<_N; i++)
    {
        //the added boid in the loop does nothing, too lazt to map it or index it?
        double distance = Boid::compute_distance(*b, *_boids[i]);
        if (distance < 10.)
        {
            c = c + (b->get_position() - _boids[i]->get_position() ); 
        }
    }
    return c;
}


vector Simulation::rule3(Boid* b)
{
    vector pvj = {0.,0.};
    for (int i=0; i<_N; i++)
    {
        pvj = pvj + _boids[i]->get_velocity(); 
    }
    pvj = pvj - b->get_position();
    pvj._x /= double(_N-1);
    pvj._y /= double(_N-1);

    pvj = pvj - b->get_position();

    pvj._x /= 8.;
    pvj._y /= 8.;

    return pvj;
    
}



void Simulation::move_all_boids_to_new_positions()
{
    vector v1,v2,v3;

    for(int i=0; i<_N; i++)
    {
        v1 = rule1(_boids[i]);
        v2 = rule2(_boids[i]);
        v3 = rule3(_boids[i]);

        _boids[i]-> update_velocity(v1+v2+v3);
        _boids[i]-> update_position(_boids[i]->get_velocity());
    }
}


void Simulation::print_boids()
{
    for(int i=0; i<_N; i++)
    {
        std::cout<<"Boid n° "<<i<<std::endl;
        std::cout<<"Position: "<<(_boids[i]->get_position())._x<<"|"<<(_boids[i]->get_position())._y<<std::endl;
        std::cout<<"Velocity: "<<(_boids[i]->get_velocity())._x<<"|"<<(_boids[i]->get_velocity())._y<<std::endl;
        std::cout<<"--------------------------------------------------------------------------------"<<std::endl;
    }
}

//SFML stuff



void Simulation::show_window()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boids");

    sf::CircleShape triangle(1000./double(_N));
    triangle.setFillColor(sf::Color(100, 250, 50));
    triangle.setPosition(10., 50.);


    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        


        window.clear();

        window.draw(triangle);

        window.display();
    }
}

void Simulation::draw_boids()
{

}