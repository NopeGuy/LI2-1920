#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#include <string.h>
#include "logic.h"
FILE *fp;
#define BUF_SIZE 1024

#define n 8

void jogadas(ESTADO *e) {

    int i;
    printf("Jogador 1:");
    for (i = 0; i < e->num_jogadas; i++) {
        printf(" %c%c", e->jogadas[i].jogador1.coluna, e->jogadas[i].jogador1.linha);
        i++;
    }
    printf("\nJogador 2:");
    for (i = 1; i < e->num_jogadas; i++) {
        printf(" %c%c", e->jogadas[i].jogador2.coluna, e->jogadas[i].jogador2.linha);
        i++;
    }
    printf("\n");

}

void jogadasInFile(ESTADO *e) {

    int k=0;
    int i=1;
    while (k<e->num_jogadas) {
        fprintf(fp,"0%d: %c%c %c%c\n", i, e->jogadas[k].jogador1.coluna, e->jogadas[k].jogador1.linha, e->jogadas[k+1].jogador2.coluna, e->jogadas[k+1].jogador2.linha);
        k+=2;
        i++;
    }
    fprintf(fp, "\n");
}

void printBoard(ESTADO *e) {

    int k = 0;
    int i;
    int j;
    if (e->num_jogadas > 0)
        printf("\n\n----------------------------------------");
    printf("\n\nJogador atual : %d\n", e->jogador_atual);
    printf("Turno: %d\n\n", (e->num_jogadas/2) + 1);
    printf(" ");
    while (k < n) {
        printf("   %c", k+65);
        k++;
    }
    printf("\n  ---------------------------------\n");
    for (i = 0; i < n; i++) {  //print rows lines
        printf("%d ", i+1);
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
    fprintf(fp,"Turno: %d\n\n", (e->num_jogadas/2 + 1));
    fprintf(fp," ");
    while (k < n) {
        fprintf(fp,"   %c", k+65);
        k++;
    }
    fprintf(fp,"\n  ---------------------------------\n");
    for (i = 0; i < n; i++) {  //print rows lines
        fprintf(fp,"%d ", i+1);
        for (j = 0; j < n; j++) {
            fprintf(fp,"|");
            fprintf(fp," %c ", e->tab[i][j]);

            if (j == n - 1)
                fprintf(fp,"|");
        }
        fprintf(fp,"\n  ---------------------------------\n");
    }
    fprintf(fp,"\n");
}


// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char filename[100]= "..\\";
    int counter=0;
    int newCounter = 0;
    char newLinha[10];
    int numpretas = 0;
    char dir[50];
    char token[3];

    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        if(add_position(*col, *lin, e)== false)
            printf("Jogada invalida\n");
        else if (check_finish(*col, *lin, e) != 0) {
            printBoard(e);
            if (check_finish(*col,*lin,e) == 1)
                puts("Player 1 wins!");
            if (check_finish(*col,*lin,e) == 2)
                puts("Player 2 wins!");
            if (check_finish(*col,*lin,e) == 3)
                printf("\nPlayer %i wins!", e->jogador_atual%2 + 1);}
        else printBoard(e);
    }
    if (strlen(linha) == 2 && strncmp(linha,"Q",1)==0) {
        fflush(stdin);
        printf("Exiting game");
        return 2;
    }
    if (strlen(linha) == 5 && strncmp(linha,"movs",4) == 0)
        jogadas(e);

    if (strncmp(linha,"gr",2) == 0 && sscanf(linha, "%s %s",token, dir)) {
        strcat(filename, dir);
        strcat(filename, ".txt");
        fp = fopen(filename, "w+");
        printInFile(e);
        jogadasInFile(e);
        fclose(fp);
        printf("\nGuardado no ficheiro %s.txt :", dir);
        printBoard(e);
    }
    if (strncmp(linha,"ler",2) == 0 && sscanf(linha, "%s %s",token, dir)) {
        strcat(filename, dir);
        strcat(filename, ".txt");
        fp = fopen(filename, "r");
        while (fgets(linha, BUF_SIZE, fp) != NULL){
            if (counter>6 && counter%2!=0){
                for(int i=0;i<strlen(linha);i++){
                    if(i==0||i%2!=0 || linha[i]=='|')
                        continue;
                    else sprintf(newLinha,"%s%c",newLinha, linha[i]);
                }
                for(int i = 0; i< strlen(newLinha);i++){
                    if(newLinha[i]=='_')
                        e->tab[newCounter][i] = VAZIO;
                    else if (newLinha[i]=='2')
                        e->tab[newCounter][i] = DOIS;
                    else if (newLinha[i]=='1')
                        e->tab[newCounter][i] = UM;
                    else if (newLinha[i]=='#') {
                        e->tab[newCounter][i] = PRETA;
                        numpretas++;
                    }
                    else if (newLinha[i]=='O') {
                        e->tab[newCounter][i] = BRANCA;
                        e->ultima_jogada.coluna= i +'a';
                        e->ultima_jogada.linha= newCounter +'1';
                        e->num_jogadas= numpretas+1;
                    }
                }
                newCounter ++;
                strcpy(newLinha,"");
            }
            counter++;
        }
        printBoard(e);
    }

    return 1;
}
