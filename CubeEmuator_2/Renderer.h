#ifndef CUBEEMUATOR_2_RENDERER_H
#define CUBEEMUATOR_2_RENDERER_H

#include "Cube.h"

const int SCAN_WIDTH_R = 19;

const int WHITE = 15, YELLOW = 14, BLUE = 9, GREEN = 10, RED = 12, PURPLE = 13, BLACK = 0;

class Renderer {
public:
    Renderer(Cube &cube);

    void set_width(const int &width);

    void visualize_cube();

    void print_highlighted(const std::string &message, const int &color);

    void print_info();

private:
    int width_;
    Cube &cube_;
};


#endif //CUBEEMUATOR_2_RENDERER_H
