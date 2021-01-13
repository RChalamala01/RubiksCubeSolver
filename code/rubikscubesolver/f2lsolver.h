#ifndef RUBIKSCUBESOLVER_F2LSOLVER_H
#define RUBIKSCUBESOLVER_F2LSOLVER_H

void solveCorners(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray);
void cornerColors(std::array<std::array<char,9>, 6> &cube, std::array<char,3> &colorArray, int i, int j);
void solveLayerTwo(std::array<std::array<char,9>, 6> &cube, std::vector<std::string> &solveArray);
void placeRed(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray);
void placeGreen(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray);
void placeOrange(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray);
void placeBlue(std::array<std::array<char,9>, 6> &cube, int i, std::vector<std::string> &solveArray);

#endif //RUBIKSCUBESOLVER_F2LSOLVER_H
