/**
@file input.h
Jogada efetuada e a sua validação
*/


#pragma once
#include "camadadedados.h"
#include "board.h"

/** \brief Validação do input introduzido.
 * lê o input do jogador e verifica-o, isto é, se o input é válido ( letra e número).
 * A função toLower é introduzida para transformar o input de maiúsculo para minúsculo caso o jogador assim o escreva.
 */

int input(char board[n][n]);
