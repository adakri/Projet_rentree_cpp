#include "boid.hpp"



class Simulation
{
    private:
        std::vector<Boid>* _boids;
        int _N;
    public:
        Simulation(int);
        ~Simulation();

        void initialise_positions();
        void move_all_boids_to_new_positions();
        vector rule1(Boid*);
        vector rule2(Boid*);
        vector rule3(Boid*);

        //SFML?
        void draw_boids();

};