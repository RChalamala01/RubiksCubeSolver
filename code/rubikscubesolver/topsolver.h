#ifndef RUBIKSCUBESOLVER_TOPSOLVER_H
#define RUBIKSCUBESOLVER_TOPSOLVER_H

void solveTopCross(std::array<std::array<char,9>, 6> &cube);
bool topCrossSolve(std::array<std::array<char,9>, 6> &cube);
void crossAlgo(std::array<std::array<char,9>, 6> &cube);
void solveYellowEdges(std::array<std::array<char,9>, 6> &cube);
void solveTopCorners(std::array<std::array<char,9>, 6> &cube);
bool topCornerCheck(std::array<std::array<char,9>, 6> &cube, std::array<char,3> &colorArrayGRY, std::array<char,3> &colorArrayGOY, std::array<char,3> &colorArrayBOY, std::array<char,3> &colorArrayBRY);

#endif //RUBIKSCUBESOLVER_TOPSOLVER_H
