#ifndef CUBEEMULATOR_SOLVER_H
#define CUBEEMULATOR_SOLVER_H

#include <limits>

#include "Cube.h"

const int MAX_SCRAMBLING_NUMBER = 12;
const int VITAL_CYCLES_NUMBER = 50;
const int MAX_GENERATIONS_NUMBER = 300;
const int POPULATION_SIZE = 500;
const int IN_TOP_NUMBER = 50;

bool compare_cubes(Cube c1, Cube c2);

class Solver {
public:
    Solver();

    Solver(std::string scrambler);

    std::string solve_genetically();

    Cube shuffle(Cube cube);

    Cube get_solved_cube();

    void apply_relocator();

protected:
    int get_random_of(const int &begin, const int &end);

    std::string get_random_relocation();

    std::string get_random_move();

    std::string get_random_rotation();

    std::string get_random_toppling();

private:
    Cube solved_;
    std::string scrambler_;
    std::vector<std::string> relocations_;
    std::vector<std::string> moves_;
    std::vector<std::string> rotations_;
    std::vector<std::string> topplings_;
};


#endif //CUBEEMULATOR_SOLVER_H
