/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 10-lista-bst
 *
 * Árvore de busca binária parte 2
 * 
 * Este trabalho consiste em escrever um programa com funções para manipular uma árvore de busca
 * binária para inteiros.
 */

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#define INVALID    -1
#define FINISH      0
#define INSERT      1
#define SEARCH      2
#define POST_ORDER  3
#define IN_ORDER    4
#define PRE_ORDER   5
#define BREADTH     6
#define DELETE      7
#define MIN         8
#define MAX         9


typedef struct tree_node {
    int data;
    struct tree_node *parent;
    struct tree_node *right_s;
    struct tree_node *left_s;
} Tree, *tree_ptr;

tree_ptr bst_create(void);
int bst_insert(tree_ptr *tree, int data);
tree_ptr bst_search(tree_ptr tree, int data);
void bst_post_order(tree_ptr tree);
void bst_in_order(tree_ptr tree);
void bst_pre_order(tree_ptr tree);
void bst_breadth(tree_ptr tree, int size);
tree_ptr bst_min(tree_ptr tree);
tree_ptr bst_max(tree_ptr tree);
void bst_destroy(tree_ptr tree);
int bst_decoder(char *instruction);

#endif /* _BINARY_SEARCH_TREE_H */
