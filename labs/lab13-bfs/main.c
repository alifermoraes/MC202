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
    //Edge *tmp;
    int vertices, vertex;
    int i, j;

    scanf(" %d", &vertices);
    G = graph_create(vertices);
    scanf(" %d", &vertex);
    graph_bfs(&G, vertices, vertex);
    printf("Origem da busca: %d\nVertices alcancados e distancias:\n", vertex);

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (G.vertices[j].marked && G.vertices[j].distance == i)
                printf("%d %d\n", (j + 1), G.vertices[j].distance);
        }
    }


    /*for (i = 0; i < vertices; i++) {
        printf("Aresta %d é conectada às arestas: ", (i + 1));

        for (tmp = G.vertices[i].next; tmp; tmp = tmp->next) {
            printf("%d ", (tmp->target + 1));
        } printf("\n");
    }*/

    graph_destroy(&G, vertices);

    return EXIT_SUCCESS;
}
