#include "board.h"
#include "stdio.h"
#include <ctype.h>
#include "camadadedados.h"
char pos1;
char pos2;
ESTADO *e;


int input(char board[n][n]) {
    char input[2];
    if (e->num_jogadas > 0)
        if ((bool)add_position == true )
            printf("\nJogador %i, introduza uma posição:\n", e->jogador_atual);
        else
            printf("Jogada impossível, introduza outra posição:\n");
    else
        printf("\nJogador %i, introduza uma posição:\n", e->jogador_atual);
    scanf("%s", &input);
    pos1 = tolower(input[0]);
    pos2 = input[1];
    return add_position(pos1,pos2,board);


}
