#include "createcube.h"
#include "crosssolver.h"
#include "f2lsolver.h"
#include "rotations.h"
#include "topsolver.h"

/* Rotation Notation: Everything based on Front (White Side).
     * Cube needs to initially be in the correct orientation.
     * To view red, rotate cube by 90 degrees down from white.
     * To view green, rotate cube by 90 degrees left from white.
     * To view orange, rotate cube by 90 degrees up from white.
     * To view yellow, rotate cube by 180 degrees up from white.
    */

int main(){
    //generating the cube.
    std::array<std::array<char,9>,6> cube{};

    originalState(cube);

    /*
    while (crossCheck(cube)){
        originalState(cube);
        cubeScramble(cube);
        printCube(cube);
        solveCross(cube);
        printCube(cube);
        solveCorners(cube);
        printCube(cube);
        solveLayerTwo(cube);
        printCube(cube);
        solveTopCross(cube);
        printCube(cube);
    }
    */

    cubeScramble(cube);
    printCube(cube);
    solveCross(cube);
    printCube(cube);
    solveCorners(cube);
    printCube(cube);
    solveLayerTwo(cube);
    printCube(cube);
    solveTopCross(cube);
    printCube(cube);


    return 0;
}
