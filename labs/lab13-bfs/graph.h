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

#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct graph_edge {
    int target;
    struct graph_edge *next;
} Edge;

typedef struct graph_vertex {
    int vertex;
    int distance;
    int pi;
    int marked;
    Edge *next;
} Vertex;

typedef struct graph {
    Vertex *vertices;
} Graph;

Graph graph_create(int vertices);
void graph_bfs(Graph *G, int vertices, int vertex);
void graph_destroy(Graph *G, int vertices);

#endif /* _GRAPH_H */
