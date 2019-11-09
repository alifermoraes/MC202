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
#include "heap.h"

heap *heap_create(int max_size) {
    heap *heap;

    heap = malloc(sizeof(heap));

    if (!heap)
        return NULL;

    heap->V = malloc(max_size * sizeof(int));

    if (!heap->V) {
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->max_size = max_size;

    return heap;
}

void heap_insert(heap *heap, int data) {
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

void heap_destroy(heap *heap) {
    if (heap) {
        if (heap->V)
            free(heap->V);

        free(heap);
    }
}
