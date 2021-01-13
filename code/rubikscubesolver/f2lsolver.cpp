#include <array>
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

void solveCorners(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray) {
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
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    rCW(cube, solveArray);
                    bCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    rCCW(cube, solveArray);
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    rCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    dCCW(cube, solveArray);
                    bCCW(cube, solveArray);
                    dCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }

                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCCW(cube, solveArray);
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    while ((cube[0][0] != 'W') || (cube[1][6] != 'R') || (cube[4][2] != 'B')) {
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
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
                    lCCW(cube, solveArray);
                    bCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    dCW(cube, solveArray);
                    bCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    lCW(cube, solveArray);
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCCW(cube, solveArray);
                    while ((cube[0][2] != 'W') || (cube[1][8] != 'R') || (cube[2][0] != 'G')) {
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
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
                    lCCW(cube, solveArray);
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    lCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 2)) || ((i == 1) && (j == 8)) || ((i == 2) && (j == 0))) {
                    uCCW(cube, solveArray);
                    bCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 0) && (j == 8)) || ((i == 2) && (j == 6)) || ((i == 3) && (j == 2))) {
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }

                if (((i == 0) && (j == 6)) || ((i == 3) && (j == 0)) || ((i == 4) && (j == 8))) {
                    lCW(cube, solveArray);
                    bCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    bCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    while ((cube[0][8] != 'W') || (cube[2][6] != 'G') || (cube[3][2] != 'O')) {
                        rCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
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
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 2)) || ((i == 2) && (j == 2)) || ((i == 5) && (j == 8))) {
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 2) && (j == 8)) || ((i == 3) && (j == 8)) || ((i == 5) && (j == 2))) {
                    bCCW(cube, solveArray);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 3) && (j == 6)) || ((i == 4) && (j == 6)) || ((i == 5) && (j == 0))) {
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
                if (((i == 1) && (j == 0)) || ((i == 4) && (j == 0)) || ((i == 5) && (j == 6))) {
                    bCW(cube, solveArray);
                    while ((cube[0][6] != 'W') || (cube[3][0] != 'O') || (cube[4][8] != 'B')) {
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                    }
                }
            }
        }
    }
}

void solveLayerTwo(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){

    //red green edge
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (cube[i][j] == 'R'){
                if (findAdj(cube, i, j) == 'G'){
                    if (i == 1 && j == 1){
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 3){
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 5){
                        continue;
                    }
                    if (i == 2 && j == 1){
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 2 && j == 5){
                        bCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 2 && j == 7){
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 3 && j == 3){
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 3 && j == 5){
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }

                    if (i == 3 && j == 7){
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 1){
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 4 && j == 3){
                        bCCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 7){
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        placeRed(cube, 0, solveArray);
                    }
                    if (i == 5 && j == 1){
                        bCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 3){
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 5){
                        placeRed(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 7){
                        bCCW(cube, solveArray);
                        placeRed(cube, 1, solveArray);
                    }
                }
            }
        }
    }




    //green orange edge
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (cube[i][j] == 'G') {
                if (findAdj(cube, i, j) == 'O') {
                    if (i == 1 && j == 1) {
                        bCCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 5) {
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 2 && j == 5) {
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 2 && j == 7) {
                        continue;
                    }
                    if (i == 3 && j == 3) {
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeGreen(cube, 1, solveArray);
                    }
                    if (i == 3 && j == 5) {
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 3 && j == 7) {
                        bCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 1) {
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        placeGreen(cube, 1, solveArray);
                    }
                    if (i == 4 && j == 3) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 7) {
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        placeGreen(cube, 0, solveArray);
                    }

                    if (i == 5 && j == 1) {
                        placeGreen(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 3) {
                        bCW(cube, solveArray);
                        placeGreen(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 5) {
                        bCCW(cube, solveArray);
                        placeGreen(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 7) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeGreen(cube, 1, solveArray);
                    }
                }
            }
        }
    }


    //orange blue edge
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (cube[i][j] == 'O') {
                if (findAdj(cube, i, j) == 'B') {
                    if (i == 1 && j == 1) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 5) {
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCW(cube, solveArray);
                        rCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        rCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 2 && j == 5) {
                        bCCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 3 && j == 3) {
                        continue;
                    }
                    if (i == 3 && j == 7) {
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 1) {
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeOrange(cube, 1, solveArray);
                    }
                    if (i == 4 && j == 3) {
                        bCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 7) {
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        dCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        dCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeOrange(cube, 0, solveArray);
                    }
                    if (i == 5 && j == 1) {
                        bCCW(cube, solveArray);
                        placeOrange(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 3) {
                        placeOrange(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 5) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeOrange(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 7) {
                        bCW(cube, solveArray);
                        placeOrange(cube, 1, solveArray);
                    }
                }
            }
        }
    }



    //blue red edge
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (cube[i][j] == 'B') {
                if (findAdj(cube, i, j) == 'R') {
                    if (i == 1 && j == 1) {
                        bCW(cube, solveArray);
                        placeBlue(cube, 0, solveArray);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube, solveArray);
                        uCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        uCCW(cube, solveArray);
                        bCCW(cube, solveArray);
                        lCCW(cube, solveArray);
                        bCW(cube, solveArray);
                        lCW(cube, solveArray);
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeBlue(cube, 0, solveArray);
                    }
                    if (i == 2 && j == 5) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeBlue(cube, 0, solveArray);
                    }
                    if (i == 3 && j == 7) {
                        bCCW(cube, solveArray);
                        placeBlue(cube, 0, solveArray);
                    }
                    if (i == 4 && j == 3) {
                        placeBlue(cube, 0, solveArray);
                    }
                    if (i == 5 && j == 1) {
                        bCW(cube, solveArray);
                        bCW(cube, solveArray);
                        placeBlue(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 3) {
                        bCCW(cube, solveArray);
                        placeBlue(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 5) {
                        bCW(cube, solveArray);
                        placeBlue(cube, 1, solveArray);
                    }
                    if (i == 5 && j == 7) {
                        placeBlue(cube, 1, solveArray);
                    }
                }
            }
        }
    }


}

void placeRed(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray){
    //when on red face.
    if (i == 0){
        bCW(cube, solveArray);
        rCW(cube, solveArray);
        bCCW(cube, solveArray);
        rCCW(cube, solveArray);
        bCCW(cube, solveArray);
        uCCW(cube, solveArray);
        bCW(cube, solveArray);
        uCW(cube, solveArray);
    }
    //when on green face.
    if (i == 1){
        bCCW(cube, solveArray);
        uCCW(cube, solveArray);
        bCW(cube, solveArray);
        uCW(cube, solveArray);
        bCW(cube, solveArray);
        rCW(cube, solveArray);
        bCCW(cube, solveArray);
        rCCW(cube, solveArray);
    }
}

void placeGreen(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray){
    //when on green face.
    if (i == 0){
        bCW(cube, solveArray);
        dCW(cube, solveArray);
        bCCW(cube, solveArray);
        dCCW(cube, solveArray);
        bCCW(cube, solveArray);
        rCCW(cube, solveArray);
        bCW(cube, solveArray);
        rCW(cube, solveArray);
    }
    //when on orange face.
    if (i == 1){
        bCCW(cube, solveArray);
        rCCW(cube, solveArray);
        bCW(cube, solveArray);
        rCW(cube, solveArray);
        bCW(cube, solveArray);
        dCW(cube, solveArray);
        bCCW(cube, solveArray);
        dCCW(cube, solveArray);
    }
}

void placeOrange(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray){
    //when on orange face.
    if (i == 0){
        bCW(cube, solveArray);
        lCW(cube, solveArray);
        bCCW(cube, solveArray);
        lCCW(cube, solveArray);
        bCCW(cube, solveArray);
        dCCW(cube, solveArray);
        bCW(cube, solveArray);
        dCW(cube, solveArray);
    }
    //when on blue face.
    if (i == 1){
        bCCW(cube, solveArray);
        dCCW(cube, solveArray);
        bCW(cube, solveArray);
        dCW(cube, solveArray);
        bCW(cube, solveArray);
        lCW(cube, solveArray);
        bCCW(cube, solveArray);
        lCCW(cube, solveArray);
    }
}

void placeBlue(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray){
    //when on blue face.
    if (i == 0){
        bCW(cube, solveArray);
        uCW(cube, solveArray);
        bCCW(cube, solveArray);
        uCCW(cube, solveArray);
        bCCW(cube, solveArray);
        lCCW(cube, solveArray);
        bCW(cube, solveArray);
        lCW(cube, solveArray);
    }
    //when on red face.
    if (i == 1){
        bCCW(cube, solveArray);
        lCCW(cube, solveArray);
        bCW(cube, solveArray);
        lCW(cube, solveArray);
        bCW(cube, solveArray);
        uCW(cube, solveArray);
        bCCW(cube, solveArray);
        uCCW(cube, solveArray);
    }
}
