#include <windows.h>

#include "Renderer.h"

Renderer::Renderer(Cube &cube) : cube_(cube), width_(SCAN_WIDTH_R) {}

void Renderer::set_width(const int &width) {
    width_ = width;
}

// ■

void Renderer::visualize_cube() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<int> palette = {15, 14, 9, 10, 12, 13};
    std::vector<int> indexes = {5, 0, 4, 1};

    for (int i = 0; i < 4; i++) {
        if (indexes[i] == 4) {
            std::vector<int> wide_ring_indexes = {3, 4, 2};

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < (width_ - 17) / 2; k++) {
                    std::cout << " ";
                }

                for (int k = 0; k < 3; k++) {
                    if (k != 0) {
                        SetConsoleTextAttribute(hConsole, 0);
                        std::cout << "|";
                    }
                    for (int t = j * 3; t < j * 3 + 3; t++) {
                        if (t != j * 3) {
                            SetConsoleTextAttribute(hConsole, 0);
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
                        SetConsoleTextAttribute(hConsole, 0);
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
}