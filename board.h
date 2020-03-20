#define n 8
#ifndef RASTROS_BOARD_H
#define RASTROS_BOARD_H

#include <stdbool.h>
#include "camadadedados.h"

void printBoard(char board[n][n]);
void inicializar_board(char board[n][n]);
bool add_position(char letter, char number, char board [n][n]);

#endif
