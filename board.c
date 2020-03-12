//
// Created by Diogo on 10/03/2020.
//
#include <stdio.h>
#include "board.h"
#include <stdlib.h>
#define n 8

void createBoard(char board[n][n]) {

    //declare variables
    int i;
    int j;

    printf("\n\n");
    printf("\n---------------------------------\n");
    for(i = 0; i < n; i++) {  //print rows lines
        for(j = 0; j < n; j++) {  //print and assign board positions
            printf("|");
            if (i == 0 && j == n-1)
                board[i][j] = '1';
            else if (i==n-1 && j == 0)
                board[i][j] = '2';
            else
                board[i][j] = ' ';

            printf(" %c ", board[i][j]);

            if (j==n-1)
                printf("|");
        }

        printf("\n---------------------------------\n");

    }

    printf("\n\n\n");
    printf("%c", board[7][0]);
    return;

}