//
// Created by Diogo on 3/26/2020.
//
#include <stdlib.h>
#include <stdbool.h>
#include "logic.h"
#include "camadadedados.h"
#include <stdio.h>

//bool check_finish(COORDENADA pos, ESTADO *e){
//    int check=1;
//    if((char)pos.linha-'a'==0 && (char)pos.coluna-'1'==7) {
//        printf("Jogador 2 venceu!");
//        return true;
//    }
//    if((char)pos.linha-'a'==7 && (char)pos.coluna-'1'==0) {
//        printf("Jogador 1 venceu!");
//        return true;
//    }
//    for(int i=-1;i<=1;i++)
//    {
//        for(int j=-1;j<=1;j++)
//        {
//            if(((char)pos.linha-'a'+i) >=0 && ((char)pos.coluna -'1'+j) >=0)
//            {
//                if(e->tab[(char)pos.linha-'a'+i][(char)pos.coluna -'1'+j] == VAZIO)
//                    check = 0;
//            }
//        }
//    }
//    if (check){
//        printf("Jogador %d vence!", (e->jogador_atual)%2+1);
//        return true;
//    }
//    return false;
//}
//
//bool add_position(COORDENADA pos, ESTADO *e){
//    if (check_finish(pos,e))
//        return true;
//    if (e->tab[(int)(pos.linha-'a')][(int)(pos.coluna-49)]==VAZIO) {
//        if (!(abs(pos.linha-e->ultima_jogada.linha)>1 ||abs(pos.coluna-e->ultima_jogada.coluna)>1))
//            if (pos.linha>='a' && pos.linha<='h' && pos.coluna>='1' && pos.coluna<='8') {
//                e->tab[(int) (e->ultima_jogada.linha-'a')][(e->ultima_jogada.coluna-49)] = PRETA;
//                e->tab[(int) (pos.linha - 'a')][(int) (pos.coluna - 49)] = BRANCA;
//                e->ultima_jogada.linha=pos.linha;
//                e->ultima_jogada.coluna=pos.coluna;
//
//                if (e->jogador_atual==1) {
//                    e->jogadas[e->num_jogadas].jogador1.linha = pos.linha;
//                    e->jogadas[e->num_jogadas].jogador1.coluna = pos.coluna;
//                    e->jogador_atual=2; }
//                else {
//                    e->jogador_atual=1;
//                    e->jogadas[e->num_jogadas].jogador2.linha = pos.linha;
//                    e->jogadas[e->num_jogadas].jogador2.coluna = pos.coluna; }
//
//                e->num_jogadas++;
//                if (check_finish(pos, e))
//                    return true;
//                return false;
//            }
//    }
//
//    return false;
//}

bool check_finish (char letter, char number, ESTADO *e){
    int check=1;
    if(letter-'a'==0 && number-'1'==7) {
        return true;
    }
    if(letter-'a'==7 && number-'1'==0) {
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
        return true;
    }
    return false;
}

bool add_position(char letter, char number, ESTADO *e){
    if (check_finish(letter, number,e))
        return true;
    if (e->tab [(int)(letter-'a')][(int)(number-49)]==VAZIO) {
        if (!(abs(letter-e->ultima_jogada.linha)>1 ||abs(number-e->ultima_jogada.coluna)>1)) {
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
                return false; }
            }
            }
    }
    return false;
}