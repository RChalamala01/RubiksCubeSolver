#include "createcube.h"
#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void TakeInput(string color, std::array<std::array<char,9>, 6> &cube, int colorIndex);
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
void CCWFaceTurn(std::array<std::array<char,9>, 6> &cube, int colorIndex);
void CubeScramble(std::array<std::array<char,9>, 6> &cube);

void CubeGen(){
    /*Cube Order: Same as color enum*/
    std::array<std::array<char,9>,6> cube;
    std::array<string,6> side = {"Front", "Up", "Right", "Down", "Left", "Back"};
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

    /* Rotation Notation: Everything based on Front (White Side).
     * Cube needs to initially be in the correct orientation.
     * To view red, rotate cube by 90 degrees down from white.
     * To view green, rotate cube by 90 degrees left from white.
     * To view orange, rotate cube by 90 degrees up from white.
     * To view yellow, rotate cube by 180 degrees up from white.
    */

    CubeScramble(cube);

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

void TakeInput(string color, std::array<std::array<char,9>, 6> &cube, int colorIndex){
    cout << "Enter in the " << color << " side:";
    for (int i = 0; i < 9; i++){
        cin >> cube[colorIndex][i];
    }
}

void CubeScramble(std::array<std::array<char,9>, 6> &cube){
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


D' F' U' B R L F B R' U' F R' D' F' U2 B' F' L2 B' D L D'

void FCW(std::array<std::array<char,9>, 6> &cube){
    std::array<std::array<char,9>,6> temp;
    temp = cube;
    for (int i = 1; i < 5; i++){
        for (int j = 0; j < 9; j++){
            if ((i == 1) && (j == 6)){
                cube[i][j] = temp[4][8];
            }
            else if ((i == 1) && (j == 7)){
                cube[i][j] = temp[4][5];
            }
            else if ((i == 1) && (j == 8)){
                cube[i][j] = temp[4][2];
            }
            else if ((i == 2) && (j == 0)){
                cube[i][j] = temp[i-1][6];
            }
            else if ((i == 2) && (j == 3)){
                cube[i][j] = temp[i-1][7];
            }
            else if ((i == 2) && (j == 6)){
                cube[i][j] = temp[i-1][8];
            }
            else if ((i == 3) && (j == 0)){
                cube[i][j] = temp[i-1][6];
            }
            else if ((i == 3) && (j == 1)){
                cube[i][j] = temp[i-1][3];
            }
            else if ((i == 3) && (j == 2)){
                cube[i][j] = temp[i-1][0];
            }
            else if ((i == 4) && (j == 2)){
                cube[i][j] = temp[i-1][0];
            }
            else if ((i == 4) && (j == 5)){
                cube[i][j] = temp[i-1][1];
            }
            else if ((i == 4) && (j == 8)){
                cube[i][j] = temp[i-1][2];
            }
        }
    }
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
    for (int i = 1; i < 5; i++){
        for (int j = 0; j < 9; j++){
            if ((i == 1) && (j == 0)){
                cube[i][j] = temp[2][2];
            }
            else if ((i == 1) && (j == 1)){
                cube[i][j] = temp[2][5];
            }
            else if ((i == 1) && (j == 2)){
                cube[i][j] = temp[2][8];
            }
            else if ((i == 2) && (j == 2)){
                cube[i][j] = temp[i+1][8];
            }
            else if ((i == 2) && (j == 5)){
                cube[i][j] = temp[i+1][7];
            }
            else if ((i == 2) && (j == 8)){
                cube[i][j] = temp[i+1][6];
            }
            else if ((i == 3) && (j == 6)){
                cube[i][j] = temp[i+1][0];
            }
            else if ((i == 3) && (j == 7)){
                cube[i][j] = temp[i+1][3];
            }
            else if ((i == 3) && (j == 8)){
                cube[i][j] = temp[i+1][6];
            }
            else if ((i == 4) && (j == 0)){
                cube[i][j] = temp[1][2];
            }
            else if ((i == 4) && (j == 3)){
                cube[i][j] = temp[1][1];
            }
            else if ((i == 4) && (j == 6)){
                cube[i][j] = temp[1][0];
            }
        }
    }
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
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            if ( i == 1 || i == 3){
                break;
            }
            else if (i == 0){
                cube[i][j] = temp[2][j];
            }
            else if (i == 2){
                if (j == 0) cube[i][j] = temp[5][8];
                if (j == 1) cube[i][j] = temp[5][7];
                if (j == 2) cube[i][j] = temp[5][6];
            }
            else if (i == 4){
                cube[i][j] = temp[0][j];
            }
            else if (i == 5) {
                if (j == 0) cube[i][j+6] = temp[4][2];
                if (j == 1) cube[i][j+6] = temp[4][1];
                if (j == 2) cube[i][j+6] = temp[4][0];
            }
        }
    }
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
    for (int i = 0; i < 6; i++){
        for (int j = 6; j < 9; j++){
            if ( i == 1 || i == 3){
                break;
            }
            else if (i == 0){
                cube[i][j] = temp[4][j];
            }
            else if (i == 2){
                cube[i][j] = temp[0][j];
            }
            else if (i == 4){
                if (j == 6) cube[i][j] = temp[5][2];
                if (j == 7) cube[i][j] = temp[5][1];
                if (j == 8) cube[i][j] = temp[5][0];
            }
            else if (i == 5) {
                if (j == 6) cube[i][j-6] = temp[2][8];
                if (j == 7) cube[i][j-6] = temp[2][7];
                if (j == 8) cube[i][j-6] = temp[2][6];
            }
        }
    }
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
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (j % 3 != 0){
                continue;
            }
            if (i == 2 || i == 4){
                break;
            }
            else if (i == 0){
                cube[i][j] = temp[1][j];
            }
            else if (i == 1){
                cube[i][j] = temp[5][j];
            }
            else if (i == 3){
                cube[i][j] = temp[0][j];
            }
            else if (i == 5) {
                cube[i][j] = temp[3][j];
            }
        }
    }
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
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (j % 3 != 2){
                continue;
            }
            if ( i == 2 || i == 4){
                break;
            }
            else if (i == 0){
                cube[i][j] = temp[3][j];
            }
            else if (i == 1){
                cube[i][j] = temp[0][j];
            }
            else if (i == 3){
                cube[i][j] = temp[5][j];
            }
            else if (i == 5) {
                cube[i][j] = temp[1][j];
            }
        }
    }
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

void CCWFaceTurn(std::array<std::array<char,9>, 6> &cube, int colorIndex){
    std::array<std::array<char,9>,6> temp;
    temp = cube;
    cube[colorIndex][0] = temp[colorIndex][2];
    cube[colorIndex][1] = temp[colorIndex][5];
    cube[colorIndex][2] = temp[colorIndex][8];
    cube[colorIndex][3] = temp[colorIndex][1];
    cube[colorIndex][5] = temp[colorIndex][7];
    cube[colorIndex][6] = temp[colorIndex][0];
    cube[colorIndex][7] = temp[colorIndex][3];
    cube[colorIndex][8] = temp[colorIndex][6];
}
