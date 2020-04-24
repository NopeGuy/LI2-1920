#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#include <string.h>
#include "logic.h"
FILE *fp;

int rand();

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
        fprintf(fp,"0%d: %c%c ", i, e->jogadas[k].jogador1.coluna, e->jogadas[k].jogador1.linha);
        if (e->num_jogadas%2 != 0 && k != e->num_jogadas - 1)
            fprintf(fp,"%c%c\n", e->jogadas[k+1].jogador2.coluna, e->jogadas[k+1].jogador2.linha);
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
    for (int i = 0; i < n; i++) {  //print rows lines
        for (int j = 0; j < n; j++) {
            if (e->tab[i][j] == VAZIO)
                fprintf(fp, ". ");
            else if (e->tab[i][j] == PRETA)
                fprintf(fp, "# ");
            else if (e->tab[i][j] == UM)
                fprintf(fp, "1 ");
            else if (e->tab[i][j] == DOIS)
                fprintf(fp, "2 ");
            else fprintf(fp, "* ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}

void position(ESTADO *e, int valor) {
    e->num_jogadas = valor * 2;
    e->ultima_jogada.coluna = e->jogadas[e->num_jogadas-1].jogador2.coluna;
    e->ultima_jogada.linha = e->jogadas[e->num_jogadas-1].jogador2.linha;
    for (int i=(valor * 2);i < 64;i++) {
        e->jogadas[i].jogador1.linha = ' ';
        e->jogadas[i].jogador1.coluna = ' ';
        e->jogadas[i + 1].jogador2.linha = ' ';
        e->jogadas[i + 1].jogador2.coluna = ' ';
        i++;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            e->tab[i][j] = VAZIO;
        }
        e->tab[3][4] = PRETA;
        e->tab[0][7] = DOIS;
        e->tab[7][0] = UM;

    }
    for (int i=0 ; i < (valor * 2) - 1;i++) {
        e->tab[(int)e->jogadas[i].jogador1.linha - 49][(int)e->jogadas[i].jogador1.coluna - 'a'] = PRETA;
        e->tab[(int)e->jogadas[i+1].jogador2.linha - 49][(int)e->jogadas[i+1].jogador2.coluna - 'a'] = PRETA;
    }
    e->tab[(e->ultima_jogada.linha - 49)][(int) (e->ultima_jogada.coluna - 'a')] = BRANCA;
    e->jogador_atual = 1;
    printBoard(e);

}

// Função que deve ser completada e colocada na camada de interface


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char filename[100] = "..\\";
    int counter = 0;
    int newCounter = 0;
    char newLinha[10];
    int numpretas = 0;
    char dir[50];
    char token[3];
    int valor;
    int teste = 0;

    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        if (add_position(*col, *lin, e) == false)
            printf("Jogada invalida\n");
        else if (check_finish(*col, *lin, e) != 0) {
            printBoard(e);
            if (check_finish(*col, *lin, e) == 1)
                puts("Player 1 wins!");
            if (check_finish(*col, *lin, e) == 2)
                puts("Player 2 wins!");
            if (check_finish(*col, *lin, e) == 3)
                printf("\nPlayer %i wins!", e->jogador_atual % 2 + 1);
        } else printBoard(e);
    }
    if (strlen(linha) == 2 && strncmp(linha, "Q", 1) == 0) {
        fflush(stdin);
        printf("Exiting game");
        return 2;
    }
    if (strlen(linha) == 5 && strncmp(linha, "movs", 4) == 0)
        jogadas(e);

    if (strncmp(linha, "gr", 2) == 0 && sscanf(linha, "%s %s", token, dir)) {
        strcat(filename, dir);
        strcat(filename, ".txt");
        fp = fopen(filename, "w+");
        printInFile(e);
        jogadasInFile(e);
        fclose(fp);
        printf("\nGuardado no ficheiro %s.txt :", dir);
        printBoard(e);
    }

    if (strncmp(linha,"ler",3) == 0 && sscanf(linha, "%s %s",token, dir)) {
        char check[5] = "01:";
        int find_pos = 0;
        int line_num = 1;

        strcat(filename, dir);
        strcat(filename, ".txt");
        fp = fopen(filename, "r");
        while (fgets(linha, BUF_SIZE, fp) != NULL) {
            if (strstr(linha, check) != NULL) {
                find_pos++;
            }
            line_num++;
            if (find_pos != 0) {
                printf("%s", linha);
                add_position(linha[4], linha[5], e);
                add_position(linha[7], linha[8],e);
            }
        }
        printBoard(e);
    }

    if (strncmp(linha, "pos", 3) == 0 && sscanf(linha, "%s %d", token, &valor)) {
            if (valor >= e->num_jogadas) {
                printf("Por favor utilize um valor entre 0 e %d", e->num_jogadas);
            } else position(e, valor);
        }

    if (strncmp(linha,"jog",3) == 0 && sscanf(linha, "%s %s",token, dir)) {
        if (strlen(linha) == 4 && strncmp(linha,"jog", 3) == 0) {
            char broC[10];
            char broL[10];
            int k = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (e->ultima_jogada.coluna + i >= 'a' && e->ultima_jogada.coluna + i <= 'h' &&
                        e->ultima_jogada.linha + j >= '1' && e->ultima_jogada.linha + j <= '8') {
                        if ((e->ultima_jogada.coluna - 'a' + i) >= 0 && (e->ultima_jogada.linha - '1' + j) >= 0) {
                            if (e->tab[e->ultima_jogada.linha - '1' + j][e->ultima_jogada.coluna - 'a' + i] == VAZIO
                                || e->tab[e->ultima_jogada.linha - '1' + j][e->ultima_jogada.coluna - 'a' + i] == UM
                                || e->tab[e->ultima_jogada.linha - '1' + j][e->ultima_jogada.coluna - 'a' + i] == DOIS) {
                                broC[k] = e->ultima_jogada.coluna + i;
                                broL[k] = e->ultima_jogada.linha + j;
                                k++;
                            }
                        }
                    }
                }
            }
            int num = (rand() % k + 1);
            while (broC[num] == ' ')
                num = (rand() % k);
            add_position(broC[num], broL[num], e);
            printBoard(e);

            for (int i = 0; i<10;i++) {
                broC[i] = ' ';
                broL[i] = ' ';
            }
        }
    }
    return 1;
}
