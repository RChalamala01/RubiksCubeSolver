#include <array>

#include "crosssolver.h"
#include "rotations.h"


int pieceTypeCheck(int j){
    //checks what type of piece is being looked at.
    if (j == 4){
        return 0; //center piece
    }
    else if (j % 2 == 1){
        return 1; //edge piece
    }
    else{
        return 2; //corner piece
    }
}

char findAdj(std::array<std::array<char,9>, 6> &cube, int i, int j){
    //finds the adjacent edge color.

    //if we're looking at a white edge.
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

    //if we're looking at a red edge.
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

    //if we're looking at a green edge.
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

    //if we're looking at a orange edge.
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

    //if we're looking at a blue edge.
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

    //if we're looking at a yellow edge.
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

bool cubeCheck(std::array<std::array<char,9>, 6> &cube){
    //checks if the white cross is complete.
    if (cube[0][0] != 'W') return false;
    if (cube[0][1] != 'W') return false;
    if (cube[0][2] != 'W') return false;
    if (cube[0][3] != 'W') return false;
    if (cube[0][4] != 'W') return false;
    if (cube[0][5] != 'W') return false;
    if (cube[0][6] != 'W') return false;
    if (cube[0][7] != 'W') return false;
    if (cube[0][8] != 'W') return false;

    if (cube[1][0] != 'R') return false;
    if (cube[1][1] != 'R') return false;
    if (cube[1][2] != 'R') return false;
    if (cube[1][3] != 'R') return false;
    if (cube[1][4] != 'R') return false;
    if (cube[1][5] != 'R') return false;
    if (cube[1][6] != 'R') return false;
    if (cube[1][7] != 'R') return false;
    if (cube[1][8] != 'R') return false;

    if (cube[2][0] != 'G') return false;
    if (cube[2][1] != 'G') return false;
    if (cube[2][2] != 'G') return false;
    if (cube[2][3] != 'G') return false;
    if (cube[2][4] != 'G') return false;
    if (cube[2][5] != 'G') return false;
    if (cube[2][6] != 'G') return false;
    if (cube[2][7] != 'G') return false;
    if (cube[2][8] != 'G') return false;

    if (cube[3][0] != 'O') return false;
    if (cube[3][1] != 'O') return false;
    if (cube[3][2] != 'O') return false;
    if (cube[3][3] != 'O') return false;
    if (cube[3][4] != 'O') return false;
    if (cube[3][5] != 'O') return false;
    if (cube[3][6] != 'O') return false;
    if (cube[3][7] != 'O') return false;
    if (cube[3][8] != 'O') return false;

    if (cube[4][0] != 'B') return false;
    if (cube[4][1] != 'B') return false;
    if (cube[4][2] != 'B') return false;
    if (cube[4][3] != 'B') return false;
    if (cube[4][4] != 'B') return false;
    if (cube[4][5] != 'B') return false;
    if (cube[4][6] != 'B') return false;
    if (cube[4][7] != 'B') return false;
    if (cube[4][8] != 'B') return false;

    if (cube[5][0] != 'Y') return false;
    if (cube[5][1] != 'Y') return false;
    if (cube[5][2] != 'Y') return false;
    if (cube[5][3] != 'Y') return false;
    if (cube[5][4] != 'Y') return false;
    if (cube[5][5] != 'Y') return false;
    if (cube[5][6] != 'Y') return false;
    if (cube[5][7] != 'Y') return false;
    if (cube[5][8] != 'Y') return false;

    return true;
}

void solveCross(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray){
    //solves the white cross

    //to place the red and white piece.
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
                    fCW(cube, solveArray);
                }
                if (i == 0 && j == 5){
                    fCCW(cube, solveArray);
                }
                if (i == 0 && j == 7){
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 1 && j == 1){
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 1 && j == 3){
                    fCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 1 && j == 5){
                    fCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 1 && j == 7){
                    uCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 1){
                    uCW(cube, solveArray);
                }
                if (i == 2 && j == 3){
                    rCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 2 && j == 5){
                    rCCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 2 && j == 7){
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 3 && j == 1){
                    dCW(cube, solveArray);
                    fCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 3 && j == 3){
                    fCCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 5){
                    fCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 3 && j == 7){
                    fCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 4 && j == 1){
                    uCCW(cube, solveArray);
                }
                if (i == 4 && j == 3){
                    lCW(cube, solveArray);
                    uCCW(cube, solveArray);
                }
                if (i == 4 && j == 5){
                    lCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                }
                if (i == 4 && j == 7){
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                    uCCW(cube, solveArray);
                }
                if (i == 5 && j == 1){
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 5 && j == 3){
                    bCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 5 && j == 5){
                    bCW(cube, solveArray);
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 5 && j == 7){
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
            }
        }
    }


    //to place the green and white piece.
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'G'){
                if (i == 0 && j == 3){
                    lCW(cube, solveArray);
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 0 && j == 5){
                    continue;
                }
                if (i == 0 && j == 7){
                    dCW(cube, solveArray);
                    fCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 1 && j == 1){
                    uCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                }
                if (i == 1 && j == 3){
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 1 && j == 5){
                    rCCW(cube, solveArray);
                }
                if (i == 2 && j == 1){
                    fCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 3) {
                    rCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 5){
                    rCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 7){
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 1){
                    dCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
                if (i == 3 && j == 3){
                    dCW(cube, solveArray);
                    dCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
                if (i == 3 && j == 5){
                    rCW(cube, solveArray);
                }
                if (i == 3 && j == 7){
                    dCCW(cube, solveArray);
                    rCW(cube, solveArray);
                }

                if (i == 4 && j == 1){
                    fCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 4 && j == 3){
                    lCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 4 && j == 5){
                    lCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 4 && j == 7){
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 5 && j == 1){
                    bCW(cube, solveArray);
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
                if (i == 5 && j == 3){
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
                if (i == 5 && j == 5){
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
                if (i == 5 && j == 7){
                    bCCW(cube, solveArray);
                    rCW(cube, solveArray);
                    rCW(cube, solveArray);
                }
            }
        }
    }


    //to place the orange and white piece.
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if ((pieceTypeCheck(j) != 1) || (cube[i][j] != 'W')){
                continue;
            }
            if (findAdj(cube,i,j) == 'O'){
                if (i == 0 && j == 3){
                    lCW(cube, solveArray);
                    fCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 0 && j == 7){
                    continue;
                }
                if (i == 1 && j == 1){
                    bCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 1 && j == 3){
                    fCW(cube, solveArray);
                    lCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 1 && j == 5){
                    fCCW(cube, solveArray);
                    rCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 1){
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 2 && j == 5){
                    rCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    rCCW(cube, solveArray);
                }
                if (i == 2 && j == 7){
                    dCCW(cube, solveArray);
                }
                if (i == 3 && j == 1){
                    dCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 3){
                    fCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 3 && j == 5){
                    fCCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 7){
                    fCCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 4 && j == 1){
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 4 && j == 3){
                    lCCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 4 && j == 5){
                    lCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 4 && j == 7){
                    dCW(cube, solveArray);
                }
                if (i == 5 && j == 1){
                    dCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 5 && j == 3){
                    bCW(cube, solveArray);
                    dCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 5 && j == 5){
                    bCCW(cube, solveArray);
                    dCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
                if (i == 5 && j == 7){
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    dCW(cube, solveArray);
                    dCW(cube, solveArray);
                }
            }
        }
    }


    //to place the blue and white piece.
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
                    uCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 1 && j == 3){
                    lCW(cube, solveArray);
                }
                if (i == 1 && j == 5){
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                    lCW(cube, solveArray);
                    uCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 2 && j == 1){
                    fCW(cube, solveArray);
                    uCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 2 && j == 5){
                    bCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    uCW(cube, solveArray);
                }
                if (i == 2 && j == 7){
                    fCCW(cube, solveArray);
                    dCCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 3){
                    lCCW(cube, solveArray);
                }
                if (i == 3 && j == 5){
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                    rCW(cube, solveArray);
                    fCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 3 && j == 7){
                    dCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    dCCW(cube, solveArray);
                }
                if (i == 4 && j == 1){
                    fCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 4 && j == 3){
                    fCW(cube, solveArray);
                    lCW(cube, solveArray);
                    uCCW(cube, solveArray);
                    lCCW(cube, solveArray);
                    fCCW(cube, solveArray);
                }
                if (i == 4 && j == 5){
                    lCW(cube, solveArray);
                    fCCW(cube, solveArray);
                    dCW(cube, solveArray);
                    fCW(cube, solveArray);
                }
                if (i == 4 && j == 7){
                    fCCW(cube, solveArray);
                    dCW(cube, solveArray);
                    fCW(cube, solveArray);
                }

                if (i == 5 && j == 1){
                    bCCW(cube, solveArray);
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                }
                if (i == 5 && j == 3){
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                }
                if (i == 5 && j == 5){
                    bCW(cube, solveArray);
                    bCW(cube, solveArray);
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                }
                if (i == 5 && j == 7){
                    bCW(cube, solveArray);
                    lCW(cube, solveArray);
                    lCW(cube, solveArray);
                }
            }
        }
    }
}

