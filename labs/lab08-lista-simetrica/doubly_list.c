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

#include <stdlib.h>
#include <stdio.h>
#include "doubly_list.h"

static void doubly_iterate(Node **current, Node **previous, int iterations);

List* create_list(void) {
    List *list = NULL;

    list = malloc(sizeof(List));

    if (!list) exit(1);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void doubly_insert(List *list) {
    Node *new, *current, *prev;
    int pos;

    new = malloc(sizeof(Node));

    if (!new) exit(1);

    scanf(" %d %lf", &pos, &new->data);
    new->A = NULL;
    new->B = NULL;

    if (!list->size) { /* lista vazia. */
        list->head = new;
        list->tail = new;
    } else {
        if (!pos) { /* insere na primeira posição */
            new->A = list->head->A;
            new->B = list->head;
            list->head->A = new;
            list->head = new;
        } else if (pos >= list->size) { /* posição inválida -> insere no fim da lista. */
            new->A = list->tail;
            list->tail->B = new;
            list->tail = new;
        } else {
            current = list->head;
            prev = current->A;
             /**
              * Percorre a lista considerando a possibilidade de que algum trecho da lista pode
              * ter sido invertido, até chegar à posição onde o novo nó deve ser adicionado.
              */
            doubly_iterate(&current, &prev, pos);

            if (current->A == prev) { /* Adiciona o novo nó na devida posição */
                new->A = current;
                new->B = current->B;
                current->B->A = new;
                current->B = new;
            } else {
                new->A = current->A; 
                new->B = current;
                current->A->B = new;
                current->A = new;
            }
        }
    }

    list->size++;
}

void doubly_print(List *list) {
    Node *prev, *current;

    current = list->head;
    prev = current->A;

    while (current) {
        printf("%.4lf ", current->data);

        if (!prev || ((current->A == prev) && (current != list->head))) {
            prev = current;
            current = current->B;
        } else {
            prev = current;
            current = current->A;
        }
    }

    printf("\n");
}

void doubly_reverse(List *list) {
    Node *f_current, *f_prev, *l_current, *l_prev;
    int first, last;

    scanf(" %d %d", &first, &last);

    if (first >= list->size || last >= list->size || first == last) { /* posições inválidas. */
        return;
    }

    f_current = list->head;
    l_current = list->head;
    f_prev = f_current->A;
    l_prev = l_current->A;


    doubly_iterate(&f_current, &f_prev, first + 1);
    doubly_iterate(&l_current, &l_prev, last + 1);

    if (!first) {
        list->head = l_current;
    }

    if (last == (list->size - 1)) {
        list->tail = f_current;
    }

    if (l_current->B) {
        l_current->B->A = f_current;
    }

    if (f_current->A) {
        f_current->A->B = l_current;
    }

    f_current->A = l_current->B;
    l_current->B = f_prev;
}

void doubly_destroy(List *list) {
    Node *prev, *current;
    Node *addresses[list->size];
    int i, counter = 0;

    current = list->head;
    prev = current->A;

    while (current) {
        addresses[counter] = current;

        if (!prev || ((current->A == prev) && (current != list->head))) {
            prev = current;
            current = current->B;
        } else {
            prev = current;
            current = current->A;
        }

        counter++;
    }

    for (i = 0; i < counter; i++) {
        free(addresses[i]);
    }

    free(list);
}

static void doubly_iterate(Node **current, Node **previous, int iterations) {
    Node *head = *current;
    int i;

    if (*current) {
        for (i = 1; i < iterations; i++) {
            if (!(*previous) || (((*current)->A == *previous) && (*current != head))) {
                *previous = *current;
                *current = (*current)->B;
            } else {
                *previous = *current;
                *current = (*current)->A;
            }
        }
    }
}
