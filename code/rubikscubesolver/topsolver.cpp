#include <array>
#include <algorithm>
#include "topsolver.h"
#include "rotations.h"
#include "f2lsolver.h"


void solveTopCross(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){
    while (topCrossSolve(cube) == 0){
        if (cube[5][1] == 'Y' && cube[5][3] == 'Y'){
            crossAlgo(cube, solveArray);
        }
        else if (cube[5][1] == 'Y' && cube[5][5] == 'Y'){
            bCCW(cube, solveArray);
            crossAlgo(cube, solveArray);
        }
        else if (cube[5][7] == 'Y' && cube[5][5] == 'Y'){
            bCW(cube, solveArray);
            bCW(cube, solveArray);
            crossAlgo(cube, solveArray);
        }
        else if (cube[5][7] == 'Y' && cube[5][3] == 'Y'){
            bCW(cube, solveArray);
            crossAlgo(cube, solveArray);
        }
        else {
            crossAlgo(cube, solveArray);
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

void crossAlgo(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){
    uCW(cube, solveArray);
    bCW(cube, solveArray);
    rCW(cube, solveArray);
    bCCW(cube, solveArray);
    rCCW(cube, solveArray);
    uCCW(cube, solveArray);
}

//for edges, get red to correct position, and then perform algo on green and then get red to correct and repeat till its correct.

void solveYellowEdges(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){
    while (cube[1][1] != 'R' || cube[2][5] != 'G' || cube[3][7] != 'O' || cube[4][3] != 'B'){
        if (cube[1][1] == 'R'){
            if (cube[2][5] == 'G'){
                lCW(cube, solveArray);
                bCW(cube, solveArray);
                lCCW(cube, solveArray);
                bCW(cube, solveArray);
                lCW(cube, solveArray);
                bCW(cube, solveArray);
                bCW(cube, solveArray);
                lCCW(cube, solveArray);
            }
            else {
                dCW(cube, solveArray);
                bCW(cube, solveArray);
                dCCW(cube, solveArray);
                bCW(cube, solveArray);
                dCW(cube, solveArray);
                bCW(cube, solveArray);
                bCW(cube, solveArray);
                dCCW(cube, solveArray);
            }
        }
        else if (cube[2][5] == 'R'){
            bCW(cube, solveArray);
        }
        else if (cube[3][7] == 'R'){
            bCW(cube, solveArray);
            bCW(cube, solveArray);
        }
        else if (cube[4][3] == 'R'){
            bCCW(cube, solveArray);
        }
    }
}

void solveTopCorners(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){

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
            bCW(cube, solveArray);
            rCW(cube, solveArray);
            bCCW(cube, solveArray);
            lCCW(cube, solveArray);
            bCW(cube, solveArray);
            rCCW(cube, solveArray);
            bCCW(cube, solveArray);
            lCW(cube, solveArray);
        }
        else if (colorArrayGOY[0] == 'G' && colorArrayGOY[1] == 'O' && colorArrayGOY[2] == 'Y'){
            bCW(cube, solveArray);
            dCW(cube, solveArray);
            bCCW(cube, solveArray);
            uCCW(cube, solveArray);
            bCW(cube, solveArray);
            dCCW(cube, solveArray);
            bCCW(cube, solveArray);
            uCW(cube, solveArray);
        }
        else if (colorArrayBOY[0] == 'B' && colorArrayBOY[1] == 'O' && colorArrayBOY[2] == 'Y'){
            bCW(cube, solveArray);
            lCW(cube, solveArray);
            bCCW(cube, solveArray);
            rCCW(cube, solveArray);
            bCW(cube, solveArray);
            lCCW(cube, solveArray);
            bCCW(cube, solveArray);
            rCW(cube, solveArray);

        }
        else {
            bCW(cube, solveArray);
            uCW(cube, solveArray);
            bCCW(cube, solveArray);
            dCCW(cube, solveArray);
            bCW(cube, solveArray);
            uCCW(cube, solveArray);
            bCCW(cube, solveArray);
            dCW(cube, solveArray);
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
            rCCW(cube, solveArray);
            fCCW(cube, solveArray);
            rCW(cube, solveArray);
            fCW(cube, solveArray);
        }
        bCW(cube, solveArray);
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