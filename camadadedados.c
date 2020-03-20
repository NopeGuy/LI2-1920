#include "camadadedados.h"
#include <stdlib.h>
#include "board.h"


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada.linha = 'd';
    e->ultima_jogada.coluna = '5';
    e->jogadas->jogador1.linha = ' ';
    e->jogadas->jogador1.coluna = ' ';
    e->jogadas->jogador2.linha = ' ';
    e->jogadas->jogador2.coluna = ' ';
    return e;
}

//ESTADO *e;
//int obter_jogador_atual(ESTADO *estado) {
//    return e->jogador_atual;
//}
