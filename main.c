#include <stdio.h>
#include "board.h"
#define n 8

int main() {
    char board[n][n];
    printf("Welcome to RASTROS!");
    createBoard(board);
    return 0;
}

