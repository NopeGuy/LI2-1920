#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "input.h"

int main() {
    char board[n][n];
    printf("\nWelcome to RASTROS!");
    inicializar_board(board);
    while (true){
        printBoard(board);
        input(board);
    }

    return 0;
}

