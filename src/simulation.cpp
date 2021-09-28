#include "simulation.hpp"

#define bug std::cout<<"debug"<<std::endl;

#define PI 3.14159265


Simulation::Simulation(int n, int width, int length) : _N(n),_window(sf::VideoMode(1000, 1000), "Boids"), _width(width), _length(length)
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

        _boids_points[i]->scale(0.35, 0.25);

    }

    _window.setVerticalSyncEnabled(false);
    _window.setFramerateLimit(10);
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

    perceived_center._x /= (10. * _N);
    perceived_center._y /= (10. * _N);


    return perceived_center; 
}


vector Simulation::rule2(Boid* b)
{
    vector c= {0.,0.};
    for (int i=0; i<_N; i++)
    {
        //the added boid in the loop does nothing, too lazt to map it or index it?
        double distance = Boid::compute_distance(*b, *_boids[i]);
        if (distance < 1.)
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

    pvj = pvj - b->get_velocity();

    pvj._x /= (double(0.5*_N));
    pvj._y /= (double(0.5*_N));

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

        //std::cout<<_boids[i]->get_velocity()._x<<"//////"<<_boids[i]->get_velocity()._y<<std::endl;

        _boids[i]-> update_velocity(_boids[i]->get_velocity()+v1+v2+v3);
        _boids[i]-> update_position(_boids[i]->get_position() + _boids[i]->get_velocity());

        
        //std::cout<<_boids[i]->get_position()._x<<"////"<<_boids[i]->get_position()._y<<std::endl;


        if( (_boids[i]->get_position()._x > _width) || (_boids[i]->get_position()._y > _length) || (_boids[i]->get_position()._x < 0.) || (_boids[i]->get_position()._y < 0.) )
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

            if( (_boids[i]->get_position())._x < 0.)
            {
                new_position._x = (_boids[i]->get_position())._x + _width;
            }

            if( (_boids[i]->get_position())._y < 0.)
            {
                new_position._y = (_boids[i]->get_position())._y + _length;
            }

            //std::cout<<new_position._x<<"/"<<new_position._y<<std::endl;

            _boids[i]-> update_position(new_position);
        }
        
        
        if( (_boids[i]->get_velocity()._x > 10.) || (_boids[i]->get_velocity()._y > 10.)   || (_boids[i]->get_velocity()._x < -10.) || (_boids[i]->get_velocity()._y < -10.))
        {
            vector new_velocity = {_boids[i]->get_velocity()._x,_boids[i]->get_velocity()._y};

            if( (_boids[i]->get_velocity())._x > 10.)
            {
                new_velocity._x = (_boids[i]->get_velocity())._x / 100.;
            }

            if( (_boids[i]->get_velocity())._y > 10.)
            {
                new_velocity._y = (_boids[i]->get_velocity())._y / 100.;
            }

            if( (_boids[i]->get_velocity())._x < -10.)
            {
                new_velocity._x = (_boids[i]->get_velocity())._x / 100.;
            }

            if( (_boids[i]->get_velocity())._y < -10.)
            {
                new_velocity._y = (_boids[i]->get_velocity())._y / 100.;
            }

            _boids[i]-> update_velocity(new_velocity);
        }
        

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
    
    //sf::Texture texture;
    
    //texture.loadFromFile("images/arrow.png");

    //sf::IntRect rectSourceSprite(300, 0, 300, 400);

    //sf::Sprite sprite(texture,rectSourceSprite);
    


    //sf::Time prevTime = clock.getElapsedTime();

    bug

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
        std::cout<<"angle: "<<angle<<std::endl;

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