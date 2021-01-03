#include "createcube.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#include "rotations.h"

void cubeGen(std::array<std::array<char,9>, 6> &cube){

    std::cout << "White - Front, Red - Up, Green - Right, Orange - Down, Blue - Left,  Yellow - Back\n";
    std::cout << "Enter cubies for each side from top left to bottom right\n";
    std::cout << "Enter it in this format, white - W, red - R, green - G, orange - O, blue - B,  yellow - Y, \n";
    takeInput("White", cube, 0);
    takeInput("Red", cube, 1);
    takeInput("Green", cube, 2);
    takeInput("Orange", cube, 3);
    takeInput("Blue", cube, 4);
    takeInput("Yellow", cube, 5);

}

void takeInput(std::string color, std::array<std::array<char,9>, 6> &cube, int colorIndex){
    std::cout << "Enter in the " << color << " side:";
    for (int i = 0; i < 9; i++){
        std::cin >> cube[colorIndex][i];
    }
}

void originalState(std::array<std::array<char,9>, 6> &cube){
    //sets the solved state, or original state of the cube.
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
    //prints out the cube.
    std::array<std::string,6> side = {"Front", "Up", "Right", "Down", "Left", "Back"};

    std::cout << "\n";

    for (int i = 0; i < 6; i++){
        std::cout << side[i] << std::endl;
        for (int j = 0; j < 9; j++){
            std::cout << cube[i][j];
            if ((j+1) % 3 == 0){
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void cubeScramble(std::array<std::array<char,9>, 6> &cube){
    //scrambles the cube by randomly picking one of 12 rotation functions.
    srand(time(nullptr));
    for (int i = 0; i < 30; i++){
        int num = rand() % 12;
        if (num == 0){
            fCW(cube);
        }
        else if (num == 1){
            fCCW(cube);
        }
        else if (num == 2){
            bCW(cube);
        }
        else if (num == 3){
            bCCW(cube);
        }
        else if (num == 4){
            uCW(cube);
        }
        else if (num == 5){
            uCCW(cube);
        }
        else if (num == 6){
            dCW(cube);
        }
        else if (num == 7){
            dCCW(cube);
        }
        else if (num == 8){
            lCW(cube);
        }
        else if (num == 9){
            lCCW(cube);
        }
        else if (num == 10){
            rCW(cube);
        }
        else if (num == 11){
            rCCW(cube);
        }
    }
    std::cout << "\n";
}


