cmake_minimum_required(VERSION 3.17)
project(rubikscubesolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(rubikscubesolver main.cpp createcube.cpp createcube.h rotations.cpp rotations.h crosssolver.cpp crosssolver.h f2lsolver.cpp f2lsolver.h topsolver.cpp topsolver.h)
