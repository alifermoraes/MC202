/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 08-lista-simetrica
 *
 * Lista simétrica
 * Para reverter um trecho de uma lista encadeada é necessário atualizar todos os apontadores dos
 * nós no trecho, realizando um número de operações proporcional ao número de nós no trecho
 * revertido. Se as operações de reversão forem freqüentes, o custo dessas operações se torna alto.
 *
 * A lista duplamente encadeada também não permite simplesmente reverter um trecho usando um número
 * constante de operações por que, se fizermos isso e tentarmos percorrer a lista, os apontadores
 * prev e next ficam inconsistentes ao longo da lista. Para resolver o problema temos que reverter
 * de fato o trecho, gastando um número de operações proporcional ao número de nós no trecho
 * revertido.
 *
 * Nas listas simétricas, que são listas duplamente encadeadas, os apontadores são chamados
 * simplesmente de A e B, sem referência a uma ordem na lista. Para percorrer a lista simétrica é
 * necessário usar informação sobre o nó visitado anteriormente para decidir qual é o próximo nó a
 * ser visitado. Assim, só é possível percorrer a lista a partir da cabeça ou do rabo, não é
 * possível percorrer a partir de um nó qualquer. Uma reversão só precisa testar e ajustar os
 * apontadores que estão entre os limites do intervalo revertido. Nenhum nó interno ao intervalo
 * revertido é atualizado.
 *
 * Por exemplo considere a lista simétrica abaixo. Na seqüência das figuras acontece uma reversão
 * dos nós nas posições entre 2 e 4 e depois uma reversão entre as posições 4 e 5. Observe que
 * apenas os apontadores nos nós dos extremos da parte revertida são atualizados. Observe também
 * que na terceira lista o caminho para percorrer da cabeça para o rabo passa por apontadores
 * BBAAABB.
 *
 * Com essa restrição é possível reverter um trecho da lista delimitado por dois nós quaisquer
 * fazendo apenas um número constante de operações. Isso é, dados dois nós, o número de operações
 * necessárias para a reversão é constante, já que um número fixo de apontadores é atualizado.
 * 
 * A lista simétrica é uma alternativa eficiente nas aplicações em que a operação de reversão é
 * freqüente.
 * 
 * Neste trabalho, implemente uma lista simétrica de double com reversão. 
 */

#ifndef _DOUBLY_LIST_H
#define _DOUBLY_LIST_H

#define INSERT  1
#define PRINT   2
#define REVERSE 3
#define FINISH  0

typedef struct node {
    double data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    int size;
} List;

#endif /* _DOUBLY_LIST_H */
