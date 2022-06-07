#include <fstream>
#include <algorithm>
#include <random>

#include "Solver.h"

bool compare_cubes(Cube c1, Cube c2) {
    return c1.check_deviation() < c2.check_deviation();
}

Solver::Solver() {
    scrambler_ = "";

    moves_ = {"U", "U'", "U2", "D", "D'", "D2", "R", "R'", "R2", "L", "L'", "L2", "F", "F'", "F2", "B", "B'", "B2"};
    rotations_ = {"x", "x'", "x2", "y", "y'", "y2"};
    topplings_ = {"z", "z'", "z2"};

    apply_relocator();
}

Solver::Solver(std::string scrambler) {
    scrambler_ = scrambler;

    moves_ = {"U", "U'", "U2", "D", "D'", "D2", "R", "R'", "R2", "L", "L'", "L2", "F", "F'", "F2", "B", "B'", "B2"};
    rotations_ = {"x", "x'", "x2", "y", "y'", "y2"};
    topplings_ = {"z", "z'", "z2"};

    apply_relocator();
}

void Solver::apply_relocator() {
    std::ifstream in("RELOCATOR.cube");

    if (in.good()) {
        relocations_.clear();

        while (!in.eof()) {
            std::string preset, move;

            int number_of_moves;
            in >> number_of_moves;

            for (int i = 0; i < number_of_moves; i++) {
                in >> move;
                if (i != 0) {
                    preset += " ";
                }
                preset += move;
            }

            relocations_.push_back(preset);
        }
    } else {
        throw std::logic_error("\"RELOCATOR.cube\" was removed");
    }

    in.close();
}

int Solver::get_random_of(const int &begin, const int &end) {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution(begin, end);

    return distribution(generator);
}

std::string Solver::get_random_relocation() {
    return relocations_[get_random_of(0, relocations_.size() - 1)];
}

std::string Solver::get_random_move() {
    return moves_[get_random_of(0, moves_.size() - 1)];
}

std::string Solver::get_random_rotation() {
    return rotations_[get_random_of(0, rotations_.size() - 1)];
}

std::string Solver::get_random_toppling() {
    return topplings_[get_random_of(0, topplings_.size() - 1)];
}

std::string Solver::solve_genetically() {
    for (int cycle = 0; cycle < VITAL_CYCLES_NUMBER; cycle++) {
        std::vector<Cube> population;

        for (int i = 0; i < POPULATION_SIZE; i++) {
            Cube new_cube(INITIAL);
            new_cube.execute(scrambler_);

            new_cube.execute(get_random_move());
            new_cube.execute(get_random_move());

            population.push_back(new_cube);
        }

        for (int generation = 0; generation < MAX_GENERATIONS_NUMBER; generation++) {
            std::sort(population.begin(), population.end(), compare_cubes);

            for (int i = 0; i < population.size(); i++) {
                if (population[i].check_deviation() == 0) {
                    solved_ = population[i];
                    return population[i].get_history()[1];
                }

                if (i > IN_TOP_NUMBER) {
                    population[i] = population[get_random_of(0, IN_TOP_NUMBER)];

                    int evolution = get_random_of(0, 5);

                    if (evolution == 0) {
                        population[i].execute(get_random_relocation());
                    } else if (evolution == 1) {
                        population[i].execute(get_random_relocation());
                        population[i].execute(get_random_relocation());
                    } else if (evolution == 2) {
                        population[i].execute(get_random_rotation());
                        population[i].execute(get_random_relocation());
                    } else if (evolution == 3) {
                        population[i].execute(get_random_toppling());
                        population[i].execute(get_random_relocation());
                    } else if (evolution == 4) {
                        population[i].execute(get_random_rotation());
                        population[i].execute(get_random_toppling());
                        population[i].execute(get_random_relocation());
                    } else if (evolution == 5) {
                        population[i].execute(get_random_toppling());
                        population[i].execute(get_random_rotation());
                        population[i].execute(get_random_relocation());
                    }
                }
            }
        }
    }

    throw std::logic_error("Solution was not found");
}

Cube Solver::get_solved_cube() {
    return solved_;
}

Cube Solver::shuffle(Cube cube) {
    int shuffles_number = get_random_of(MAX_SCRAMBLING_NUMBER / 2, MAX_SCRAMBLING_NUMBER);

    for (int i = 0; i < shuffles_number; i++) {
        cube.execute(get_random_move());
    }

    return cube;
}