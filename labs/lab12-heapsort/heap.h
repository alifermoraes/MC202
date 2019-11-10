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

#ifndef _HEAP_H
#define _HEAP_H

typedef struct heap {
    int *V;
    int size;
    int max_size;
} Heap;

Heap *heap_create(int max_size);
int heap_remove_max(Heap *heap);
void heap_destroy(Heap *heap);

#endif /* _HEAP_H */
