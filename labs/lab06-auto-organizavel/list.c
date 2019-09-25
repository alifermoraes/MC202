/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 06-auto-organizavel
 *
 * Lista auto-organizável
 *
 * Em uma lista não há uma forma simples que facilite a recuperação dos registros armazenados nos
 * nós: para recuperar o nó na posição i de uma lista é preciso percorrê-la a partir da cabeça,
 * fazendo i acessos a nós.
 *
 * Em muitas aplicações, as freqüências com que os registros são recuperados não são uniformes. Faz
 * sentido que os registros que são recuperados com maior freqüência sejam colocados mais próximos
 * da cabeça, mas tipicamente tais freqüências não são conhecidas e mudam ao longo do tempo.
 *
 * Estratégias de permutação podem ser aplicadas para reduzir o número de acessos a nós da lista
 * durante a recuperação de registros em uma lista. Tais estratégias movem o registro que acabou de
 * ser recuperado um certo número de posições em direção ao início da lista, sem modificar a ordem
 * relativa dos demais registros. Listas acompanhadas de alguma estratégia desse tipo foram
 * chamadas de listas auto-organizáveis.
 * 
 * Algumas estratégias de permutação foram propostas na literatura. As mais usadas incluem:
 * - Move-to-front (MTF): quando um registro é recuperado ele é movido para o início da lista, se
 * ele ainda não estiver no início da lista.
 * - Transpose (TR): quando um registro é recuperado ele é trocado de posição com o registro que o
 * precede, se ele ainda não estiver no início da lista.
 * - Count (C): cada registro tem um contador do número de acessos. Quando um registro é recuperado
 * o contador é incrementado e ele é movido para uma posição anterior a todos os registros com
 * contador menor ou igual ao dele. 
 */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

node_ptr list_create(int size) {
    int i;
    node_ptr list = NULL, tmp = NULL;

    list = malloc(sizeof(Node));
    tmp = list;

    for (i = 1; i < size; i++) {
        tmp->key = i;
        tmp->counter = 0;
        tmp->next = malloc(sizeof(Node));
        tmp = tmp->next;
    }

    tmp->key = i;
    tmp->counter = 0;
    tmp->next = NULL;

    return list;
}

void list_destroy(node_ptr list) {
    if (list) {
        if (list->next) {
            list_destroy(list->next);
        }

        free(list);
    }
}

int list_move_to_front(node_ptr *list, int key) {
    int cost = 1;
    node_ptr prev = NULL, current = NULL;

    for (current = *list; current && (current->key != key); current = current->next) {
        prev = current;
        cost++;
    }

    if (!current) { /* lista vazia ou valor nao encontrado */
        return 0;
    } else if (prev) { /* move o item para o inicio da lista rearranjando os ponteiros */
        prev->next = current->next;
        current->next = *list;
        *list = current;
    }

    return cost;
}

int list_transpose(node_ptr *list, int key) {
    int cost = 1;
    node_ptr tmp = NULL, prev = NULL, current = NULL;

    for (current = *list; current && (current->key != key); current = current->next) {
        tmp = prev;
        prev = current;
        cost++;
    }

    if (!current) { /* lista vazia ou valor nao encontrado */
        return 0;
    } else if (!prev) { /* valor no primeiro elemento da lista, nao precisa ser movido */
        return 1;
    } else if (!tmp) { /* valor na segunda posicao da lista, precisa ser movido para o inicio */
        prev->next = current->next;
        current->next = prev;
        *list = current;
    } else { /* caso geral, move o item correspondente para a esquerda */
        prev->next = current->next;
        current->next = prev;
        tmp->next = current;
    }

    return cost;
}

int list_count(node_ptr *list, int key) {
    int cost = 1;
    node_ptr item = NULL, prev = NULL, current = NULL;

    for (item = *list; item && (item->key != key); item = item->next) {
        prev = item;
        cost++;
    }

    if (!item) { /* lista vazia ou item nao encontrado */
        return 0;
    } else if (!prev) { /* item na primeira posicao da lista */
        item->counter++;
        return 1;
    } else { /* caso geral, remove o item da lista e adiciona-o na nova posicao */
        item->counter++;
        prev->next = item->next;
        prev = NULL;

        /* percorre a lista novamente para encontrar onde o item deve ser realocado */
        for (current = *list; current && (current->counter > item->counter); current = current->next) {
            prev = current;
        }
        
        item->next = current;

        if (!prev) { /* item deve ser adicionado na primeira posicao da lista */
            *list = item;
        } else { /* caso geral */
            prev->next = item;
        }
    }

    return cost;
}
