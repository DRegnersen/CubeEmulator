#include <iostream>

#include "Cube.h"
#include "Solver.h"

using namespace std;

int main() {
    std::string scramble = "R' U' L2 B2 U2 F L2 B' L' B D R B F2 L F R' B2 F' L B' D B2 R2 D' U B2 F' D R2";

    Solver slv(scramble);

    std::cout << slv.solve_as_God();

    Cube c1 = slv.get_solved_cube();

    vector<std::string> scan = c1.scan();

    for (const auto &line: scan) {
        std::cout << line << std::endl;
    }

    std::cout << c1.check_validity() << std::endl;

    return 0;
}
