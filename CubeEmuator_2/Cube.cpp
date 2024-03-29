#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

#include "Cube.h"

Cube::Cube() {
    for (int i = 0; i < 6; i++) {
        std::vector<Color> face;
        for (int j = 0; j < 9; j++) {
            face.push_back(char_to_color(INITIAL[i * 9 + j]));
        }
        blocks_.push_back(face);
    }

    rotate_left();
}

Cube::Cube(std::string stickers) {
    if (stickers.length() != 6 * 9) {
        throw std::logic_error("'" + stickers + "' is not a scan");
    }

    for (int i = 0; i < 6; i++) {
        std::vector<Color> face;
        for (int j = 0; j < 9; j++) {
            face.push_back(char_to_color(stickers[i * 9 + j]));
        }
        blocks_.push_back(face);
    }

    rotate_left();
}

Cube::Cube(const Cube &other) {
    for (int i = 0; i < 6; i++) {
        std::vector<Color> face;
        for (int j = 0; j < 9; j++) {
            face.push_back(other.blocks_[i][j]);
        }
        blocks_.push_back(face);
    }

    for (const auto &line: other.history_) {
        history_.push_back(line);
    }
}

Cube &Cube::operator=(const Cube &other) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            blocks_[i][j] = other.blocks_[i][j];
        }
    }

    history_.clear();

    for (const auto &line: other.history_) {
        history_.push_back(line);
    }

    return *this;
}

std::vector<Color> &Cube::operator[](const int &face_index) {
    return blocks_[face_index];
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
        Color shifted = blocks_[4][i];
        for (int j = 0; j < 4; j++) {
            std::swap(shifted, blocks_[indexes[j]][i]);
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

    Color shifted_even = blocks_[face_no][0], shifted_odd = blocks_[face_no][3];

    for (int i = 0; i < 4; i++) {
        std::swap(shifted_even, blocks_[face_no][even_indexes[i]]);
        std::swap(shifted_odd, blocks_[face_no][odd_indexes[i]]);
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
        Color shifted = blocks_[4][i];
        for (int j = 0; j < 4; j++) {
            if (indexes[j] == 5) {
                std::swap(shifted, blocks_[indexes[j]][8 - i]);
            } else {
                std::swap(shifted, blocks_[indexes[j]][i]);
            }
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
    top_anticlockwise();
    down_anticlockwise();
    anticlockwise_layer_shift(1);
}

void Cube::rotate_right() {
    top_clockwise();
    down_clockwise();
    clockwise_layer_shift(1);
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

void Cube::rotate_x() {
    rotate_down();
}

void Cube::rotate_y() {
    rotate_right();
}

void Cube::topple_z() {
    rotate_left();
    rotate_down();
    rotate_right();
}

int Cube::check_deviation() {
    int result = 0;

    for (int face = 0; face < 6; face++) {
        for (int block = 0; block < 9; block++) {
            if (blocks_[face][block] != blocks_[face][4]) {
                result++;
            }
        }
    }

    return result;
}

void Cube::execute(std::string line) {
    history_.push_back(line);

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
            rotate_x();
        } else if (current_move == "x'") {
            for (int i = 0; i < 3; i++) {
                rotate_x();
            }
        } else if (current_move == "x2") {
            rotate_x();
            rotate_x();
        } else if (current_move == "y") {
            rotate_y();
        } else if (current_move == "y'") {
            for (int i = 0; i < 3; i++) {
                rotate_y();
            }
        } else if (current_move == "y2") {
            rotate_y();
            rotate_y();
        } else if (current_move == "z") {
            topple_z();
        } else if (current_move == "z'") {
            for (int i = 0; i < 3; i++) {
                topple_z();
            }
        } else if (current_move == "z2") {
            topple_z();
            topple_z();
        } else {
            std::cout << "\"" << current_move << "\" is not a move" << std::endl;
        }
    }
}

std::vector<std::string> Cube::get_history() {
    std::vector<std::string> result;

    if (!history_.empty()) {
        result.push_back(history_[0]);

        std::string algorithm;
        for (int i = 1; i < history_.size(); i++) {
            if (i != 1) {
                algorithm += " ";
            }
            algorithm += history_[i];
        }

        result.push_back(algorithm);
    }

    return result;
}

bool Cube::check_validity() {
    std::vector<int> color_numbers(6);
    std::set<Color> centers;

    for (int i = 0; i < 6; i++) {
        centers.insert(blocks_[i][4]);

        for (int j = 0; j < 9; j++) {
            color_numbers[blocks_[i][j]]++;
        }
    }

    if (centers.size() != 6) {
        return false;
    }

    for (auto value: color_numbers) {
        if (value != 9) {
            return false;
        }
    }

    return check_corners() && check_middles();
}

bool Cube::check_corners() {
    std::vector<std::set<Color>> acceptable_corners = {{White,  Red,    Blue},
                                                       {White,  Orange, Blue},
                                                       {Yellow, Orange, Blue},
                                                       {Red,    Blue,   Yellow},
                                                       {White,  Orange, Green},
                                                       {Orange, Green,  Yellow},
                                                       {Green,  Yellow, Red},
                                                       {White,  Red,    Green}};

    std::vector<std::set<Color>> given_corners = {{blocks_[3][8], blocks_[4][6], blocks_[1][0]},
                                                  {blocks_[3][2], blocks_[4][0], blocks_[0][6]},
                                                  {blocks_[0][8], blocks_[4][2], blocks_[2][0]},
                                                  {blocks_[1][2], blocks_[4][8], blocks_[2][6]},
                                                  {blocks_[5][2], blocks_[1][8], blocks_[2][8]},
                                                  {blocks_[5][0], blocks_[1][6], blocks_[3][6]},
                                                  {blocks_[3][0], blocks_[0][0], blocks_[5][6]},
                                                  {blocks_[2][2], blocks_[0][2], blocks_[5][8]}};

    for (const auto &gc: given_corners) {
        bool is_found = false;

        for (const auto &ac: acceptable_corners) {
            if (gc == ac) {
                is_found = true;
                break;
            }
        }

        if (!is_found) {
            return false;
        }
    }

    return true;
}

bool Cube::check_middles() {
    std::vector<std::set<Color>> unacceptable_middles = {{Yellow, White},
                                                         {Blue,   Green},
                                                         {Orange, Red}};

    std::vector<std::set<Color>> given_middles = {{blocks_[4][1], blocks_[0][7]},
                                                  {blocks_[4][5], blocks_[2][3]},
                                                  {blocks_[4][7], blocks_[1][1]},
                                                  {blocks_[4][3], blocks_[3][5]},
                                                  {blocks_[1][3], blocks_[3][7]},
                                                  {blocks_[1][7], blocks_[5][1]},
                                                  {blocks_[1][5], blocks_[2][7]},
                                                  {blocks_[3][1], blocks_[0][3]},
                                                  {blocks_[3][3], blocks_[5][3]},
                                                  {blocks_[2][1], blocks_[0][5]},
                                                  {blocks_[2][5], blocks_[5][5]},
                                                  {blocks_[0][1], blocks_[5][7]}};

    for (const auto &gm: given_middles) {
        for (const auto &um: unacceptable_middles) {
            if (gm == um) {
                return false;
            }
        }
    }

    return true;
}

void Cube::save() {
    std::ofstream out("SAVES.cube");

    if (out.good()) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                if (j != 0) {
                    out << " ";
                }
                out << blocks_[i][j];
            }
            out << std::endl;
        }

        out << history_.size() << std::endl;
        for (auto script: history_) {
            int n = std::count(script.begin(), script.end(), ' ') + 1;
            out << n << ' ' << script << std::endl;
        }
    } else {
        throw std::logic_error("\"SAVES.cube\" was removed");
    }

    out.close();
}

void Cube::load() {
    std::ifstream in("SAVES.cube");

    if (in.good()) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                int sticker;
                in >> sticker;
                blocks_[i][j] = static_cast<Color>(sticker);
            }
        }

        history_.clear();

        int loading_history_size, n;
        in >> loading_history_size;

        for (int i = 0; i < loading_history_size; i++) {
            std::string script, move;
            in >> n;
            for (int j = 0; j < n; j++) {
                in >> move;
                if (j != 0) {
                    script += " ";
                }
                script += move;
            }
            history_.push_back(script);
        }
    } else {
        throw std::logic_error("\"SAVES.cube\" was removed");
    }

    in.close();
}

void Cube::clear() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            blocks_[i][j] = char_to_color(INITIAL[i * 9 + j]);
        }
    }

    history_.clear();
}

void Cube::relabel(std::string stickers) {
    if (stickers.length() != 6 * 9) {
        throw std::logic_error("'" + stickers + "' is not a scan");
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            blocks_[i][j] = char_to_color(stickers[i * 9 + j]);
        }
    }

    history_.clear();
}