#include <array>
#include "topsolver.h"
#include "rotations.h"

void solveTopCross(std::array<std::array<char,9>, 6> &cube){
    while (topCrossSolve(cube) == 0){
        if (cube[5][1] == 'Y' && cube[5][3] == 'Y'){
            crossAlgo(cube);
        }
        else if (cube[5][1] == 'Y' && cube[5][5] == 'Y'){
            bCCW(cube);
            crossAlgo(cube);
        }
        else if (cube[5][7] == 'Y' && cube[5][5] == 'Y'){
            bCW(cube);
            bCW(cube);
            crossAlgo(cube);
        }
        else if (cube[5][7] == 'Y' && cube[5][3] == 'Y'){
            bCW(cube);
            crossAlgo(cube);
        }
        else {
            crossAlgo(cube);
        }
    }
}

bool topCrossSolve(std::array<std::array<char,9>, 6> &cube){
    for (int i = 0; i < 9; i++){
        if (i % 2 == 1 && cube[5][i] != 'Y'){
            return false;
        }
    }
    return true;
}

void crossAlgo(std::array<std::array<char,9>, 6> &cube){
    uCW(cube);
    bCW(cube);
    rCW(cube);
    bCCW(cube);
    rCCW(cube);
    uCCW(cube);
}