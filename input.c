#include "input.h"
#include "board.h"
#include "stdio.h"
#include <ctype.h>
char pos1;
char pos2;



int input(char board[n][n]) {
    char input[2];
    printf("Introduza uma posição (letra e depois número)\n");
    scanf("%s", &input);
    pos1 = tolower(input[0]);
    pos2 = input[1];
    printf("%d\n",pos1);
    return add_position(pos1,pos2,board);
}

//
//int validez(char board[n][n]){
//    if (pos1 >= 'a' && pos1 <= 'h')
//            add_position(pos1, pos2, board);
//        else printf("try again");
//
//}