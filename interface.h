/**
@file interface.h
Inicialização/configuração do tabuleiro e jogadas
*/

#define n 8
#ifndef RASTROS_BOARD_H
#define RASTROS_BOARD_H

#include "camadadedados.h"

#include <stdbool.h>
#include "camadadedados.h"

/** \brief Esta função constrói os tabuleiros.
 * Esta função funciona através de ciclos onde o primeiro ciclo constroi a primeira linha  do tabuleiro, sendo q isto só se  repete até i < n.
 * ou seja até i < 8 construindo assim um tabuleiro com 8 linhas e colunas.
 * No fim é aplicado printf ("\n ") para introduzir espaços entre o tabuleiro e onde o jogador insere a jogada.
 @param e Apontador para o estado
 */
void printBoard(ESTADO *e);

/** \brief O interpretador é a função aonde estão guardados os vários comandos.
*O interpretador também  verifica se uma jogada introduzida é válida , dá o jogo como finalizado através da função check_finish e dá print a indicar o respectivo vencedor.
 * O comandos "gr" guarda o estado do jogo num ficheiro.
 * O comando "ler " lê o estado do jogo a partir do ficheiro guardado em "gr".
 * O comando "jog" verifica as posiçães adjacentes que estão livres a partir da posição da peça branca e efetua uma jogada aleatória (Caso a peça branca esteja numa posição consecutiva á casa de vitória, essa jogada será sempre prioridade).
 * O comando "jog2"(estratégia da distância_euclidiana) procura todas as jogadas possíveis a partir da posição em que a peça branca se encontra , depois percorre todas essas posições possíveis e calcula a distância euclidiana para ,assim, saber qual a é a posição mais perto da casa de vitória.(Caso a peça branca esteja numa posição consecutiva á casa de vitória, essa jogada será sempre prioridade).
 @param e Apontador para o estado
*/

int interpretador(ESTADO *e);

extern bool finish;

#endif
