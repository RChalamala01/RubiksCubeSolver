#ifndef RUBIKSCUBESOLVER_ROTATIONS_H
#define RUBIKSCUBESOLVER_ROTATIONS_H

#include <array>

void fCW(std::array<std::array<char,9>, 6> &cube);
void fCCW(std::array<std::array<char,9>, 6> &cube);
void bCW(std::array<std::array<char,9>, 6> &cube);
void bCCW(std::array<std::array<char,9>, 6> &cube);
void uCW(std::array<std::array<char,9>, 6> &cube);
void uCCW(std::array<std::array<char,9>, 6> &cube);
void dCW(std::array<std::array<char,9>, 6> &cube);
void dCCW(std::array<std::array<char,9>, 6> &cube);
void lCW(std::array<std::array<char,9>, 6> &cube);
void lCCW(std::array<std::array<char,9>, 6> &cube);
void rCW(std::array<std::array<char,9>, 6> &cube);
void rCCW(std::array<std::array<char,9>, 6> &cube);
void faceTurnCW(std::array<std::array<char,9>, 6> &cube, int colorIndex);

#endif //RUBIKSCUBESOLVER_ROTATIONS_H
