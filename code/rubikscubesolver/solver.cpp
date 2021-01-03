#include <array>

#include "solver.h"
#include "rotations.h"


int pieceTypeCheck(int i){
    if (i == 4){
        return 0; //center piece
    }
    else if (i % 2 == 1){
        return 1; //edge piece
    }
    else{
        return 2; //corner piece
    }
}

char findAdj(std::array<std::array<char,9>, 6> &cube, int i, int j){

    if (i == 0){
        if (j == 1){
            return cube[1][7];
        }
        if (j == 3){
            return cube[4][5];
        }
        if (j == 5){
            return cube[2][3];
        }
        if (j == 7){
            return cube[3][1];
        }
    }
    if (i == 1){
        if (j == 1){
            return cube[5][7];
        }
        if (j == 3){
            return cube[4][1];
        }
        if (j == 5){
            return cube[2][1];
        }
        if (j == 7){
            return cube[0][1];
        }
    }
    if (i == 2){
        if (j == 1){
            return cube[1][5];
        }
        if (j == 3){
            return cube[0][5];
        }
        if (j == 5){
            return cube[5][5];
        }
        if (j == 7){
            return cube[3][5];
        }
    }
    if (i == 3){
        if (j == 1){
            return cube[0][7];
        }
        if (j == 3){
            return cube[4][7];
        }
        if (j == 5){
            return cube[2][7];
        }
        if (j == 7){
            return cube[5][1];
        }
    }
    if (i == 4){
        if (j == 1){
            return cube[1][3];
        }
        if (j == 3){
            return cube[5][3];
        }
        if (j == 5){
            return cube[0][3];
        }
        if (j == 7){
            return cube[3][3];
        }
    }
    if (i == 5){
        if (j == 1){
            return cube[3][7];
        }
        if (j == 3){
            return cube[4][3];
        }
        if (j == 5){
            return cube[2][5];
        }
        if (j == 7){
            return cube[1][1];
        }
    }
}

int crossCheck(std::array<std::array<char,9>, 6> &cube){
    for (int i = 0; i < 9; i++){
        if (i % 2 != 1){
            continue;
        }
        if (cube[0][i] != 'W'){
            return 0;
        }
    }
    return 1;
}

void solveCross(std::array<std::array<char,9>, 6> &cube){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'R'){
                if (i == 0 && j == 1){
                    continue;
                }
                if (i == 0 && j == 3){
                    fCW(cube);
                }
                if (i == 0 && j == 5){
                    fCCW(cube);
                }
                if (i == 0 && j == 7){
                    fCW(cube);
                    fCW(cube);
                }
                if (i == 1 && j == 1){
                    uCW(cube);
                    fCW(cube);
                    rCCW(cube);
                    fCCW(cube);
                }
                if (i == 1 && j == 3){
                    fCCW(cube);
                    lCW(cube);
                    fCW(cube);
                }
                if (i == 1 && j == 5){
                    fCW(cube);
                    rCCW(cube);
                    fCCW(cube);
                }
                if (i == 1 && j == 7){
                    uCW(cube);
                    fCCW(cube);
                    lCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 1){
                    uCW(cube);
                }
                if (i == 2 && j == 3){
                    rCW(cube);
                    uCW(cube);
                }
                if (i == 2 && j == 5){
                    rCCW(cube);
                    uCW(cube);
                }
                if (i == 2 && j == 7){
                    rCW(cube);
                    rCW(cube);
                    uCW(cube);
                }
                if (i == 3 && j == 1){
                    dCW(cube);
                    fCW(cube);
                    rCW(cube);
                    fCCW(cube);
                }
                if (i == 3 && j == 3){
                    fCCW(cube);
                    lCCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 5){
                    fCW(cube);
                    rCW(cube);
                    fCCW(cube);
                }
                if (i == 3 && j == 7){
                    fCW(cube);
                    dCCW(cube);
                    rCW(cube);
                    fCCW(cube);
                }
                if (i == 4 && j == 1){
                    uCCW(cube);
                }
                if (i == 4 && j == 3){
                    lCW(cube);
                    uCCW(cube);
                }
                if (i == 4 && j == 5){
                    lCCW(cube);
                    uCCW(cube);
                }
                if (i == 4 && j == 7){
                    lCW(cube);
                    lCW(cube);
                    uCCW(cube);
                }
                if (i == 5 && j == 1){
                    bCW(cube);
                    bCW(cube);
                    uCW(cube);
                    uCW(cube);
                }
                if (i == 5 && j == 3){
                    bCCW(cube);
                    uCW(cube);
                    uCW(cube);
                }
                if (i == 5 && j == 5){
                    bCW(cube);
                    uCW(cube);
                    uCW(cube);
                }
                if (i == 5 && j == 7){
                    uCW(cube);
                    uCW(cube);
                }
            }
        }
    }



    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'G'){
                if (i == 0 && j == 3){
                    lCW(cube);
                    fCW(cube);
                    fCW(cube);
                    lCCW(cube);
                    fCW(cube);
                    fCW(cube);
                }
                if (i == 0 && j == 5){
                    continue;
                }
                if (i == 0 && j == 7){
                    dCW(cube);
                    fCW(cube);
                    dCCW(cube);
                    fCCW(cube);
                }
                if (i == 1 && j == 1){
                    uCW(cube);
                    rCCW(cube);
                    uCCW(cube);
                }
                if (i == 1 && j == 3){
                    uCW(cube);
                    uCW(cube);
                    rCCW(cube);
                    uCW(cube);
                    uCW(cube);
                }
                if (i == 1 && j == 5){
                    rCCW(cube);
                }
                if (i == 2 && j == 1){
                    fCCW(cube);
                    uCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 3) {
                    rCW(cube);
                    fCCW(cube);
                    uCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 5){
                    rCCW(cube);
                    fCCW(cube);
                    uCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 7){
                    rCW(cube);
                    rCW(cube);
                    fCCW(cube);
                    uCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 1){
                    dCW(cube);
                    rCW(cube);
                }
                if (i == 3 && j == 3){
                    dCW(cube);
                    dCW(cube);
                    rCW(cube);
                }
                if (i == 3 && j == 5){
                    rCW(cube);
                }
                if (i == 3 && j == 7){
                    dCCW(cube);
                    rCW(cube);
                }

                if (i == 4 && j == 1){
                    fCCW(cube);
                    uCCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 3){
                    lCW(cube);
                    fCCW(cube);
                    uCCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 5){
                    lCCW(cube);
                    fCCW(cube);
                    uCCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 7){
                    lCW(cube);
                    lCW(cube);
                    fCCW(cube);
                    uCCW(cube);
                    fCW(cube);
                }
                if (i == 5 && j == 1){
                    bCW(cube);
                    rCW(cube);
                    rCW(cube);
                }
                if (i == 5 && j == 3){
                    bCW(cube);
                    bCW(cube);
                    rCW(cube);
                    rCW(cube);
                }
                if (i == 5 && j == 5){
                    rCW(cube);
                    rCW(cube);
                }
                if (i == 5 && j == 7){
                    bCCW(cube);
                    uCW(cube);
                    rCW(cube);
                    rCW(cube);
                }
            }
        }
    }



    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'O'){
                if (i == 0 && j == 3){
                    lCW(cube);
                    fCW(cube);
                    lCCW(cube);
                    fCCW(cube);
                }
                if (i == 0 && j == 7){
                    continue;
                }
                if (i == 1 && j == 1){
                    bCW(cube);
                    lCCW(cube);
                    dCW(cube);
                }
                if (i == 1 && j == 3){
                    fCW(cube);
                    lCW(cube);
                    fCCW(cube);
                }
                if (i == 1 && j == 5){
                    fCCW(cube);
                    rCCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 1){
                    fCW(cube);
                    fCW(cube);
                    uCW(cube);
                    fCW(cube);
                    fCW(cube);
                }
                if (i == 2 && j == 5){
                    rCW(cube);
                    dCCW(cube);
                    rCCW(cube);
                }
                if (i == 2 && j == 7){
                    dCCW(cube);
                }
                if (i == 3 && j == 1){
                    dCW(cube);
                    fCCW(cube);
                    rCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 3){
                    fCW(cube);
                    lCCW(cube);
                    fCCW(cube);
                }
                if (i == 3 && j == 5){
                    fCCW(cube);
                    rCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 7){
                    fCCW(cube);
                    dCCW(cube);
                    rCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 1){
                    lCW(cube);
                    lCW(cube);
                    dCW(cube);
                }
                if (i == 4 && j == 3){
                    lCCW(cube);
                    dCW(cube);
                }
                if (i == 4 && j == 5){
                    lCW(cube);
                    dCW(cube);
                }
                if (i == 4 && j == 7){
                    dCW(cube);
                }
                if (i == 5 && j == 1){
                    dCW(cube);
                    dCW(cube);
                }
                if (i == 5 && j == 3){
                    bCW(cube);
                    dCW(cube);
                    dCW(cube);
                }
                if (i == 5 && j == 5){
                    bCCW(cube);
                    dCW(cube);
                    dCW(cube);
                }
                if (i == 5 && j == 7){
                    bCW(cube);
                    bCW(cube);
                    dCW(cube);
                    dCW(cube);
                }
            }
        }
    }



    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'B'){
                if (i == 0 && j == 3){
                    continue;
                }
                if (i == 1 && j == 1){
                    uCCW(cube);
                    lCW(cube);
                    uCW(cube);
                }
                if (i == 1 && j == 3){
                    lCW(cube);
                }
                if (i == 1 && j == 5){
                    uCW(cube);
                    uCW(cube);
                    lCW(cube);
                    uCW(cube);
                    uCW(cube);
                }
                if (i == 2 && j == 1){
                    fCW(cube);
                    uCW(cube);
                    fCCW(cube);
                }
                if (i == 2 && j == 5){
                    bCW(cube);
                    uCCW(cube);
                    lCW(cube);
                    uCW(cube);
                }
                if (i == 2 && j == 7){
                    fCCW(cube);
                    dCCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 3){
                    lCCW(cube);
                }
                if (i == 3 && j == 5){
                    fCW(cube);
                    fCW(cube);
                    rCW(cube);
                    fCW(cube);
                    fCW(cube);
                }
                if (i == 3 && j == 7){
                    dCW(cube);
                    lCCW(cube);
                    dCCW(cube);
                }
                if (i == 4 && j == 1){
                    lCW(cube);
                    fCCW(cube);
                    dCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 3){
                    fCW(cube);
                    lCW(cube);
                    uCCW(cube);
                    lCCW(cube);
                    fCCW(cube);
                }
                if (i == 4 && j == 5){
                    lCW(cube);
                    fCCW(cube);
                    dCW(cube);
                    fCW(cube);
                }
                if (i == 4 && j == 7){
                    fCCW(cube);
                    dCW(cube);
                    fCW(cube);
                }

                if (i == 5 && j == 1){
                    bCCW(cube);
                    lCW(cube);
                    lCW(cube);
                }
                if (i == 5 && j == 3){
                    lCW(cube);
                    lCW(cube);
                }
                if (i == 5 && j == 5){
                    bCW(cube);
                    bCW(cube);
                    lCW(cube);
                    lCW(cube);
                }
                if (i == 5 && j == 7){
                    bCW(cube);
                    lCW(cube);
                    lCW(cube);
                }
            }
        }
    }
}


