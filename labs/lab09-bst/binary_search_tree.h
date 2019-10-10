/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 09-lista-bst
 *
 * Árvore de busca binária
 * 
 * Este trabalho consiste em escrever um programa com funções para manipular uma árvore de busca
 * binária para inteiros.
 */

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

typedef struct tree_node {
    int data;
    struct tree_node *right_s;
    struct tree_node *left_s;
} Tree;

#endif /* _BINARY_SEARCH_TREE_H */
