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
}


