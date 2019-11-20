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

typedef struct graph_vertex {
    int target;
    struct graph_vertex *next;
} Vertex;

typedef struct graph_edge {
    int edge;
    int distance;
    struct Edge *pi;
    int marked;
    Vertex *next;
} Edge;

typedef struct graph {
    Edge *edge;
} Graph;

Graph graph_create(int edges);

void graph_destroy(Graph *graph, int edges);

#endif /* _GRAPH_H */
