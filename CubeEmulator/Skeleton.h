#ifndef CUBEEMULATOR_SKELETON_H
#define CUBEEMULATOR_SKELETON_H

#include <vector>

class Skeleton {
private:
    std::vector<std::vector<int>> coordinates_;

    Skeleton() {
        for (int i = 0; i < 3; i++) {
            coordinates_.push_back(std::vector<int>(3));
        }
    }
};


#endif //CUBEEMULATOR_SKELETON_H
