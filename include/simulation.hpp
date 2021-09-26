#include "boid.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>    
#include <time.h>



class Simulation
{
    private:
        std::vector<Boid*> _boids;
        std::vector<sf::CircleShape*> _boids_points;
        int _N,_width,_length;
        sf::RenderWindow _window;
        //QWidget _window;
    public:
        Simulation(int, int , int);
        ~Simulation();

        //game methods
        void initialise_positions();
        void move_all_boids_to_new_positions();
        vector rule1(Boid*);
        vector rule2(Boid*);
        vector rule3(Boid*);

        //SFML
        void show_boids();
        void draw_boids();
        void move_boids();

        //getters
        int get_n() const {return _N;};
        std::vector<Boid*> get_boids() const {return _boids;};
        void print_boids();

};