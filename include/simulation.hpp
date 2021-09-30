#include "boid.hpp"
#include <math.h> 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>    
#include <time.h>



class Simulation
{
    private:
        std::vector<Boid*> _boids;
        std::vector<sf::ConvexShape*> _boids_points;
        int _N,_width,_length;
        double _alignement_d, _max_speed, _separation_d;
        sf::RenderWindow _window;
        //QWidget _window;
    public:
        Simulation(int, int , int);
        ~Simulation();

        //game methods
        void initialise_positions();
        void move_all_boids_to_new_positions();
        vector alignment(Boid*);
        vector cohesion(Boid*);
        vector separation(Boid*);
        void launch_simulation();

        //SFML
        void show_boids();
        void draw_boids();
        void move_boids_shapes();

        //getters
        int get_n() const {return _N;};
        std::vector<Boid*> get_boids() const {return _boids;};
        void print_boids();

};