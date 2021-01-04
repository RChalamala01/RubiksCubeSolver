#ifndef RUBIKSCUBESOLVER_F2LSOLVER_H
#define RUBIKSCUBESOLVER_F2LSOLVER_H

void solveCorners(std::array<std::array<char,9>, 6> &cube);
void cornerColors(std::array<std::array<char,9>, 6> &cube, std::array<char,3> &colorArray, int i, int j);

#endif //RUBIKSCUBESOLVER_F2LSOLVER_H
