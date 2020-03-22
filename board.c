#include <stdio.h>
#include "board.h"
#include "camadadedados.h"
#include <stdlib.h>
#include <stdbool.h>

#define n 8

ESTADO* e;

void printBoard(char board[n][n]) {

    //declare variables
    int k = 1;
    int i;
    int j;
    if(e->num_jogadas > 0)
        printf("\n\n----------------------------------------");
    printf("\n\nJogador atual : %d\n",e->jogador_atual);
    printf("Turno: %d\n\n", e->num_jogadas+1);
    printf(" ");
    while (k <= n) {
        printf("   %d", k);
        k++;
    }
    printf("\n  ---------------------------------\n");
    for (i = 0; i < n; i++) {  //print rows lines
        printf("%c ", i + 65);
        for (j = 0; j < n; j++) {  //print board positions
            printf("|");
            printf(" %c ", board[i][j]);

            if (j == n - 1)
                printf("|");
        }
        printf("\n  ---------------------------------\n");
    }
    printf("\n");
    if (e->num_jogadas > 0) { //depois da primeira jogada, dar print na jogada de cada jogador
        printf("Jogador 1:");
        for(i=0;i < e->num_jogadas;i++){ //print jogadas
            printf(" %c%c", e->jogadas[i].jogador1.linha, e->jogadas[i].jogador1.coluna);
            i++; //o Loop incrementa dois de cada vez, de forma a que só dê print alternadamente
        }
        printf("\nJogador 2:");
        for(i=1;i < e->num_jogadas;i++){
            printf(" %c%c", e->jogadas[i].jogador2.linha, e->jogadas[i].jogador2.coluna);
            i++; //o Loop incrementa dois de cada vez, de forma a que só dê print alternadamente
        }
        printf("\n");

    }
}

void inicializar_board(char board[n][n]) {
    int i, j;
    e=inicializar_estado();
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            board[i][j] = VAZIO;
        }
        board[3][4]=BRANCA;
        board[0][7]=DOIS;
        board[7][0]=UM;

    }
    printBoard(board);
}

// Esta função verifica quando o jogo se dá por terminado, contamos 2 casos, onde o primeiro dá vitoria ao player 1 ou 2 casos.
// estes cheguem as casas [0][7] ou [7][0].
// consideramos no segundo caso , a hipótese de um player ficar rodeado por # , dando assim a vitória ao outro jogador.
//  check faz com que caso seja o player 1 rodeado entao com o check a vitoria será dada ao player 2 e vice-versa.

bool check_finish (char letter, char number, char board[n][n]){
    int check=1;
    if(letter-'a'==0 && number-'1'==7) {
        printf("Jogador 2 venceu!");
        return true;
    }
    if(letter-'a'==7 && number-'1'==0) {
        printf("Jogador 1 venceu!");
        return true;
    }
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if((letter-'a'+i) >=0 && (number -'1'+j) >=0)
            {
                if(board[letter-'a'+i][number -'1'+j] == VAZIO)
                    check = 0;
            }
        }
    }
    if (check){
        printf("Jogador %d vence!", (e->jogador_atual)%2+1);
        return true;
    }
    return false;
}

bool add_position(char letter, char number, char board [n][n]){
    if (check_finish(letter, number,board))
        return true;
    if (board [(int)(letter-'a')][(int)(number-49)]==VAZIO) {
        if (!(abs(letter-e->ultima_jogada.linha)>1 ||abs(number-e->ultima_jogada.coluna)>1))
            if (letter>='a' && letter<='h' && number>='1' && number<='8') {
                board[(int) (e->ultima_jogada.linha-'a')][(e->ultima_jogada.coluna-49)] = PRETA;
                board[(int) (letter - 'a')][(int) (number - 49)] = BRANCA;
                e->ultima_jogada.linha=letter;
                e->ultima_jogada.coluna=number;

                if (e->jogador_atual==1) { // inserir a jogada no array de structs JOGADAS[32], no seu devido indice (e->num_jogadas é usado como indice)
                    e->jogadas[e->num_jogadas].jogador1.linha = letter;
                    e->jogadas[e->num_jogadas].jogador1.coluna = number;
                    e->jogador_atual=2; }
                else {
                    e->jogador_atual=1;
                    e->jogadas[e->num_jogadas].jogador2.linha = letter;
                    e->jogadas[e->num_jogadas].jogador2.coluna = number; }

                e->num_jogadas++;
                if (check_finish(letter, number, board))
                    return true;
                return false;
            }
    }

    return false;
}
