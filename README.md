Rastros, Laboratório de Algoritmia I 

Turno Prático 3 - Número do Grupo: 7

Elementos do grupo:

Luís Ferreira A91672 

José Abreu A91648 

Diogo Costa A78133

Relatório do guião final

Estratégia do bot

Através do bot criado anteriormente retiramos a componente aleatória em que se removia a cabeça da lista um número sorteado de vezes para introduzir uma estrutura que calcula a melhor jogada através da soma da coluna e da linha, assim é possível ver qual o valor mais próximo á soma do valor de ASCII de H+1 e de A+8 que são iguais e, assim, introduzir a estratégia da distância euclidiana.
Com isso conseguimos encontrar a melhor jogada de acordo com essa estratégia que foi implementada e caso a peça branca se encontre a uma jogada da casa de vitória irá ,como de antes, prioritizar sempre essa jogada.