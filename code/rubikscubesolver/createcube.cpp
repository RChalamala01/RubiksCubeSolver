#include "createcube.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#include "rotations.h"

using namespace std;

void cubeGen(){
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

    originalState(cube);
    cubeScramble(cube);

    /* Rotation Notation: Everything based on Front (White Side).
     * Cube needs to initially be in the correct orientation.
     * To view red, rotate cube by 90 degrees down from white.
     * To view green, rotate cube by 90 degrees left from white.
     * To view orange, rotate cube by 90 degrees up from white.
     * To view yellow, rotate cube by 180 degrees up from white.
    */

    //PrintCube(cube);
    //SolveCross(cube);
    printCube(cube);

}

void takeInput(string color, std::array<std::array<char,9>, 6> &cube, int colorIndex){
    cout << "Enter in the " << color << " side:";
    for (int i = 0; i < 9; i++){
        cin >> cube[colorIndex][i];
    }
}

void originalState(std::array<std::array<char,9>, 6> &cube){
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

void printCube(std::array<std::array<char,9>, 6> &cube){
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

void cubeScramble(std::array<std::array<char,9>, 6> &cube){
    //std:: mt19937
    srand(time(nullptr));
    for (int i = 0; i < 30; i++){
        int num = rand() % 12;
        if (num == 0){
            fCW(cube);
            cout << "F ";
        }
        else if (num == 1){
            fCCW(cube);
            cout << "F' ";
        }
        else if (num == 2){
            bCW(cube);
            cout << "B ";
        }
        else if (num == 3){
            bCCW(cube);
            cout << "B' ";
        }
        else if (num == 4){
            uCW(cube);
            cout << "U ";
        }
        else if (num == 5){
            uCCW(cube);
            cout << "U' ";
        }
        else if (num == 6){
            dCW(cube);
            cout << "D ";
        }
        else if (num == 7){
            dCCW(cube);
            cout << "D' ";
        }
        else if (num == 8){
            lCW(cube);
            cout << "L ";
        }
        else if (num == 9){
            lCCW(cube);
            cout << "L' ";
        }
        else if (num == 10){
            rCW(cube);
            cout << "R ";
        }
        else if (num == 11){
            rCCW(cube);
            cout << "R' ";
        }
    }
    cout << "\n";
}


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
/*
char findAdj(std::array<std::array<char,9>, 6> &cube){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if (j % 2 != 1){
                continue;
            }
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
                    return cube[3][1];
                }
                if (j == 3){

                }
                if (j == 5){

                }
                if (j == 7){

                }
            }
            if (i == 2){
                if (j == 1){

                }
                if (j == 3){

                }
                if (j == 5){

                }
                if (j == 7){

                }
            }
            if (i == 3){
                if (j == 1){

                }
                if (j == 3){

                }
                if (j == 5){

                }
                if (j == 7){

                }
            }
            if (i == 4){
                if (j == 1){

                }
                if (j == 3){

                }
                if (j == 5){

                }
                if (j == 7){

                }
            }
            if (i == 5){
                if (j == 1){

                }
                if (j == 3){

                }
                if (j == 5){

                }
                if (j == 7){

                }
            }

        }
    }
}

void solveCross(std::array<std::array<char,9>, 6> &cube){
    while (crossCheck(cube) != 1) {

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
 */