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

Graph graph_create(int vertices) {
    Graph G;
    Edge *new, *tmp;
    int origin, target;
    int i;

    G.vertices = malloc(vertices * sizeof(Vertex));

    if (!G.vertices) exit(1);

    for (i = 0; i < vertices; i++) {
        G.vertices[i].vertex = (i + 1);
        G.vertices[i].distance = -1;
        G.vertices[i].pi = 0;
        G.vertices[i].marked = 0;
        G.vertices[i].next = NULL;
    }

    do {
        scanf(" %d,%d", &origin, &target);

        if (origin && target) {
            origin--;
            target--;

            new = malloc(sizeof(Edge));

            if (!new) exit(1);

            new->target = target;
            new->next = NULL;

            tmp = G.vertices[origin].next;

            if (tmp) {
                while (tmp->next) {
                    tmp = tmp->next;
                }

                tmp->next = new;

            } else {
                G.vertices[origin].next = new;
            }

            new = malloc(sizeof(Edge));

            if (!new) exit(1);

            new->target = origin;
            new->next = NULL;

            tmp = G.vertices[target].next;

            if (tmp) {
                while (tmp->next) {
                    tmp = tmp->next;
                }

                tmp->next = new;

            } else {
                G.vertices[target].next = new;
            }

            origin++;
            target++;
        }
    } while (origin && target);

    return G;
}

void graph_bfs(Graph *G, int vertices, int vertex) {
    Edge *tmp;
    int *queue, head = 0, size = 0;
    int i, u;

    queue = malloc(vertices * sizeof(int));

    if (!queue) exit(1);

    for (i = 0; i < vertices; i++) {
        G->vertices[i].distance = -1;
        G->vertices[i].pi = 0;
        G->vertices[i].marked = 0;
    }

    vertex--;

    G->vertices[vertex].distance = 0;
    G->vertices[vertex].marked = 1;
    queue[head] = vertex;
    size++;

    while (size) {
        u = queue[head];
        head++;
        size--;

        for (tmp = G->vertices[u].next; tmp; tmp = tmp->next) {
            if (!(G->vertices[tmp->target].marked)) {
                G->vertices[tmp->target].distance = G->vertices[u].distance + 1;
                G->vertices[tmp->target].pi = u;
                queue[(head + size) % vertices] = tmp->target;
                size++;
                G->vertices[tmp->target].marked = 1;
            }
        }
    }

    free(queue);
}

void graph_destroy(Graph *G, int vertices) {
    Edge *tmp, *curr;
    int i;

    for (i = 0; i < vertices; i++) {
        tmp = G->vertices[i].next;

        while (tmp) {
            curr = tmp;
            tmp = curr->next;
            free(curr);
        }
    }

    if (G->vertices) {
        free(G->vertices);
    }
}
