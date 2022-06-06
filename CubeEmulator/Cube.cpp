#include <sstream>

#include "Cube.h"

Cube::Cube(std::string stickers) {
    if (stickers.length() != 6 * 9) {
        throw std::logic_error("'" + stickers + "' is not a scan");
    }

    for (int i = 0; i < 6; i++) {
        std::vector<Color> face;
        for (int j = 0; j < 9; j++) {
            face.push_back(char_to_color(stickers[i * 9 + j]));
        }
        stickers_.push_back(face);
    }
}

Cube::Cube(const Cube &other) : stickers_(other.stickers_) {}

Cube &Cube::operator=(const Cube &other) {
    stickers_ = other.stickers_;
    return *this;
}

std::vector<Color> &Cube::operator[](const int &face_index) {
    return stickers_[face_index];
}

Color Cube::char_to_color(const char &color) {
    if (color == 'W') {
        return White;
    } else if (color == 'Y') {
        return Yellow;
    } else if (color == 'B') {
        return Blue;
    } else if (color == 'G') {
        return Green;
    } else if (color == 'R') {
        return Red;
    } else if (color == 'O') {
        return Orange;
    } else {
        std::string to_output = "'";
        to_output += color;
        to_output += "' is not a color";
        throw std::logic_error(to_output);
    }
}

void Cube::clockwise_ring_shift(const int &column_no) {
    std::vector<int> indexes = {0, 5, 1, 4};

    for (int i = column_no; i <= column_no + 6; i += 3) {
        Color shifted = stickers_[4][i];
        for (int j = 0; j < 4; j++) {
            std::swap(shifted, stickers_[indexes[j]][i]);
        }
    }
}

void Cube::anticlockwise_ring_shift(const int &column_no) {
    for (int i = 0; i < 3; i++) {
        clockwise_ring_shift(column_no);
    }
}

void Cube::clockwise_face_shift(const int &face_no) {
    std::vector<int> even_indexes = {2, 8, 6, 0};
    std::vector<int> odd_indexes = {1, 5, 7, 3};

    Color shifted_even = stickers_[face_no][0], shifted_odd = stickers_[face_no][3];

    for (int i = 0; i < 4; i++) {
        std::swap(shifted_even, stickers_[face_no][even_indexes[i]]);
        std::swap(shifted_odd, stickers_[face_no][odd_indexes[i]]);
    }
}

void Cube::anticlockwise_face_shift(const int &face_no) {
    for (int i = 0; i < 3; i++) {
        clockwise_face_shift(face_no);
    }
}

void Cube::clockwise_layer_shift(const int &row_no) {
    std::vector<int> indexes = {3, 5, 2, 4};

    for (int i = row_no * 3; i < row_no * 3 + 3; i++) {
        Color shifted = stickers_[4][i];
        for (int j = 0; j < 4; j++) {
            std::swap(shifted, stickers_[indexes[j]][i]);
        }
    }
}

void Cube::anticlockwise_layer_shift(const int &row_no) {
    for (int i = 0; i < 3; i++) {
        clockwise_layer_shift(row_no);
    }
}

void Cube::left_forward() {
    clockwise_ring_shift(0);
    anticlockwise_face_shift(3);
}

void Cube::left_backward() {
    anticlockwise_ring_shift(0);
    clockwise_face_shift(3);
}

void Cube::left_double() {
    left_forward();
    left_forward();
}

void Cube::right_forward() {
    clockwise_ring_shift(2);
    clockwise_face_shift(2);
}

void Cube::right_backward() {
    anticlockwise_face_shift(2);
    anticlockwise_ring_shift(2);
}

void Cube::right_double() {
    right_forward();
    right_forward();
}

void Cube::top_clockwise() {
    clockwise_layer_shift(0);
    clockwise_face_shift(0);
}

void Cube::top_anticlockwise() {
    anticlockwise_layer_shift(0);
    anticlockwise_face_shift(0);
}

void Cube::top_double() {
    top_clockwise();
    top_clockwise();
}

void Cube::down_clockwise() {
    clockwise_layer_shift(2);
    anticlockwise_face_shift(1);
}

void Cube::down_anticlockwise() {
    anticlockwise_layer_shift(2);
    clockwise_face_shift(1);
}

void Cube::down_double() {
    down_clockwise();
    down_clockwise();
}

void Cube::front_clockwise() {
    rotate_right();
    left_backward();
    rotate_left();
}

void Cube::front_anticlockwise() {
    rotate_right();
    left_forward();
    rotate_left();
}

void Cube::front_double() {
    front_clockwise();
    front_clockwise();
}

void Cube::back_clockwise() {
    rotate_right();
    right_backward();
    rotate_left();
}

void Cube::back_anticlockwise() {
    rotate_right();
    right_forward();
    rotate_left();
}

void Cube::back_double() {
    back_clockwise();
    back_clockwise();
}

void Cube::rotate_left() {
    top_clockwise();
    down_clockwise();
    clockwise_layer_shift(1);
}

void Cube::rotate_right() {
    top_anticlockwise();
    down_anticlockwise();
    anticlockwise_layer_shift(1);
}

void Cube::rotate_up() {
    left_backward();
    right_backward();
    anticlockwise_ring_shift(1);
}

void Cube::rotate_down() {
    left_forward();
    right_forward();
    clockwise_ring_shift(1);
}

void Cube::execute(std::string line) {
    std::stringstream moves;
    moves << line;

    std::string current_move;

    while (moves >> current_move) {
        if (current_move == "L") {
            left_backward();
        } else if (current_move == "L'") {
            left_forward();
        } else if (current_move == "L2") {
            left_double();
        } else if (current_move == "R") {
            right_forward();
        } else if (current_move == "R'") {
            right_backward();
        } else if (current_move == "R2") {
            right_double();
        } else if (current_move == "U") {
            top_clockwise();
        } else if (current_move == "U'") {
            top_anticlockwise();
        } else if (current_move == "U2") {
            top_double();
        } else if (current_move == "D") {
            down_anticlockwise();
        } else if (current_move == "D'") {
            down_clockwise();
        } else if (current_move == "D2") {
            down_double();
        } else if (current_move == "F") {
            front_clockwise();
        } else if (current_move == "F'") {
            front_anticlockwise();
        } else if (current_move == "F2") {
            front_double();
        } else if (current_move == "B") {
            back_anticlockwise();
        } else if (current_move == "B'") {
            back_clockwise();
        } else if (current_move == "B2") {
            back_double();
        } else if (current_move == "M") {
            clockwise_ring_shift(1);
        } else if (current_move == "M'") {
            anticlockwise_ring_shift(1);
        } else if (current_move == "M2") {
            clockwise_ring_shift(1);
            clockwise_ring_shift(1);
        } else if (current_move == "E") {
            anticlockwise_layer_shift(1);
        } else if (current_move == "E'") {
            clockwise_layer_shift(1);
        } else if (current_move == "E2") {
            clockwise_layer_shift(1);
            clockwise_layer_shift(1);
        } else if (current_move == "S") {
            rotate_right();
            anticlockwise_ring_shift(1);
            rotate_left();
        } else if (current_move == "S'") {
            rotate_right();
            clockwise_ring_shift(1);
            rotate_left();
        } else if (current_move == "S2") {
            rotate_right();
            clockwise_ring_shift(1);
            clockwise_ring_shift(1);
            rotate_left();
        } else if (current_move == "x") {
            rotate_down();
        } else if (current_move == "y") {
            rotate_right();
        } else if (current_move == "z") {
            rotate_left();
            rotate_down();
            rotate_right();
        }
    }
}