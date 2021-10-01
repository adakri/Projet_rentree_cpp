#include "simulation.hpp"

#define bug std::cout<<"debug"<<std::endl;

#define PI 3.14159265


Simulation::Simulation(int n, int width, int length) :  _width(width), _length(length),_N(n),_window(sf::VideoMode(width, length), "Boids"), _alignement_d(80.), _max_speed(10.), _separation_d(15.)
{
    
    //_boids = new std::vector<Boid>;
    _boids.resize(_N);
    _boids_points.resize(_N);

    for(int i=0; i<_N; i++)
    {
        //_boids_points[i] = new sf::ConvexShape(500./double(_N),3);
        _boids_points[i] = new sf::ConvexShape();

        _boids_points[i]->setPointCount(4);

        _boids_points[i]->setPoint(1, sf::Vector2f(0, 0));
        _boids_points[i]->setPoint(0, sf::Vector2f(-20, -10));
        _boids_points[i]->setPoint(2, sf::Vector2f(20, -10));
        _boids_points[i]->setPoint(3, sf::Vector2f(0, 50));

        _boids_points[i]->setFillColor(sf::Color(0, 0, 0));

        _boids_points[i]->scale(0.25, 0.17);

    }

    _window.setVerticalSyncEnabled(false);
    _window.setFramerateLimit(30);
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
        random_posx = ( (double)rand() / RAND_MAX ) *_width + 0.;
        random_posy = ( (double)rand() / RAND_MAX ) *_length + 0.;
        random_velocityx = ( (double)rand() / RAND_MAX ) *_max_speed -_max_speed;
        random_velocityy = ( (double)rand() / RAND_MAX ) *_max_speed -_max_speed;
        pos = {random_posx,random_posy};
        vel = {random_velocityx,random_velocityy};
        
        _boids[i] = new Boid(pos,vel);
    }
    //this->print_boids();

    //exit(0);

}



vector Simulation::alignment(Boid* b)
{
    vector perceived_center = {0.,0.};
    int counter(0);
    //Better mapping to exclude the boid
    for (int i=0; i<_N; i++)
    {
        if(Boid::compute_distance(*b, *_boids[i]) < _alignement_d)
        {
            perceived_center = perceived_center + _boids[i]->get_velocity();
            counter++;
        }
         
    }
    //perceived_center = perceived_center - b->get_position();

    perceived_center._x /= double(counter);
    perceived_center._y /= double(counter);
    
    perceived_center = perceived_center - b->get_velocity();

    perceived_center._x *= 0.001;
    perceived_center._y *= 0.001;
    
    if( perceived_center._x > _max_speed || perceived_center._y > _max_speed)
    {
        perceived_center._x = _max_speed * 0.3;
        perceived_center._y = _max_speed * 0.3;
    }
    

    return perceived_center; 
}


vector Simulation::cohesion(Boid* b)
{
    vector c= {0.,0.};
    int counter(0);

    for (int i=0; i<_N; i++)
    {
        //the added boid in the loop does nothing, too lazt to map it or index it?
        //double distance = Boid::compute_distance(*b, *_boids[i]);
        if (Boid::compute_distance(*b, *_boids[i]) < _alignement_d)
        {
            c = c + _boids[i]->get_position() ; 
            counter++;
        }
    }

    c._x /= double(counter);
    c._y /= double(counter);

    c = c - b->get_position();

    //c._x *= 0.1 ;
    //c._y *= 0.1 ;
    
    if( c._x > _max_speed || c._y > _max_speed)
    {
        c._x = _max_speed * 0.3;
        c._y = _max_speed * 0.3;
    }
    
    return c;
}


vector Simulation::separation(Boid* b)
{
    vector pvj = {0.,0.};
    int counter(0);
    for (int i=0; i<_N; i++)
    {
        if (Boid::compute_distance(*b, *_boids[i]) <= _separation_d)
        {
            vector tmp ={0.0};
            tmp._x = _boids[i]->get_position()._x / _width;
            tmp._y = _boids[i]->get_position()._y / _length;
            pvj = pvj + (tmp - b->get_velocity());
            counter++;
        }
         
    }
    
    if( pvj._x > _max_speed || pvj._y > _max_speed)
    {
        pvj._x = _max_speed * 0.3;
        pvj._y = _max_speed * 0.3;
    }
    


    //pvj = pvj - b->get_position();
    pvj._x *= 0.01;
    pvj._y *= 0.01;

    //pvj = pvj - b->get_velocity();

    //pvj._x /= (double(counter));
    //pvj._y /= (double(counter));

    return pvj;
    
}



void Simulation::move_all_boids_to_new_positions()
{
    vector v1,v2,v3;

    for(int i=0; i<_N; i++)
    {
        v1 = alignment(_boids[i]);
        v2 = cohesion(_boids[i]);
        v3 = separation(_boids[i]);

        //std::cout<<_boids[i]->get_velocity()._x<<"//////"<<_boids[i]->get_velocity()._y<<std::endl;

        _boids[i]-> update_velocity(_boids[i]->get_velocity()+v1+v2-v3);
        _boids[i]-> update_position(_boids[i]->get_position() + _boids[i]->get_velocity());

        
        //std::cout<<_boids[i]->get_position()._x<<"////"<<_boids[i]->get_position()._y<<std::endl;



        vector new_position = {_boids[i]->get_position()._x,_boids[i]->get_position()._y};

        if( (_boids[i]->get_position())._x > _width)
        {
            //new_position._x = (_boids[i]->get_position())._x - _width;
            new_position._x = 0.;
        }

        if( (_boids[i]->get_position())._y > _length)
        {
            new_position._y = 0.;
        }

        if( (_boids[i]->get_position())._x < 0.)
        {
            new_position._x = _width;
        }

        if( (_boids[i]->get_position())._y < 0.)
        {
            new_position._y = _length;
        }

        //std::cout<<new_position._x<<"/"<<new_position._y<<std::endl;

        _boids[i]-> update_position(new_position);
        
        
        

        vector new_velocity = {_boids[i]->get_velocity()._x,_boids[i]->get_velocity()._y};

        if( (_boids[i]->get_velocity())._x > _max_speed)
        {
            //new_velocity._x = (_boids[i]->get_velocity())._x / 100.;
            new_velocity._x = 5.;
        }

        if( (_boids[i]->get_velocity())._y > _max_speed)
        {
            new_velocity._y = 5.;
        }

        if( (_boids[i]->get_velocity())._x < -_max_speed)
        {
            new_velocity._x = -5.;
        }

        if( (_boids[i]->get_velocity())._y < -_max_speed)
        {
            new_velocity._y = -5.;
        }

        _boids[i]-> update_velocity(new_velocity);
        
        

        //std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;

          
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
    bug

    //move_boids_shapes();
    /*
    sf::CircleShape triangle(1000./double(_N));
    triangle.setFillColor(sf::Color(100, 250, 50));
    triangle.setPosition(500., 500.);
    */

    sf::Event event;
    
    while (_window.isOpen())
    {
        sf::Clock clock;

        _window.clear(sf::Color::White);

        move_all_boids_to_new_positions();

        move_boids_shapes();

        draw_boids();

        print_boids();

        _window.display();

        //sf::Time elapsedTime = clock.getElapsedTime() - prevTime;

        //prevTime = prevTime + elapsedTime;

        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                _window.clear(sf::Color::White);

                move_all_boids_to_new_positions();

                move_boids_shapes();

                print_boids();

                draw_boids();

                _window.display(); 
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {

            }

            //sprite.setTextureRect(rectSourceSprite);

            //_window.clear(sf::Color(255, 255, 255, 255));

            

            std::cout<<"loop"<<std::endl; 
        }
        
    }
}




void Simulation::draw_boids()
{
    for(int i=0; i<_N; i++)
    {
        _window.draw(*_boids_points[i]); 
    }
}




void Simulation::move_boids_shapes()
{
    for(int i=0; i<_N; i++)
    {


        //rewind time already taken into account
        _boids_points[i]->setPosition(_boids[i]->get_position()._x, _boids[i]->get_position()._y);
        //Rotate the object
        double angle = abs (tan( abs(_boids[i]->get_velocity()._x) / abs(_boids[i]->get_velocity()._y ) * 180. / PI) );
        //std::cout<<"angle: "<<angle<<std::endl;

        if( _boids[i]->get_velocity()._x > 0. && _boids[i]->get_velocity()._y >0.)
        {
            _boids_points[i]->setRotation(angle);
        };
        if(_boids[i]->get_velocity()._x > 0. && _boids[i]->get_velocity()._y <0.)
        {
            _boids_points[i]->setRotation(90. + angle );
        };
        if(_boids[i]->get_velocity()._x < 0. && _boids[i]->get_velocity()._y  < 0.)
        {
            _boids_points[i]->setRotation(180. + angle);
        };
        if(_boids[i]->get_velocity()._x < 0. && _boids[i]->get_velocity()._y > 0.)
        {
            _boids_points[i]->setRotation(- angle );
        }
        
    }
}


void Simulation::launch_simulation()
{
    std::cout<<"Initialising the boids"<<std::endl;

    this->initialise_positions();
    
    this->move_boids_shapes();

    std::cout<<"Represent the boids"<<std::endl;
    
    this->draw_boids();

    //sfml stuff testing
    std::cout<<"Show the boids"<<std::endl;
    this->show_boids();
    
}