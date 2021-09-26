#include "simulation.hpp"

Simulation::Simulation(int n, int width, int length) : _N(n),_window(sf::VideoMode(1000, 1000), "Boids"), _width(width), _length(length)
{
    //_boids = new std::vector<Boid>;
    _boids.resize(_N);
    _boids_points.resize(_N);
    
    //_window = new QWidget;
}

Simulation::~Simulation()
{
    //delete _boids;
    //add max velocity 
}

void Simulation::initialise_positions()
{
    //for now the frame in a 1000 the speed is 100
    double random_posx,random_posy,random_velocityx,random_velocityy;
    vector pos,vel;

    for (int i=0; i<_N;i++)
    {
        srand (i);
        random_posx = ( (double)rand() / RAND_MAX ) *999. + 1.;
        random_posy = ( (double)rand() / RAND_MAX ) *999. + 1.;
        random_velocityx = ( (double)rand() / RAND_MAX ) *20. + 1.;
        random_velocityy = ( (double)rand() / RAND_MAX ) *20. + 1.;
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
        if (distance < 5.)
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

        std::cout<<_boids[i]->get_velocity()._x<<"//////"<<_boids[i]->get_velocity()._y<<std::endl;

        _boids[i]-> update_velocity(_boids[i]->get_velocity()+v1+v2+v3);
        _boids[i]-> update_position(_boids[i]->get_position() + _boids[i]->get_velocity());

        
        std::cout<<_boids[i]->get_position()._x<<"////"<<_boids[i]->get_position()._y<<std::endl;


        if( (_boids[i]->get_position()._x > _width) || (_boids[i]->get_position()._y > _length) )
        {
            vector new_position = {_boids[i]->get_position()._x,_boids[i]->get_position()._y};

            if( (_boids[i]->get_position())._x > _width)
            {
                new_position._x = (_boids[i]->get_position())._x - _width;
            }

            if( (_boids[i]->get_position())._y > _length)
            {
                new_position._y = (_boids[i]->get_position())._y - _length;
            }

            std::cout<<new_position._x<<"/"<<new_position._y<<std::endl;

            _boids[i]-> update_position(new_position);
        }
        
        if( (_boids[i]->get_velocity()._x > 1000.) || (_boids[i]->get_velocity()._y > 1000.) )
        {
            vector new_velocity = {_boids[i]->get_velocity()._x,_boids[i]->get_velocity()._y};

            if( (_boids[i]->get_velocity())._x > 1000.)
            {
                new_velocity._x = (_boids[i]->get_velocity())._x - _width;
            }

            if( (_boids[i]->get_velocity())._y > 1000.)
            {
                new_velocity._y = (_boids[i]->get_velocity())._y - _length;
            }

            _boids[i]-> update_velocity(new_velocity);
        }
        

        std::cout<<"-------------------------------------------------"<<std::endl;

          
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



void Simulation::show_boids()
{
    //sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boids");


    //move_boids();
    /*
    sf::CircleShape triangle(1000./double(_N));
    triangle.setFillColor(sf::Color(100, 250, 50));
    triangle.setPosition(500., 500.);
    */

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                _window.clear(sf::Color(255, 255, 255, 255));

                move_all_boids_to_new_positions();

                move_boids();

                print_boids();

                _window.display();

            }
        }

        _window.clear(sf::Color(255, 255, 255, 255));

        draw_boids();

        _window.display();
        
    }
}

void Simulation::draw_boids()
{
    for(int i=0; i<_N; i++)
    {
        _window.draw(*_boids_points[i]); 
    }
}

void Simulation::move_boids()
{
    for(int i=0; i<_N; i++)
    {
        _boids_points[i] = new sf::CircleShape(1000./double(_N));
        _boids_points[i]->setFillColor(sf::Color(100, 250, 50));
        //rewind time already taken into account
        _boids_points[i]->setPosition(_boids[i]->get_position()._x, _boids[i]->get_position()._y);
    }
}