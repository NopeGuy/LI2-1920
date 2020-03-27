/**
@file board.h
Inicialização/configuração do tabuleiro e jogadas
*/

#define n 8
#ifndef RASTROS_BOARD_H
#define RASTROS_BOARD_H

#include <stdbool.h>
#include "camadadedados.h"

/**\brief Esta função constrói os tabuleiros.
 * Esta função funciona através de ciclos onde o primeiro ciclo constroi a primeira linha  do tabuleiro, sendo q isto só se  repete até i < n.
 * ou seja até i < 8 construindo assim um tabuleiro com 8 linhas e colunas.
 * No fim é aplicado printf ("\n \n \n") para introduzir espaços entre o tabuleiro e onde o jogador insere a jogada.
 */

void printBoard(ESTADO *e);

/**\brief Função que define o tabuleiro.
 * A função trabalha através de for´s, onde ambos declaram todas as  casas como Vazias exceto as casas board [2][4] , [0][7] e [7][0].
 * Esta função já no tabuleiro, aplica onde a peça branca vai aparecer e define todas as outras casas para além da onde esta a peça branca e as casas de vitórias como casas vazias.
 * Define tambem as casas de vitória , board [0][7] e board [7][0].
 */

void inicializar_board(ESTADO *e);

/** \brief  Função sobres as jogadas, funcionalidade e dados do jogo.
 * Esta função considera se uma jogada de um jogador é válida ou não e move a peça branca, caso a casa esteja vazia então a jogada é valida.
 * As funçoes ultima_jogada.linha , ultima_jogada.coluna , jogador atual e num_jogadas são funções de estado que guardam o valor, que depois sempre que sao chamadas através do e->"..." aplica esse valor que estava guardado.
 * Por fim esta função verifica se uma jogada é impossivel ou não, isto é, se a casa existe, ou se a casa que o jogador quer jogar é consecutiva aquela onde ele se situa.
*/

int interpretador(ESTADO *e);
#endif
