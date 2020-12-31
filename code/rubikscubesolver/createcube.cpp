#include "createcube.h"
#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
void TakeInput(string color, std::array<std::array<char,9>, 6> &cube, int colorIndex);
void CubeScramble(std::array<std::array<char,9>, 6> &cube);
void PrintCube(std::array<std::array<char,9>, 6> &cube);
void OriginalState(std::array<std::array<char,9>, 6> &cube);
void FCW(std::array<std::array<char,9>, 6> &cube);
void FCCW(std::array<std::array<char,9>, 6> &cube);
void BCW(std::array<std::array<char,9>, 6> &cube);
void BCCW(std::array<std::array<char,9>, 6> &cube);
void UCW(std::array<std::array<char,9>, 6> &cube);
void UCCW(std::array<std::array<char,9>, 6> &cube);
void DCW(std::array<std::array<char,9>, 6> &cube);
void DCCW(std::array<std::array<char,9>, 6> &cube);
void LCW(std::array<std::array<char,9>, 6> &cube);
void LCCW(std::array<std::array<char,9>, 6> &cube);
void RCW(std::array<std::array<char,9>, 6> &cube);
void RCCW(std::array<std::array<char,9>, 6> &cube);
void CWFaceTurn(std::array<std::array<char,9>, 6> &cube, int colorIndex);
void PieceTypeCheck(std::array<std::array<char,9>, 6> &cube, int colorIndex, int i, int j);

void CubeGen(){
    /*Cube Order: Same as color enum*/
    std::array<std::array<char,9>,6> cube;
    /*
    cout << "White - Front, Red - Up, Green - Right, Orange - Down, Blue - Left,  Yellow - Back\n";
    cout << "Enter cubies for each side from top left to bottom right\n";
    cout << "Enter it in this format, white - W, red - R, green - G, orange - O, blue - B,  yellow - Y, \n";
    TakeInput("White", cube, 0);
    TakeInput("Red", cube, 1);
    TakeInput("Green", cube, 2);
    TakeInput("Orange", cube, 3);
    TakeInput("Blue", cube, 4);
    TakeInput("Yellow", cube, 5);
    */

    OriginalState(cube);
    CubeScramble(cube);

    /* Rotation Notation: Everything based on Front (White Side).
     * Cube needs to initially be in the correct orientation.
     * To view red, rotate cube by 90 degrees down from white.
     * To view green, rotate cube by 90 degrees left from white.
     * To view orange, rotate cube by 90 degrees up from white.
     * To view yellow, rotate cube by 180 degrees up from white.
    */

    PrintCube(cube);

}

void TakeInput(string color, std::array<std::array<char,9>, 6> &cube, int colorIndex){
    cout << "Enter in the " << color << " side:";
    for (int i = 0; i < 9; i++){
        cin >> cube[colorIndex][i];
    }
}

void OriginalState(std::array<std::array<char,9>, 6> &cube){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (i == 0) cube[i][j] = 'W';
            if (i == 1) cube[i][j] = 'R';
            if (i == 2) cube[i][j] = 'G';
            if (i == 3) cube[i][j] = 'O';
            if (i == 4) cube[i][j] = 'B';
            if (i == 5) cube[i][j] = 'Y';
        }
    }
}

void PrintCube(std::array<std::array<char,9>, 6> &cube){
    std::array<string,6> side = {"Front", "Up", "Right", "Down", "Left", "Back"};

    cout << "\n";

    for (int i = 0; i < 6; i++){
        cout << side[i] << endl;
        for (int j = 0; j < 9; j++){
            cout << cube[i][j];
            if ((j+1) % 3 == 0){
                cout << endl;
            }
        }
        cout << endl;
    }
}

void CubeScramble(std::array<std::array<char,9>, 6> &cube){
    srand(time(0));
    for (int i = 0; i < 30; i++){
        int num = rand() % 12;
        if (num == 0){
            FCW(cube);
            cout << "F ";
        }
        else if (num == 1){
            FCCW(cube);
            cout << "F' ";
        }
        else if (num == 2){
            BCW(cube);
            cout << "B ";
        }
        else if (num == 3){
            BCCW(cube);
            cout << "B' ";
        }
        else if (num == 4){
            UCW(cube);
            cout << "U ";
        }
        else if (num == 5){
            UCCW(cube);
            cout << "U' ";
        }
        else if (num == 6){
            DCW(cube);
            cout << "D ";
        }
        else if (num == 7){
            DCCW(cube);
            cout << "D' ";
        }
        else if (num == 8){
            LCW(cube);
            cout << "L ";
        }
        else if (num == 9){
            LCCW(cube);
            cout << "L' ";
        }
        else if (num == 10){
            RCW(cube);
            cout << "R ";
        }
        else if (num == 11){
            RCCW(cube);
            cout << "R' ";
        }
    }
    cout << "\n\n";
}

void FCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[1][6] = temp[4][8];
    cube[1][7] = temp[4][5];
    cube[1][8] = temp[4][2];
    cube[2][0] = temp[1][6];
    cube[2][3] = temp[1][7];
    cube[2][6] = temp[1][8];
    cube[2][3] = temp[1][7];
    cube[3][0] = temp[2][6];
    cube[3][1] = temp[2][3];
    cube[3][2] = temp[2][0];
    cube[4][2] = temp[3][0];
    cube[4][5] = temp[3][1];
    cube[4][8] = temp[3][2];

    CWFaceTurn(cube, 0);
}

void FCCW(std::array<std::array<char,9>, 6> &cube){
    FCW(cube);
    FCW(cube);
    FCW(cube);
}

void BCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[1][0] = temp[2][2];
    cube[1][1] = temp[2][5];
    cube[1][2] = temp[2][8];
    cube[2][2] = temp[3][8];
    cube[2][5] = temp[3][7];
    cube[2][8] = temp[3][6];
    cube[3][6] = temp[4][0];
    cube[3][7] = temp[4][3];
    cube[3][8] = temp[4][6];
    cube[4][0] = temp[1][2];
    cube[4][3] = temp[1][1];
    cube[4][6] = temp[1][0];

    CWFaceTurn(cube, 5);
}

void BCCW(std::array<std::array<char,9>, 6> &cube){
    BCW(cube);
    BCW(cube);
    BCW(cube);
}

void UCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][0] = temp[2][0];
    cube[0][1] = temp[2][1];
    cube[0][2] = temp[2][2];
    cube[2][0] = temp[5][8];
    cube[2][1] = temp[5][7];
    cube[2][2] = temp[5][6];
    cube[4][0] = temp[0][0];
    cube[4][1] = temp[0][1];
    cube[4][2] = temp[0][2];
    cube[5][6] = temp[4][2];
    cube[5][7] = temp[4][1];
    cube[5][8] = temp[4][0];

    CWFaceTurn(cube, 1);
}

void UCCW(std::array<std::array<char,9>, 6> &cube){
    UCW(cube);
    UCW(cube);
    UCW(cube);
}

void DCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][6] = temp[4][6];
    cube[0][7] = temp[4][7];
    cube[0][8] = temp[4][8];
    cube[2][6] = temp[0][6];
    cube[2][7] = temp[0][7];
    cube[2][8] = temp[0][8];
    cube[4][6] = temp[5][2];
    cube[4][7] = temp[5][1];
    cube[4][8] = temp[5][0];
    cube[5][0] = temp[2][8];
    cube[5][1] = temp[2][7];
    cube[5][2] = temp[2][6];

    CWFaceTurn(cube, 3);
}

void DCCW(std::array<std::array<char,9>, 6> &cube){
    DCW(cube);
    DCW(cube);
    DCW(cube);
}

void LCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][0] = temp[1][0];
    cube[0][3] = temp[1][3];
    cube[0][6] = temp[1][6];
    cube[1][0] = temp[5][0];
    cube[1][3] = temp[5][3];
    cube[1][6] = temp[5][6];
    cube[3][0] = temp[0][0];
    cube[3][3] = temp[0][3];
    cube[3][6] = temp[0][6];
    cube[5][0] = temp[3][0];
    cube[5][3] = temp[3][3];
    cube[5][6] = temp[3][6];

    CWFaceTurn(cube, 4);
}

void LCCW(std::array<std::array<char,9>, 6> &cube){
    LCW(cube);
    LCW(cube);
    LCW(cube);
}

void RCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][2] = temp[3][2];
    cube[0][5] = temp[3][5];
    cube[0][8] = temp[3][8];
    cube[1][2] = temp[0][2];
    cube[1][5] = temp[0][5];
    cube[1][8] = temp[0][8];
    cube[3][2] = temp[5][2];
    cube[3][5] = temp[5][5];
    cube[3][8] = temp[5][8];
    cube[5][2] = temp[1][2];
    cube[5][5] = temp[1][5];
    cube[5][8] = temp[1][8];

    CWFaceTurn(cube, 2);
}

void RCCW(std::array<std::array<char,9>, 6> &cube){
    RCW(cube);
    RCW(cube);
    RCW(cube);
}

void CWFaceTurn(std::array<std::array<char,9>, 6> &cube, int colorIndex){
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[colorIndex][0] = temp[colorIndex][6];
    cube[colorIndex][1] = temp[colorIndex][3];
    cube[colorIndex][2] = temp[colorIndex][0];
    cube[colorIndex][3] = temp[colorIndex][7];
    cube[colorIndex][5] = temp[colorIndex][1];
    cube[colorIndex][6] = temp[colorIndex][8];
    cube[colorIndex][7] = temp[colorIndex][5];
    cube[colorIndex][8] = temp[colorIndex][2];
}

void PieceTypeCheck(std::array<std::array<char,9>, 6> &cube, int colorIndex, int i, int j){

}
