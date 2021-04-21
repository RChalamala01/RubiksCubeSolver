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

void takeInput(const std::string color, std::array<std::array<char,9>, 6> &cube, int colorIndex){
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
            if (cube[i][j] == 'R'){
                std::cout << "\033[48;2;170;0;0m" << "  ";
                std::cout << "\033[0m";
            }
            else if (cube[i][j] == 'B'){
                std::cout << "\033[48;2;0;0;255m" << "  ";
                std::cout << "\033[0m";
            }
            else if (cube[i][j] == 'Y'){
                std::cout << "\033[48;2;229;229;16m" << "  ";
                std::cout << "\033[0m";
            }
            else if (cube[i][j] == 'G'){
                std::cout << "\033[48;2;0;170;0m" << "  ";
                std::cout << "\033[0m";
            }
            else if (cube[i][j] == 'O'){
                std::cout << "\033[48;2;252;127;0m" << "  ";
                std::cout << "\033[0m";
            }
            else if (cube[i][j] == 'W'){
                std::cout << "\033[48;2;255;255;255m" << "  ";
                std::cout << "\033[0m";
            }

            if ((j+1) % 3 == 0){
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void cubeScramble(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &scrambleArray){
    //scrambles the cube by randomly picking one of 12 rotation functions.
    srand(time(nullptr));
    //srand(9);
    for (int i = 0; i < 20; i++){
        int num = rand() % 12;
        if (num == 0){
            fCW(cube, scrambleArray);
        }
        else if (num == 1){
            fCCW(cube, scrambleArray);
        }
        else if (num == 2){
            bCW(cube, scrambleArray);
        }
        else if (num == 3){
            bCCW(cube, scrambleArray);
        }
        else if (num == 4){
            uCW(cube, scrambleArray);
        }
        else if (num == 5){
            uCCW(cube, scrambleArray);
        }
        else if (num == 6){
            dCW(cube, scrambleArray);
        }
        else if (num == 7){
            dCCW(cube, scrambleArray);
        }
        else if (num == 8){
            lCW(cube, scrambleArray);
        }
        else if (num == 9){
            lCCW(cube, scrambleArray);
        }
        else if (num == 10){
            rCW(cube, scrambleArray);
        }
        else if (num == 11){
            rCCW(cube, scrambleArray);
        }
    }
    std::cout << "\n";
}


