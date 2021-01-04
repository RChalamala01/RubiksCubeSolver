#include <array>
#include <iostream>
#include <algorithm>

#include "crosssolver.h"
#include "f2lsolver.h"
#include "rotations.h"

void cornerColors(std::array<std::array<char,9>, 6> &cube, std::array<char,3> &colorArray, int i, int j){
    //white red blue corner
    if (((i == 0) && (j == 0)) || ((i == 1) && (j == 6)) || ((i == 4) && (j == 2))){
        colorArray[0] = cube[0][0];
        colorArray[1] = cube[1][6];
        colorArray[2] = cube[4][2];
    }
    //white red green corner
    if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))){
        colorArray[0] = cube[0][2];
        colorArray[1] = cube[1][8];
        colorArray[2] = cube[2][0];
    }
    //white green orange corner
    if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))){
        colorArray[0] = cube[0][8];
        colorArray[1] = cube[2][6];
        colorArray[2] = cube[3][2];
    }
    //white orange blue corner
    if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))){
        colorArray[0] = cube[0][6];
        colorArray[1] = cube[3][0];
        colorArray[2] = cube[4][8];
    }
    //red green yellow corner
    if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))){
        colorArray[0] = cube[1][2];
        colorArray[1] = cube[2][2];
        colorArray[2] = cube[5][8];
    }
    //green orange yellow corner
    if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))){
        colorArray[0] = cube[2][8];
        colorArray[1] = cube[3][8];
        colorArray[2] = cube[5][2];
    }
    //orange blue yellow corner
    if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))){
        colorArray[0] = cube[3][6];
        colorArray[1] = cube[4][6];
        colorArray[2] = cube[5][0];
    }
    //red blue yellow corner
    if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))){
        colorArray[0] = cube[1][0];
        colorArray[1] = cube[4][0];
        colorArray[2] = cube[5][6];
    }
}

void solveCorners(std::array<std::array<char,9>, 6> &cube) {
    std::array<char, 3> colorArray;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if ((pieceTypeCheck(j) != 2) || (cube[i][j] != 'W')) {
                continue;
            }

            cornerColors(cube, colorArray, i, j);
            std::sort(colorArray.begin(), colorArray.end());

            //white red blue corner
            if ((colorArray[0] == 'B') && (colorArray[1] == 'R') && (colorArray[2] == 'W')) {

                if (((i == 0) && (j == 0)) || ((i == 1) && (j == 6)) || ((i == 4) && (j == 2))) {
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    rCW(cube);
                    bCW(cube);
                    rCCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    rCCW(cube);
                    bCW(cube);
                    bCW(cube);
                    rCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    dCCW(cube);
                    bCCW(cube);
                    dCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }

                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCW(cube);
                    bCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCCW(cube);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube);
                        bCCW(cube);
                        lCW(cube);
                        bCW(cube);
                    }
                }
            }
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if ((pieceTypeCheck(j) != 2) || (cube[i][j] != 'W')) {
                continue;
            }

            cornerColors(cube, colorArray, i, j);
            std::sort(colorArray.begin(), colorArray.end());

            //white red green corner
            if ((colorArray[0] == 'G') && (colorArray[1] == 'R') && (colorArray[2] == 'W')) {

                if (((i == 0) && (j == 0)) || ((i == 1) && (j == 6)) || ((i == 4) && (j == 2))) {
                    lCCW(cube);
                    bCCW(cube);
                    lCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    dCW(cube);
                    bCW(cube);
                    dCCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    lCW(cube);
                    bCW(cube);
                    bCW(cube);
                    lCCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCW(cube);
                    bCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCCW(cube);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube);
                        bCCW(cube);
                        uCW(cube);
                        bCW(cube);
                    }
                }
            }
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if ((pieceTypeCheck(j) != 2) || (cube[i][j] != 'W')) {
                continue;
            }

            cornerColors(cube, colorArray, i, j);
            std::sort(colorArray.begin(), colorArray.end());

            //white green orange corner
            if ((colorArray[0] == 'G') && (colorArray[1] == 'O') && (colorArray[2] == 'W')) {

                if (((i == 0) && (j == 0)) || ((i == 1) && (j == 6)) || ((i == 4) && (j == 2))) {
                    lCCW(cube);
                    bCW(cube);
                    bCW(cube);
                    lCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    uCCW(cube);
                    bCCW(cube);
                    uCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    lCW(cube);
                    bCW(cube);
                    lCCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCW(cube);
                    bCW(cube);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube);
                        bCCW(cube);
                        rCW(cube);
                        bCW(cube);
                    }
                }
            }
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if ((pieceTypeCheck(j) != 2) || (cube[i][j] != 'W')) {
                continue;
            }

            cornerColors(cube, colorArray, i, j);
            std::sort(colorArray.begin(), colorArray.end());

            //white orange blue corner
            if ((colorArray[0] == 'B') && (colorArray[1] == 'O') && (colorArray[2] == 'W')) {

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube);
                        bCCW(cube);
                        dCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCW(cube);
                    bCW(cube);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube);
                        bCCW(cube);
                        dCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCCW(cube);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube);
                        bCCW(cube);
                        dCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube);
                        bCCW(cube);
                        dCW(cube);
                        bCW(cube);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCW(cube);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube);
                        bCCW(cube);
                        dCW(cube);
                        bCW(cube);
                    }
                }
            }
        }
    }
}
