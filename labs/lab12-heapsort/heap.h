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
} heap;

heap *heap_create(int max_size);
void heap_insert(heap *heap, int data);


#endif /* _HEAP_H */
