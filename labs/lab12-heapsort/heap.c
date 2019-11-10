/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 11-hashing
 *
 * Hashing de cadeias
 *
 * Este trabalho consiste em implementar uma tabela de hashing para armazenar cadeias do alfabeto
 * {a,b,...,z,A,B,...,Z,_}. No máximo 5.000 cadeias de no máximo 250 caracteres estarão armazenadas
 * na tabela ao mesmo tempo.
 *
 * As colisões devem ser resolvidas usando sondagem com hashing duplo ou encadeamento na própria
 * tabela. Defina o tamanho e a função de hashing para a sua tabela.
 *
 * Escolha também uma função de transformação de cadeias de caracteres em inteiros.
 */

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

static void heap_insert(Heap *heap, int data);

Heap *heap_create(int max_size) {
    Heap *heap;
    int data;

    heap = malloc(sizeof(Heap));

    if (!heap)
        return NULL;

    heap->V = malloc(max_size * sizeof(int));

    if (!heap->V) {
        free(heap);
        return NULL;
    }

    heap->max_size = max_size;
    heap->size = 0;

    while (heap->size < heap->max_size) {
        scanf(" %d", &data);
        heap_insert(heap, data);
    }

    return heap;
}

static void heap_insert(Heap *heap, int data) {
    int parent, child;

    if (heap->size < heap->max_size) {
        heap->V[heap->size] = data;
        child = heap->size;
        parent = (heap->size - 1) / 2;

        while (child && (heap->V[parent] < heap->V[child])) {
            /**
             * XOR swap -> troca os valores de duas variáveis que se comportam como inteiros sem uso
             * de variável auxiliar.
             */
            heap->V[parent] ^= heap->V[child];
            heap->V[child] ^= heap->V[parent];
            heap->V[parent] ^= heap->V[child];

            child = parent;
            parent = (child - 1) / 2;
        }

        heap->size++;
    }
}

/**
 * Coloca o maior valor do heap na utilma posição útil do vetor que armazena os valores do heap
 * depois diminui o índice que guarda o tamanho útil do vetor.
 * A função retorna esse valor, que era o heap
 */
int heap_remove_max(Heap *heap) {
    int parent, child, r_child, l_child;

    if (heap->size > 1) {
        heap->size--;

        /**
         * XOR swap -> troca os valores de duas variáveis que se comportam como inteiros sem uso
         * de variável auxiliar.
         */
        heap->V[0] ^= heap->V[heap->size];
        heap->V[heap->size] ^= heap->V[0];
        heap->V[0] ^= heap->V[heap->size];

        parent = 0;
        l_child = (2 * parent) + 1;
        r_child = l_child + 1;

        do {
            if (r_child < heap->size)
                child = heap->V[l_child] > heap->V[r_child] ? l_child : r_child;
            else if (l_child < heap->size)
                child = l_child;
            else
                child = parent;

            if (heap->V[parent] < heap->V[child]) {
                heap->V[parent] ^= heap->V[child];
                heap->V[child] ^= heap->V[parent];
                heap->V[parent] ^= heap->V[child];

                parent = child;
                l_child = (2 * parent) + 1;
                r_child = l_child + 1;
                child = l_child;
            } else {
                child = parent;
            }

        } while (child != parent);
    } else if (heap->size) { /* heap possui só 1 elemento */
        heap->size--;
    }

    return heap->V[heap->size];
}

void heap_destroy(Heap *heap) {
    if (heap) {
        if (heap->V)
            free(heap->V);

        free(heap);
    }
}
