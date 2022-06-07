#include <iostream>

#include "Cube.h"
#include "Solver.h"
#include "Renderer.h"

std::string get_scrambler(std::vector<std::string> history) {
    std::string scrambler;

    for (int i = 0; i < history.size(); i++) {
        if (i != 0) {
            scrambler += " ";
        }
        scrambler += history[i];
    }

    return scrambler;
}

int main() {
    bool root = false;

    Cube cube(INITIAL);
    Renderer rnd(cube);
    cube.load();

    while (true) {
        std::string command;

        std::cout << "=> Command:";
        std::cin >> command;

        if (command == "clear") {

            cube.clear();

        } else if (command == "scramble") {

            Solver slv("");
            cube = slv.scramble(cube);
            std::cout << get_scrambler(cube.get_history()) << std::endl;

        } else if (command == "solve") {

            Solver slv(get_scrambler(cube.get_history()));
            slv.solve_genetically();
            cube = slv.get_solved_cube();

            std::cout << cube.get_history()[1] << std::endl;

        } else if (command == "move") {

            std::string moves;
            std::cout << "Print \"end\" to stop typing moves:";

            bool is_first = true;
            while (true) {
                std::string value;
                std::cin >> value;

                if (value == "end") {
                    break;
                }
                if (!is_first) {
                    moves += " ";
                } else {
                    is_first = false;
                }
                moves += value;
            }
            cube.execute(moves);

        } else if (command == "show") {

            rnd.visualize_cube();

        } else if (command == ".\\root") {

            root = true;
            std::cout << "Admin rights received" << std::endl;

        } else if (command == ".\\relabel" && root) {

            std::string stickers;
            std::cout << "Enter stickers:";
            std::cin >> stickers;
            cube.relabel(stickers);

        } else if (command == ".\\is-valid" && root) {

            if (cube.check_validity()) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }

        } else if (command == "save") {

            cube.save();

        } else if (command == "esc") {

            char answer;
            std::cout << "Save changes? (Y/N):";
            std::cin >> answer;

            if (answer == 'Y') {
                cube.save();
            }
            break;

        } else {

            std::cout << "\"" << command << "\" is not a command" << std::endl;

        }
    }

    return 0;
}
