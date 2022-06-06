#ifndef CUBEEMULATOR_SOLVER_H
#define CUBEEMULATOR_SOLVER_H

#include "Cube.h"

class Solver {
public:
    Solver(const Cube& cube);

protected:

private:
    Cube cube_;
};


#endif //CUBEEMULATOR_SOLVER_H
