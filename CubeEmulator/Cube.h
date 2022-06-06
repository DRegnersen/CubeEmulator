#ifndef CUBEEMULATOR_CUBE_H
#define CUBEEMULATOR_CUBE_H

#include <iostream>
#include <vector>

enum Color {
    White = 0, Yellow = 1, Blue = 2, Green = 3, Red = 4, Orange = 5
};

class Cube {
public:
    Cube(std::string stickers);

    Cube(const Cube &other);

    Cube &operator=(const Cube &other);

    std::vector<Color> &operator[](const int &face_index);

    void execute(std::string line);

    void left_forward();

    void left_backward();

    void left_double();

    void right_forward();

    void right_backward();

    void right_double();

    void top_clockwise();

    void top_anticlockwise();

    void top_double();

    void down_clockwise();

    void down_anticlockwise();

    void down_double();

    void front_clockwise();

    void front_anticlockwise();

    void front_double();

    void back_clockwise();

    void back_anticlockwise();

    void back_double();

    void rotate_left();

    void rotate_right();

    void rotate_up();

    void rotate_down();

protected:
    Color char_to_color(const char &color);

    void clockwise_ring_shift(const int &column_no);

    void anticlockwise_ring_shift(const int &column_no);

    void clockwise_face_shift(const int &face_no);

    void anticlockwise_face_shift(const int &face_no);

    void clockwise_layer_shift(const int &row_no);

    void anticlockwise_layer_shift(const int &row_no);

private:
    std::vector<std::vector<Color>> stickers_;
};


#endif //CUBEEMULATOR_CUBE_H
