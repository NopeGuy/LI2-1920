cmake_minimum_required(VERSION 3.15)
project(RastrosProject C)

set(CMAKE_C_STANDARD 99)

add_executable(RastrosProject main.c board.c board.h input.c input.h camadadedados.c camadadedados.h)
