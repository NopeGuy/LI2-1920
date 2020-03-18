#include "input.h"
#include "board.h"
#include "stdio.h"
#include <ctype.h>

int input(char board[n][n]){
    char input [2];
    char pos1;
    char pos2;
    printf("Introduza uma posição (letra e depois número)\n");
    scanf("%s", &input);
    pos1 = tolower(input[0]);
    pos2 = input[1];
    if (pos1 >= 'a' && pos1 <= 'h')
        if (pos2 >= '1' && pos2 <= '8')
        add_position(pos1, pos2, board);
    else
        printf("\n\nTry again");
}
