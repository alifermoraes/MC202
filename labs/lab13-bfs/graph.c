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
    Vertex *new, *tmp;
    int origin, target;
    int i;

    G.edge = malloc(edges * sizeof(Edge));

    if (!G.edge) exit(1);

    for (i = 0; i < edges; i++) {
        G.edge[i].edge = (i + 1);
        G.edge[i].distance = -1;
        G.edge[i].pi = NULL;
        G.edge[i].marked = 0;
        G.edge[i].next = NULL;
    }

    do {
        scanf(" %d,%d", &origin, &target);

        if (origin && target) {
            new = malloc(sizeof(Vertex));

            if (!new) exit(1);

            new->target = target;
            new->next = NULL;

            tmp = G.edge[origin - 1].next;

            if (tmp) {
                while(tmp->next) {
                    tmp = tmp->next;
                }

                tmp->next = new;

            } else {
                G.edge[origin - 1].next = new;
            }

            new = malloc(sizeof(Vertex));

            if (!new) exit(1);

            new->target = origin;
            new->next = NULL;

            tmp = G.edge[target - 1].next;

            if (tmp) {
                while(tmp->next) {
                    tmp = tmp->next;
                }

                tmp->next = new;

            } else {
                G.edge[target - 1].next = new;
            }
        }
    } while (origin && target);

    return G;
}

void graph_destroy(Graph *graph, int edges) {
    Vertex *tmp, *curr;
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
