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

Graph graph_create(int edges) {
    Graph G;
    Edge *new, *tmp;
    int origin, target;
    int i;

    G.edge = malloc(edges * sizeof(Edge));

    if (!G.edge) exit(1);

    for (i = 0; i < edges; i++) {
        G.edge[i].edge = (i + 1);
        G.edge[i].marked = 0;
        G.edge[i].next = NULL;
    }

    do {
        scanf(" %d,%d", &origin, &target);

        if (origin && target) {
            new = malloc(sizeof(Edge));

            if (!new) exit(1);

            new->edge = target;
            new->marked = 0;
            new->next = NULL;
            for (tmp = &G.edge[origin - 1]; tmp->next; tmp = tmp->next);
            tmp->next = new;

            new = malloc(sizeof(Edge));

            if (!new) exit(1);

            new->edge = origin;
            new->marked = 0;
            new->next = NULL;
            for (tmp = &G.edge[target - 1]; tmp->next; tmp = tmp->next);
            tmp->next = new;
        }
    } while (origin && target);

    return G;
}

void graph_destroy(Graph *graph, int edges) {
    Edge *tmp, *curr;
    int i;

    for(i = 0; i < edges; i++) {
        tmp = graph->edge[i].next;

        while(tmp) {
            curr = tmp;
            tmp = curr->next;
            free(curr);
        }
    }

    if (graph->edge) {
        free(graph->edge);
    }
}
