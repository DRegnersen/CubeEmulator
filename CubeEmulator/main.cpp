#include <iostream>
#include "Cube.h"

using namespace std;

void double_move(void (*move)()) {
    (*move)();
    (*move)();
}

void move() {
    cout << 3;
}

int main() {
    Cube c1("WWWWWWWWWYYYYYYYYYBBBBBBBBBGGGGGGGGGRRRRRRRRROOOOOOOOO");

    c1.execute("E R love you 45");

    //cout << c1[0][0];
    return 0;
}
