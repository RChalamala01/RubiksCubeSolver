#ifndef RUBIKSCUBESOLVER_TOPSOLVER_H
#define RUBIKSCUBESOLVER_TOPSOLVER_H

void solveTopCross(std::array<std::array<char,9>, 6> &cube);
bool topCrossSolve(std::array<std::array<char,9>, 6> &cube);
void crossAlgo(std::array<std::array<char,9>, 6> &cube);

#endif //RUBIKSCUBESOLVER_TOPSOLVER_H
