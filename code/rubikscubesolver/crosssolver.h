#ifndef RUBIKSCUBESOLVER_CROSSSOLVER_H
#define RUBIKSCUBESOLVER_CROSSSOLVER_H

int pieceTypeCheck(int j);
void solveCross(std::array<std::array<char,9>, 6> &cube);
bool cubeCheck(std::array<std::array<char,9>, 6> &cube);
char findAdj(std::array<std::array<char,9>, 6> &cube, int i, int j);

#endif //RUBIKSCUBESOLVER_CROSSSOLVER_H
