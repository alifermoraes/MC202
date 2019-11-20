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

typedef struct graph {
    int nodes;
    Node *nodes_list;
} Graph;

typedef struct graph_node {
    int edge;
    Node *next;
    int marked;
} Node;

#endif /* _GRAPH_H */
