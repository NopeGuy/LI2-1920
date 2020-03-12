cmake_minimum_required(VERSION 3.15)
project(rastrosShit C)

set(CMAKE_C_STANDARD 99)

add_executable(rastrosShit main.c cmake-build-debug/board.c cmake-build-debug/board.h)