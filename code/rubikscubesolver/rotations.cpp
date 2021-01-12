#include <array>
#include "rotations.h"
#include <iostream>

//all of these moves are based on the standard rubik's notation for moves.

void fCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a front clockwise move.

    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[1][6] = temp[4][8];
    cube[1][7] = temp[4][5];
    cube[1][8] = temp[4][2];
    cube[2][0] = temp[1][6];
    cube[2][3] = temp[1][7];
    cube[2][6] = temp[1][8];
    cube[3][0] = temp[2][6];
    cube[3][1] = temp[2][3];
    cube[3][2] = temp[2][0];
    cube[4][2] = temp[3][0];
    cube[4][5] = temp[3][1];
    cube[4][8] = temp[3][2];

    faceTurnCW(cube, 0);
    std::cout << "F ";
}

void fCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a front counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[1][6] = temp[2][0];
    cube[1][7] = temp[2][3];
    cube[1][8] = temp[2][6];
    cube[2][0] = temp[3][2];
    cube[2][3] = temp[3][1];
    cube[2][6] = temp[3][0];
    cube[3][0] = temp[4][2];
    cube[3][1] = temp[4][5];
    cube[3][2] = temp[4][8];
    cube[4][2] = temp[1][8];
    cube[4][5] = temp[1][7];
    cube[4][8] = temp[1][6];

    faceTurnCCW(cube, 0);
    std::cout << "F' ";
}

void bCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a back clockwise move.
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

    faceTurnCW(cube, 5);
    std::cout << "B ";
}

void bCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a back counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[1][0] = temp[4][6];
    cube[1][1] = temp[4][3];
    cube[1][2] = temp[4][0];
    cube[2][2] = temp[1][0];
    cube[2][5] = temp[1][1];
    cube[2][8] = temp[1][2];
    cube[3][6] = temp[2][8];
    cube[3][7] = temp[2][5];
    cube[3][8] = temp[2][2];
    cube[4][0] = temp[3][6];
    cube[4][3] = temp[3][7];
    cube[4][6] = temp[3][8];

    faceTurnCCW(cube, 5);
    std::cout << "B' ";
}

void uCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a up clockwise move.
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

    faceTurnCW(cube, 1);
    std::cout << "U ";
}

void uCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a up counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][0] = temp[4][0];
    cube[0][1] = temp[4][1];
    cube[0][2] = temp[4][2];
    cube[2][0] = temp[0][0];
    cube[2][1] = temp[0][1];
    cube[2][2] = temp[0][2];
    cube[4][0] = temp[5][8];
    cube[4][1] = temp[5][7];
    cube[4][2] = temp[5][6];
    cube[5][6] = temp[2][2];
    cube[5][7] = temp[2][1];
    cube[5][8] = temp[2][0];

    faceTurnCCW(cube, 1);
    std::cout << "U' ";
}

void dCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a down clockwise move.
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

    faceTurnCW(cube, 3);
    std::cout << "D ";

}

void dCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a down counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][6] = temp[2][6];
    cube[0][7] = temp[2][7];
    cube[0][8] = temp[2][8];
    cube[2][6] = temp[5][2];
    cube[2][7] = temp[5][1];
    cube[2][8] = temp[5][0];
    cube[4][6] = temp[0][6];
    cube[4][7] = temp[0][7];
    cube[4][8] = temp[0][8];
    cube[5][0] = temp[4][8];
    cube[5][1] = temp[4][7];
    cube[5][2] = temp[4][6];

    faceTurnCCW(cube, 3);
    std::cout << "D' ";
}

void lCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a left clockwise move.
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

    faceTurnCW(cube, 4);
    std::cout << "L ";
}

void lCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a left counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][0] = temp[3][0];
    cube[0][3] = temp[3][3];
    cube[0][6] = temp[3][6];
    cube[1][0] = temp[0][0];
    cube[1][3] = temp[0][3];
    cube[1][6] = temp[0][6];
    cube[3][0] = temp[5][0];
    cube[3][3] = temp[5][3];
    cube[3][6] = temp[5][6];
    cube[5][0] = temp[1][0];
    cube[5][3] = temp[1][3];
    cube[5][6] = temp[1][6];

    faceTurnCCW(cube, 4);
    std::cout << "L' ";
}

void rCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a right clockwise move.
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

    faceTurnCW(cube, 2);
    std::cout << "R ";
}

void rCCW(std::array<std::array<char,9>, 6> &cube){
    // performs change in matrix to represent a right counter clockwise move.
    std::array<std::array<char,9>,6> temp;
    temp = cube;

    cube[0][2] = temp[1][2];
    cube[0][5] = temp[1][5];
    cube[0][8] = temp[1][8];
    cube[1][2] = temp[5][2];
    cube[1][5] = temp[5][5];
    cube[1][8] = temp[5][8];
    cube[3][2] = temp[0][2];
    cube[3][5] = temp[0][5];
    cube[3][8] = temp[0][8];
    cube[5][2] = temp[3][2];
    cube[5][5] = temp[3][5];
    cube[5][8] = temp[3][8];

    faceTurnCCW(cube, 2);
    std::cout << "R' ";
}

void faceTurnCW(std::array<std::array<char,9>, 6> &cube, int colorIndex){
    //face of the cube needs to be moved clockwise as well so this is used.

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

void faceTurnCCW(std::array<std::array<char,9>, 6> &cube, int colorIndex){
    //face of the cube needs to be moved counter clockwise as well so this is used.

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

