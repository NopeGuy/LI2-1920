#include <stdlib.h>
#include <stdbool.h>
#include "logic.h"
#include "camadadedados.h"
#include <stdio.h>

bool check_finish (char letter, char number, ESTADO *e){
    int check=1;
    if(letter-'a'==0 && number-'1'==7) {
        if (e->jogador_atual == 1) {
            e->jogadas[e->num_jogadas].jogador1.linha = letter;
            e->jogadas[e->num_jogadas].jogador1.coluna = number;
        } else {
            e->jogadas[e->num_jogadas].jogador2.linha = letter;
            e->jogadas[e->num_jogadas].jogador2.coluna = number;
        }
        e->num_jogadas++;
        printf("\nPlayer 2 wins!");
        return true;
    }
    if(letter-'a'==7 && number-'1'==0) {
        if (e->jogador_atual == 1) {
            e->jogadas[e->num_jogadas].jogador1.linha = letter;
            e->jogadas[e->num_jogadas].jogador1.coluna = number;
        } else {
            e->jogadas[e->num_jogadas].jogador2.linha = letter;
            e->jogadas[e->num_jogadas].jogador2.coluna = number;
        }

        e->num_jogadas++;
        printf("\nPlayer 1 wins!");
        return true;
    }
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if((letter-'a'+i) >=0 && (number -'1'+j) >=0)
            {
                if(e->tab[letter-'a'+i][number -'1'+j] == VAZIO)
                    check = 0;
            }
        }
    }
    if (check){
        printf("Player %i wins!", e->jogador_atual%2+1);
        return true;

    }
    return false;
}

bool add_position(char letter, char number, ESTADO *e){
//    if (check_finish(letter, number,e))
//        return true;
    if (e->tab[(int)(letter-'a')][(int)(number-49)]==VAZIO || e->tab[(int)(letter-'a')][(int)(number-49)]==UM || e->tab[(int)(letter-'a')][(int)(number-49)]==DOIS) {
        if (!(abs(letter-(e->ultima_jogada.linha))>1 || abs(number-(e->ultima_jogada.coluna))>1)) {
            if (letter>='a' && letter<='h' && number>='1' && number<='8') {
                e->tab[(int) (e->ultima_jogada.linha - 'a')][(e->ultima_jogada.coluna - 49)] = PRETA;
                e->tab[(int) (letter - 'a')][(int) (number - 49)] = BRANCA;
                e->ultima_jogada.linha = letter;
                e->ultima_jogada.coluna = number;

                if (e->jogador_atual == 1) {
                    e->jogadas[e->num_jogadas].jogador1.linha = letter;
                    e->jogadas[e->num_jogadas].jogador1.coluna = number;
                    e->jogador_atual = 2;
                } else {
                    e->jogador_atual = 1;
                    e->jogadas[e->num_jogadas].jogador2.linha = letter;
                    e->jogadas[e->num_jogadas].jogador2.coluna = number;
                }

                e->num_jogadas++;
                if (check_finish(letter, number, e))
                    return true;
                return true; }
            }
            }

    return false;
}