#include "boid.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>    
#include <time.h>



class Simulation
{
    private:
        std::vector<Boid*> _boids;
        int _N;
        //QWidget _window;
    public:
        Simulation(int);
        ~Simulation();

        //game methods
        void initialise_positions();
        void move_all_boids_to_new_positions();
        vector rule1(Boid*);
        vector rule2(Boid*);
        vector rule3(Boid*);

        //SFML
        void show_window();
        void draw_boids();

        //getters
        int get_n() const {return _N;};
        std::vector<Boid*> get_boids() const {return _boids;};
        void print_boids();

};