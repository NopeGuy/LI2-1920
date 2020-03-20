#include <stdio.h>
#include "board.h"
#include "input.h"

int main() {
    char board[n][n];
    int  finish=0;
    printf("\n      -----------------------\n\tWelcome to RASTROS!\n      -----------------------");
    inicializar_board(board);
    while (!finish){
        finish=input(board);
        printBoard(board);
    }

    return 0;
}

