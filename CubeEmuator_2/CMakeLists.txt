cmake_minimum_required(VERSION 3.20)
project(CubeEmuator_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CubeEmuator_2 main.cpp Cube.h Cube.cpp Solver.h Solver.cpp Renderer.cpp Renderer.h)
