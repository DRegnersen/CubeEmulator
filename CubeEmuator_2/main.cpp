#include <iostream>

#include "Cube.h"
#include "Solver.h"
#include "Renderer.h"


using namespace std;

int main() {
    Cube c1(INITIAL);
    Renderer r1(c1);

    c1.right_forward();

    r1.visualize_cube();

    return 0;
}
