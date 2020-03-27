#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#include <stdlib.h>
#include <string.h>
#include "logic.h"
FILE *fp;
#define BUF_SIZE 1024

#define n 8

void jogadas(ESTADO *e) {

    int i;
    printf("Jogador 1:");
    for (i = 0; i < e->num_jogadas; i++) {
        printf(" %c%c", e->jogadas[i].jogador1.linha, e->jogadas[i].jogador1.coluna);
        i++;
    }
    printf("\nJogador 2:");
    for (i = 1; i < e->num_jogadas; i++) {
        printf(" %c%c", e->jogadas[i].jogador2.linha, e->jogadas[i].jogador2.coluna);
        i++;
    }
    printf("\n");

}


void printBoard(ESTADO *e) {

    int k = 1;
    int i;
    int j;
    if (e->num_jogadas > 0)
        printf("\n\n----------------------------------------");
    printf("\n\nJogador atual : %d\n", e->jogador_atual);
    printf("Turno: %d\n\n", e->num_jogadas + 1);
    printf(" ");
    while (k <= n) {
        printf("   %d", k);
        k++;
    }
    printf("\n  ---------------------------------\n");
    for (i = 0; i < n; i++) {  //print rows lines
        printf("%c ", i + 65);
        for (j = 0; j < n; j++) {
            printf("|");
            printf(" %c ", e->tab[i][j]);

            if (j == n - 1)
                printf("|");
        }
        printf("\n  ---------------------------------\n");
    }
    printf("\n");
    jogadas(e);
}


void printInFile(ESTADO *e) {

    int k = 1;
    int i;
    int j;
    if (e->num_jogadas > 0)
        printf("\n\n----------------------------------------");
    fprintf(fp,"\n\nJogador atual : %d\n", e->jogador_atual);
    fprintf(fp,"Turno: %d\n\n", e->num_jogadas + 1);
    fprintf(fp," ");
    while (k <= n) {
        fprintf(fp,"   %d", k);
        k++;
    }
    fprintf(fp,"\n  ---------------------------------\n");
    for (i = 0; i < n; i++) {  //print rows lines
        fprintf(fp,"%c ", i + 65);
        for (j = 0; j < n; j++) {
            fprintf(fp,"|");
            fprintf(fp," %c ", e->tab[i][j]);

            if (j == n - 1)
                fprintf(fp,"|");
        }
    }
    fprintf(fp,"\n");
}

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char filename[100];


    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        if(add_position(*col, *lin, e)== false)
            printf("Jogada invalida bro\n");
        else {
            add_position(*col,*lin,e);
            printBoard(e);
        }
    }
    if (strlen(linha) == 2 && linha[0] == 'Q')
        return 2;

    if (strlen(linha) == 5 && strncmp(linha,"movs",4) == 0)
        jogadas(e);

    if (strncmp(linha,"gr",2) == 0) {
        fp = fopen("C:\\Users\\Diogo\\Desktop\\trabalhodela-Mark7\\board.txt", "w");
        printInFile(e);
        fclose(fp);
    }

    return 1;
}