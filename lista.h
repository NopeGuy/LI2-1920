/**
@file lista.h
listas ligadas genéricas
*/

#ifndef RASTROSPROJECT_LISTA_H
#define RASTROSPROJECT_LISTA_H
#include "camadadedados.h"

typedef struct lista{
    void *cabeca;
    struct lista *proximo;

}CABECA,*LISTA;

/** \brief Função que  cria uma lista inicialmente vazia
 * A função define a cabeça da lista e a cauda como vazias e dá return desses valores.
 */
LISTA criar_lista();

/** \brief Insere um valor na cabeça da lista
 */
LISTA insere_cabeca(LISTA L, void *valor);

/** \brief Devolve a cabeça da lista
 */
void *devolve_cabeca(LISTA L);

/** \brief Devolve a cauda da lista
 */
LISTA proximo(LISTA L);

/** \brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
 */

LISTA remove_cabeca(LISTA L);

/** \brief Devolve verdareiro se a lista é vazia
 */
int lista_esta_vazia(LISTA L);

#endif //RASTROSPROJECT_LISTA_H
