#ifndef CUBEEMUATOR_2_RENDERER_H
#define CUBEEMUATOR_2_RENDERER_H

#include "Cube.h"

const int SCAN_WIDTH_R = 19;

class Renderer {
public:
    Renderer(Cube &cube);

    void set_width(const int &width);

    void visualize_cube();

private:
    int width_;
    Cube &cube_;
};


#endif //CUBEEMUATOR_2_RENDERER_H
