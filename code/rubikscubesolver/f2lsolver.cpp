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

void solveLayerTwo(std::array<std::array<char,9>, 6> &cube){

    //red green edge
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (cube[i][j] == 'R'){
                if (findAdj(cube, i, j) == 'G'){
                    if (i == 1 && j == 1){
                        placeRed(cube, 0);
                    }
                    if (i == 1 && j == 3){
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        bCW(cube);
                        placeRed(cube, 0);
                    }
                    if (i == 1 && j == 5){
                        continue;
                    }
                    if (i == 2 && j == 1){
                        bCCW(cube);
                        uCCW(cube);
                        bCW(cube);
                        uCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 2 && j == 5){
                        bCW(cube);
                        placeRed(cube, 0);
                    }
                    if (i == 2 && j == 7){
                        bCW(cube);
                        dCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 3 && j == 3){
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCW(cube);
                        dCW(cube);
                        bCCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 3 && j == 5){
                        bCW(cube);
                        dCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCCW(cube);
                        placeRed(cube, 0);
                    }

                    if (i == 3 && j == 7){
                        bCW(cube);
                        bCW(cube);
                        placeRed(cube, 0);
                    }
                    if (i == 4 && j == 1){
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 4 && j == 3){
                        bCCW(cube);
                        placeRed(cube, 0);
                    }
                    if (i == 4 && j == 7){
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCW(cube);
                        dCW(cube);
                        placeRed(cube, 0);
                    }
                    if (i == 5 && j == 1){
                        bCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 5 && j == 3){
                        bCW(cube);
                        bCW(cube);
                        placeRed(cube, 1);
                    }
                    if (i == 5 && j == 5){
                        placeRed(cube, 1);
                    }
                    if (i == 5 && j == 7){
                        bCCW(cube);
                        placeRed(cube, 1);
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
                        bCCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 1 && j == 5) {
                        bCCW(cube);
                        uCCW(cube);
                        bCW(cube);
                        uCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 2 && j == 5) {
                        placeGreen(cube, 0);
                    }
                    if (i == 2 && j == 7) {
                        continue;
                    }
                    if (i == 3 && j == 3) {
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCW(cube);
                        dCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeGreen(cube, 1);
                    }
                    if (i == 3 && j == 5) {
                        bCW(cube);
                        dCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 3 && j == 7) {
                        bCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 4 && j == 1) {
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        placeGreen(cube, 1);
                    }
                    if (i == 4 && j == 3) {
                        bCW(cube);
                        bCW(cube);
                        placeGreen(cube, 0);
                    }
                    if (i == 4 && j == 7) {
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCW(cube);
                        dCW(cube);
                        bCCW(cube);
                        placeGreen(cube, 0);
                    }

                    if (i == 5 && j == 1) {
                        placeGreen(cube, 1);
                    }
                    if (i == 5 && j == 3) {
                        bCW(cube);
                        placeGreen(cube, 1);
                    }
                    if (i == 5 && j == 5) {
                        bCCW(cube);
                        placeGreen(cube, 1);
                    }
                    if (i == 5 && j == 7) {
                        bCW(cube);
                        bCW(cube);
                        placeGreen(cube, 1);
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
                        bCW(cube);
                        bCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 1 && j == 5) {
                        bCCW(cube);
                        uCCW(cube);
                        bCW(cube);
                        uCW(cube);
                        bCW(cube);
                        rCW(cube);
                        bCCW(cube);
                        rCCW(cube);
                        bCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 2 && j == 5) {
                        bCCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 3 && j == 3) {
                        continue;
                    }
                    if (i == 3 && j == 7) {
                        placeOrange(cube, 0);
                    }
                    if (i == 4 && j == 1) {
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeOrange(cube, 1);
                    }
                    if (i == 4 && j == 3) {
                        bCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 4 && j == 7) {
                        bCW(cube);
                        lCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCCW(cube);
                        dCCW(cube);
                        bCW(cube);
                        dCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeOrange(cube, 0);
                    }
                    if (i == 5 && j == 1) {
                        bCCW(cube);
                        placeOrange(cube, 1);
                    }
                    if (i == 5 && j == 3) {
                        placeOrange(cube, 1);
                    }
                    if (i == 5 && j == 5) {
                        bCW(cube);
                        bCW(cube);
                        placeOrange(cube, 1);
                    }
                    if (i == 5 && j == 7) {
                        bCW(cube);
                        placeOrange(cube, 1);
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
                        bCW(cube);
                        placeBlue(cube, 0);
                    }
                    if (i == 1 && j == 3) {
                        bCW(cube);
                        uCW(cube);
                        bCCW(cube);
                        uCCW(cube);
                        bCCW(cube);
                        lCCW(cube);
                        bCW(cube);
                        lCW(cube);
                        bCW(cube);
                        bCW(cube);
                        placeBlue(cube, 0);
                    }
                    if (i == 2 && j == 5) {
                        bCW(cube);
                        bCW(cube);
                        placeBlue(cube, 0);
                    }
                    if (i == 3 && j == 7) {
                        bCCW(cube);
                        placeBlue(cube, 0);
                    }
                    if (i == 4 && j == 3) {
                        placeBlue(cube, 0);
                    }
                    if (i == 5 && j == 1) {
                        bCW(cube);
                        bCW(cube);
                        placeBlue(cube, 1);
                    }
                    if (i == 5 && j == 3) {
                        bCCW(cube);
                        placeBlue(cube, 1);
                    }
                    if (i == 5 && j == 5) {
                        bCW(cube);
                        placeBlue(cube, 1);
                    }
                    if (i == 5 && j == 7) {
                        placeBlue(cube, 1);
                    }
                }
            }
        }
    }


}

void placeRed(std::array<std::array<char,9>, 6> &cube, int i){
    //when on red face.
    if (i == 0){
        bCW(cube);
        rCW(cube);
        bCCW(cube);
        rCCW(cube);
        bCCW(cube);
        uCCW(cube);
        bCW(cube);
        uCW(cube);
    }
    //when on green face.
    if (i == 1){
        bCCW(cube);
        uCCW(cube);
        bCW(cube);
        uCW(cube);
        bCW(cube);
        rCW(cube);
        bCCW(cube);
        rCCW(cube);
    }
}

void placeGreen(std::array<std::array<char,9>, 6> &cube, int i){
    //when on green face.
    if (i == 0){
        bCW(cube);
        dCW(cube);
        bCCW(cube);
        dCCW(cube);
        bCCW(cube);
        rCCW(cube);
        bCW(cube);
        rCW(cube);
    }
    //when on orange face.
    if (i == 1){
        bCCW(cube);
        rCCW(cube);
        bCW(cube);
        rCW(cube);
        bCW(cube);
        dCW(cube);
        bCCW(cube);
        dCCW(cube);
    }
}

void placeOrange(std::array<std::array<char,9>, 6> &cube, int i){
    //when on orange face.
    if (i == 0){
        bCW(cube);
        lCW(cube);
        bCCW(cube);
        lCCW(cube);
        bCCW(cube);
        dCCW(cube);
        bCW(cube);
        dCW(cube);
    }
    //when on blue face.
    if (i == 1){
        bCCW(cube);
        dCCW(cube);
        bCW(cube);
        dCW(cube);
        bCW(cube);
        lCW(cube);
        bCCW(cube);
        lCCW(cube);
    }
}

void placeBlue(std::array<std::array<char,9>, 6> &cube, int i){
    //when on blue face.
    if (i == 0){
        bCW(cube);
        uCW(cube);
        bCCW(cube);
        uCCW(cube);
        bCCW(cube);
        lCCW(cube);
        bCW(cube);
        lCW(cube);
    }
    //when on red face.
    if (i == 1){
        bCCW(cube);
        lCCW(cube);
        bCW(cube);
        lCW(cube);
        bCW(cube);
        uCW(cube);
        bCCW(cube);
        uCCW(cube);
    }
}
