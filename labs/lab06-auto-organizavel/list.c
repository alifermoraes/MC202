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

int move_to_front(node_ptr *list, int key) {
    int cost = 2;
    node_ptr tmp = NULL, aux = NULL;

    if (!(*list)) {
        return 0;
    } else if ((*list)->key == key) {
        return 1;
    }

    for (tmp = *list; tmp->next && (tmp->next->key != key); tmp = tmp->next) {
        cost++;
    }

    aux = tmp->next;
    tmp->next = aux->next;
    aux->next = *list;
    *list = aux;
    
    return cost;
}

int transpose(node_ptr *list, int key) {
    int cost = 3;
    node_ptr prev = NULL, tmp = NULL, aux = NULL;

    if(!(*list)) {
        return 0;
    } else if ((*list)->key == key) {
        return 1;
    }

    for (prev = *list; prev->next && prev->next->next && (prev->next->next->key != key); prev = prev->next) {
        cost++;
    }

    tmp = prev->next;
    aux = tmp->next;
    tmp->next = aux->next;
    aux->next = tmp;
    prev->next = aux;

    for (tmp = *list; tmp; tmp = tmp->next) {
        printf("%d ", tmp->key);
    }

    printf("\n%d\n", cost);

    return cost;
}

int count(node_ptr *list, int key) {
    int cost = 0;
    node_ptr tmp;

    return cost;
}
