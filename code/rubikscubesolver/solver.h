#ifndef RUBIKSCUBESOLVER_SOLVER_H
#define RUBIKSCUBESOLVER_SOLVER_H

int pieceTypeCheck(int i);
void solveCross(std::array<std::array<char,9>, 6> &cube);
int crossCheck(std::array<std::array<char,9>, 6> &cube);
char findAdj(std::array<std::array<char,9>, 6> &cube, int i, int j);

#endif //RUBIKSCUBESOLVER_SOLVER_H
