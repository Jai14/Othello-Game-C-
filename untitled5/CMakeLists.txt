cmake_minimum_required(VERSION 3.17)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled5 main.c set_board.h set_board.c make_moves.h make_moves.c check.h check.c winner.h winner.c)