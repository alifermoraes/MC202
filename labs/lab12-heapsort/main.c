/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 12-heapsort
 *
 * Heapsort
 *
 * Implemente o heapsort.
 * 
 * Seu programa deve ter pelo menos uma função para criar um heap e uma função para remover o
 * máximo. Sua implementação de heap deve ser implícita. O heapsort deve ser in-place.
 */

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int main(void) {
    Heap *heap;
    int i, max_size;

    scanf(" %d", &max_size);
    heap = heap_create(max_size);

    if (max_size > 0) {
        for (i = 0; i < max_size; i++)
            heap_remove_max(heap);

        for (i = 0; i < max_size; i++)
            printf("%d ", heap->V[i]);
    }

    printf("\n");

    heap_destroy(heap);

    return EXIT_SUCCESS;
}
