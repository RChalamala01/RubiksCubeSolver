#include "createcube.h"
#include "crosssolver.h"
#include "f2lsolver.h"
#include "rotations.h"
#include "topsolver.h"
#include <vector>
#include <iostream>
//#include <chrono>

/* Rotation Notation: Everything based on Front (White Side).
     * Cube needs to initially be in the correct orientation.
     * To view red, rotate cube by 90 degrees down from white.
     * To view green, rotate cube by 90 degrees left from white.
     * To view orange, rotate cube by 90 degrees up from white.
     * To view yellow, rotate cube by 180 degrees up from white.
    */

void solveCube(std::array<std::array<char,9>,6> &cube, std::vector<std::string> &solveArray);
void solutionFix(std::vector<std::string> &solveArray);

int main(){
    //generating the cube.

    //auto start = std::chrono::high_resolution_clock::now();

    std::array<std::array<char,9>,6> cube;
    std::vector<std::string> scrambleArray = {};
    std::vector<std::string> solveArray = {};

    originalState(cube);
    //printCube(cube);

    std::cout << std::endl << std::endl;
    std::cout << std::endl << "Cube Scramble: ";
    std::cout << std::endl;
    cubeScramble(cube,scrambleArray);
    printCube(cube);

    solveCube(cube, solveArray);

    std::cout << std::endl << std::endl << "Number of turns: " << solveArray.size() << std::endl;
    solutionFix(solveArray);

//    int counter = 0;
//    int iterations = 1000000;
//    for (int i = 0; i < iterations; i++){
//        std::array<std::array<char,9>,6> cube;
//        std::vector<std::string> scrambleArray = {};
//        std::vector<std::string> solveArray = {};
//
//        originalState(cube);\
//
//        std::cout << "Cube Scramble: ";
//        std::cout <<std::endl;
//        cubeScramble(cube,scrambleArray);
//
//        solveCube(cube, solveArray);
//
//        std::cout << solveArray.size();
//        counter += solveArray.size();
//        solutionFix(solveArray);
//    }

//    std::cout << std::endl << std::endl << "Average Number of Moves: " << counter/iterations;

//    auto end = std::chrono::high_resolution_clock::now();
//    auto timeTotal = std::chrono::duration_cast<std::chrono::seconds>(end - start);
//
//
//    std::cout << std::endl;
//    std::cout << "Runtime: " << timeTotal.count() << " seconds" << std::endl;

    return 0;

}

void solveCube(std::array<std::array<char,9>,6> &cube, std::vector<std::string> &solveArray){
    std::cout << std::endl << std::endl;
    std::cout << "Cross Solve: ";
    std::cout << std::endl;
    solveCross(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
    std::cout << std::endl << std::endl;
    std::cout << "Corner Solve: " << std::endl;
    solveCorners(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
    std::cout << std::endl << std::endl;
    std::cout << "First Two Layer Solve: " << std::endl;
    solveLayerTwo(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
    std::cout << std::endl << std::endl;
    std::cout << "Top Cross Solve: " << std::endl;
    solveTopCross(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
    std::cout << std::endl << std::endl;
    std::cout << "Top Edges Solve: " <<std::endl;
    solveYellowEdges(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
    std::cout << std::endl << std::endl;
    std::cout << "Top Corners Solve: " << std::endl;
    solveTopCorners(cube, solveArray);
    std::cout << std::endl;
    printCube(cube);
}

void solutionFix(std::vector<std::string> &solveArray){
    std::vector<std::string> newArray = {};
    for (int i = 0; i < solveArray.size(); i++){
        break;
    }
}