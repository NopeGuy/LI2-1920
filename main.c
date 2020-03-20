#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "input.h"

int main() {
    char board[n][n];
    int  finish=0;
    printf("\nWelcome to RASTROS!");
    inicializar_board(board);
    while (!finish){
        printBoard(board);
        finish=input(board);
    }

    return 0;
}

