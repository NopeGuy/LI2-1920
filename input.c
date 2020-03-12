#include "input.h"
#include "board.h"
#include "stdio.h"

void input(char board[n][n]){
    char input [2];
    printf("Introduza uma posição (letra e depois número)\n");
    scanf("%s", &input);
    input[0]|=0x10000;
    add_position(input [0],input [1],board);
}