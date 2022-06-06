#ifndef CUBEEMULATOR_SOLVER_H
#define CUBEEMULATOR_SOLVER_H

#include <limits>

#include "Cube.h"

const int VITAL_CYCLES_NUMBER = std::numeric_limits<int>::max();
const int MAX_GENERATIONS_NUMBER = 300;
const int POPULATION_SIZE = 500;
const int IN_TOP_NUMBER = 50;

bool compare_cubes(Cube c1, Cube c2);

class Solver {
public:
    Solver(std::string scrambler);

    std::string solve_as_God();

    void apply_relocator();

protected:
    int get_random_of(const int &begin, const int &end);

    std::string get_random_relocation();

    std::string get_random_move();

    std::string get_random_rotation();

    std::string get_random_toppling();

private:
    std::string scrambler_;
    std::vector<std::string> relocations_;
    std::vector<std::string> moves_;
    std::vector<std::string> rotations_;
    std::vector<std::string> topplings_;
};


#endif //CUBEEMULATOR_SOLVER_H
