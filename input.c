#include "board.h"
#include "stdio.h"
#include <ctype.h>
#include "camadadedados.h"
#include <string.h>
char pos1;
char pos2;
ESTADO *e;


int input(char board[n][n]) {
    char input[10];
    printf("\nJogador %i, introduza uma posição:\n", e->jogador_atual);
    scanf("%s", &input);
    while (strlen(input) != 2 ) {
        printf("Jogada inválida, introduza outra posição: \n");
        scanf("%s", &input);}
    pos1 = tolower(input[0]);
    pos2 = input[1];
    return add_position(pos1,pos2,board);


}
