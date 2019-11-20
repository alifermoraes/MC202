/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 13-bfs
 *
 * Busca em largura
 * 
 * Este trabalho consiste em implementar uma busca em largura em um grafo não-orientado G. O grafo
 * deve ser representado por um vetor de adjacências.
 */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main(void) {
    Graph G;
    Vertex *tmp;
    int edges;
    int i;

    scanf(" %d", &edges);
    G = graph_create(edges);

    for(i = 0; i < edges; i++) {
        printf("Aresta %d é conectada às arestas: ", (i + 1));

        for(tmp = G.edge[i].next; tmp; tmp = tmp->next) {
            printf("%d ", tmp->target);
        } printf("\n");
    }

    graph_destroy(&G, edges);

    return EXIT_SUCCESS;
}
