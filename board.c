#include <stdio.h>
#include "board.h"
#include <unistd.h>
#define n 8

void printBoard(char board[n][n]) {

    //declare variables
    int k=1;
    int i;
    int j;

    printf("\n\n");
    printf(" ");
    while(k<=n) {
        printf("   %d", k);
        k++;
    }
    printf("\n  ---------------------------------\n");
    for(i = 0; i < n; i++) {  //print rows lines
        printf("%c ", i+65);
        for(j = 0; j < n; j++) {  //print board positions
            printf("|");
            printf(" %c ", board[i][j]);

            if (j==n-1)
                printf("|");
        }
        printf("\n  ---------------------------------\n");
    }
    printf("\n\n\n");
}

void inicializar_board(char board[n][n]) {
    int i, j;

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            board[i][j] = ' ';
        }
    }
}

void add_position(char letter, char number, char board [n][n]){
    if (board [(int)(letter-'a')][(int)(number-49)]!='#')
        board [(int)(letter-'a')][(int)(number-49)]='#';
    else printf ("Escolha outra posição");
}
//
//void mostrar_tabuleiro(ESTADO *estado);

