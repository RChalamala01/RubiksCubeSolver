#ifndef RUBIKSCUBESOLVER_CREATECUBE_H
#define RUBIKSCUBESOLVER_CREATECUBE_H

#include <string>
#include <array>

void cubeGen();
void takeInput(std::string color, std::array<std::array<char,9>, 6> &cube, int colorIndex);
void cubeScramble(std::array<std::array<char,9>, 6> &cube);
void printCube(std::array<std::array<char,9>, 6> &cube);
void originalState(std::array<std::array<char,9>, 6> &cube);


#endif //RUBIKSCUBESOLVER_CREATECUBE_H
