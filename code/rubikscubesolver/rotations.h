#ifndef RUBIKSCUBESOLVER_ROTATIONS_H
#define RUBIKSCUBESOLVER_ROTATIONS_H

#include <array>

void fCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void fCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void bCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void bCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void uCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void uCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void dCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void dCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void lCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void lCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void rCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void rCCW(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &storeArray);
void faceTurnCW(std::array<std::array<char,9>, 6> &cube, int colorIndex);
void faceTurnCCW(std::array<std::array<char,9>, 6> &cube, int colorIndex);

#endif //RUBIKSCUBESOLVER_ROTATIONS_H
