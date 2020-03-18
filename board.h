#define n 8
#ifndef SHITRASTROS_BOARD_H
#define SHITRASTROS_BOARD_H
#include "camadadedados.h"

void printBoard(char board[n][n]);
void inicializar_board(char board[n][n]);
void initialize_array();
void add_position(char letter, char number, char board [n][n]);

#endif //SHITRASTROS_BOARD_H
