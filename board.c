#include <stdio.h>
#include "board.h"
#include <unistd.h>
#define n 8
int positions[128];

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


    char letter;
    char number;
    for(int i = 0; i< 128; i++){
        if(positions[i] != NULL)
        {
            if(i%2==0){
                letter = positions[i];
            }
            else{
                number = positions[i];
                board [letter-'a'][number-1];
            }
        }
        else
            break;
    }
}


void initialize_array(){
    for(int i =0;i<128;i++){
        positions[i] = NULL;
    }
}

void add_position(char letter, char number, char board [n][n]){
    if (board [(int)(letter-'a')][(int)(number-49)]!='#')
        board [(int)(letter-'a')][(int)(number-49)]='#';
    else printf ("Escolha outra posição");
}
   //board[3][4] = '#';



