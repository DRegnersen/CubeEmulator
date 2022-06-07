#include <fstream>
#include <windows.h>

#include "Renderer.h"

Renderer::Renderer(Cube &cube) : cube_(cube), width_(SCAN_WIDTH_R) {}

void Renderer::set_width(const int &width) {
    width_ = width;
}

void Renderer::visualize_cube() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<int> palette = {WHITE, YELLOW, BLUE, GREEN, RED, PURPLE};
    std::vector<int> indexes = {5, 0, 4, 1};

    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        if (indexes[i] == 4) {
            std::vector<int> wide_ring_indexes = {3, 4, 2};

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < (width_ - 17) / 2; k++) {
                    std::cout << " ";
                }

                for (int k = 0; k < 3; k++) {
                    if (k != 0) {
                        SetConsoleTextAttribute(hConsole, BLACK);
                        std::cout << "|";
                    }
                    for (int t = j * 3; t < j * 3 + 3; t++) {
                        if (t != j * 3) {
                            SetConsoleTextAttribute(hConsole, BLACK);
                            std::cout << "|";
                        }
                        SetConsoleTextAttribute(hConsole, palette[cube_[wide_ring_indexes[k]][t]]);
                        std::cout << char(219);
                    }
                }

                for (int k = 0; k < (width_ - 17) / 2; k++) {
                    std::cout << " ";
                }

                std::cout << std::endl;
            }
        } else {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < (width_ - 5) / 2; k++) {
                    std::cout << " ";
                }

                for (int k = j * 3; k < j * 3 + 3; k++) {
                    if (k != j * 3) {
                        SetConsoleTextAttribute(hConsole, BLACK);
                        std::cout << "|";
                    }
                    SetConsoleTextAttribute(hConsole, palette[cube_[indexes[i]][k]]);
                    std::cout << char(219);
                }

                for (int k = 0; k < (width_ - 5) / 2; k++) {
                    std::cout << " ";
                }

                std::cout << std::endl;
            }
        }
    }

    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void Renderer::print_highlighted(const std::string &message, const int &color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << message;
    SetConsoleTextAttribute(hConsole, 7);
}

void Renderer::print_info() {
    std::ifstream in("INFO.cube");

    if (in.good()) {
        int notes_number;
        in >> notes_number;

        for (int i = 0; i < notes_number; i++) {
            std::string note, sign, word;
            std::cout << "* ";

            in >> note;
            print_highlighted(note, YELLOW);

            in >> sign;
            if (sign != ";") {
                throw std::logic_error("\"INFO.cube\" was corrupted");
            }

            std::cout << " - ";

            while (true) {
                in >> word;
                if (word == ";") {
                    break;
                }
                std::cout << word << " ";
            }

            std::cout << std::endl;
        }
    } else {
        throw std::logic_error("\"INFO.cube\" was removed");
    }

    in.close();
}