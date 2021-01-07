#include <array>
#include <algorithm>
#include "topsolver.h"
#include "rotations.h"
#include "f2lsolver.h"


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

//for edges, get red to correct position, and then perform algo on green and then get red to correct and repeat till its correct.

void solveYellowEdges(std::array<std::array<char,9>, 6> &cube){
    while (cube[1][1] != 'R' || cube[2][5] != 'G' || cube[3][7] != 'O' || cube[4][3] != 'B'){
        if (cube[1][1] == 'R'){
            if (cube[2][5] == 'G'){
                lCW(cube);
                bCW(cube);
                lCCW(cube);
                bCW(cube);
                lCW(cube);
                bCW(cube);
                bCW(cube);
                lCCW(cube);
            }
            else {
                dCW(cube);
                bCW(cube);
                dCCW(cube);
                bCW(cube);
                dCW(cube);
                bCW(cube);
                bCW(cube);
                dCCW(cube);
            }
        }
        else if (cube[2][5] == 'R'){
            bCW(cube);
        }
        else if (cube[3][7] == 'R'){
            bCW(cube);
            bCW(cube);
        }
        else if (cube[4][3] == 'R'){
            bCCW(cube);
        }
    }
}

void solveTopCorners(std::array<std::array<char,9>, 6> &cube){

    std::array<char,3> colorArrayGRY;
    std::array<char,3> colorArrayGOY;
    std::array<char,3> colorArrayBOY;
    std::array<char,3> colorArrayBRY;

    cornerColors(cube, colorArrayGRY, 5, 8);
    std::sort(colorArrayGRY.begin(), colorArrayGRY.end());

    cornerColors(cube, colorArrayGOY, 5, 2);
    std::sort(colorArrayGOY.begin(), colorArrayGOY.end());

    cornerColors(cube, colorArrayBOY, 5, 0);
    std::sort(colorArrayBOY.begin(), colorArrayBOY.end());

    cornerColors(cube, colorArrayBRY, 5, 6);
    std::sort(colorArrayBRY.begin(), colorArrayBRY.end());

    while (topCornerCheck(cube, colorArrayGRY, colorArrayGOY, colorArrayBOY, colorArrayBRY) == 0){

        if (colorArrayGRY[0] == 'G' && colorArrayGRY[1] == 'R' && colorArrayGRY[2] == 'Y'){
            bCW(cube);
            rCW(cube);
            bCCW(cube);
            lCCW(cube);
            bCW(cube);
            rCCW(cube);
            bCCW(cube);
            lCW(cube);
        }
        else if (colorArrayGOY[0] == 'G' && colorArrayGOY[1] == 'O' && colorArrayGOY[2] == 'Y'){
            bCW(cube);
            dCW(cube);
            bCCW(cube);
            uCCW(cube);
            bCW(cube);
            dCCW(cube);
            bCCW(cube);
            uCW(cube);
        }
        else if (colorArrayBOY[0] == 'B' && colorArrayBOY[1] == 'O' && colorArrayBOY[2] == 'Y'){
            bCW(cube);
            lCW(cube);
            bCCW(cube);
            rCCW(cube);
            bCW(cube);
            lCCW(cube);
            bCCW(cube);
            rCW(cube);

        }
        else {
            bCW(cube);
            uCW(cube);
            bCCW(cube);
            dCCW(cube);
            bCW(cube);
            uCCW(cube);
            bCCW(cube);
            dCW(cube);
        }

        cornerColors(cube, colorArrayGRY, 5, 8);
        std::sort(colorArrayGRY.begin(), colorArrayGRY.end());

        cornerColors(cube, colorArrayGOY, 5, 2);
        std::sort(colorArrayGOY.begin(), colorArrayGOY.end());

        cornerColors(cube, colorArrayBOY, 5, 0);
        std::sort(colorArrayBOY.begin(), colorArrayBOY.end());

        cornerColors(cube, colorArrayBRY, 5, 6);
        std::sort(colorArrayBRY.begin(), colorArrayBRY.end());

    }

    for (int i = 0; i < 4; i++){
        while (cube[5][8] != 'Y'){
            rCCW(cube);
            fCCW(cube);
            rCW(cube);
            fCW(cube);
        }
        bCW(cube);
    }

}

bool topCornerCheck(std::array<std::array<char,9>, 6> &cube, std::array<char,3> &colorArrayGRY, std::array<char,3> &colorArrayGOY, std::array<char,3> &colorArrayBOY, std::array<char,3> &colorArrayBRY){
    if (colorArrayGRY[0] != 'G') return false;
    if (colorArrayGRY[1] != 'R') return false;
    if (colorArrayGRY[2] != 'Y') return false;
    if (colorArrayGOY[0] != 'G') return false;
    if (colorArrayGOY[1] != 'O') return false;
    if (colorArrayGOY[2] != 'Y') return false;
    if (colorArrayBOY[0] != 'B') return false;
    if (colorArrayBOY[1] != 'O') return false;
    if (colorArrayBOY[2] != 'Y') return false;
    if (colorArrayBRY[0] != 'B') return false;
    if (colorArrayBRY[1] != 'R') return false;
    if (colorArrayBRY[2] != 'Y') return false;
    return true;
}