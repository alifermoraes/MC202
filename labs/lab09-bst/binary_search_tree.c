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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_search_tree.h"

tree_ptr bst_create(void) {
    return NULL;
}

int bst_insert(tree_ptr *tree, int data) {
    tree_ptr new, tmp;

    new = malloc(sizeof(Tree));

    if (!new) exit(1);

    new->data = data;
    new->left_s = NULL;
    new->right_s = NULL;

    if (!(*tree)) {
        *tree = new;
    } else {
        tmp = (*tree);
        
        while (tmp) {

            if (data == tmp->data) {
                free(new);
                return 0;
            } else if (data < tmp->data) {
                if (!tmp->left_s) {
                    tmp->left_s = new;
                    return 1;
                }

                tmp = tmp->left_s;
            } else {
                if (!tmp->right_s) {
                    tmp->right_s = new;
                    return 1;
                }

                tmp = tmp->right_s;
            }
        }
    }
    
    return 1;
}

int bst_search(tree_ptr tree, int data) {
    while (tree) {
        if (tree->data == data) {
            return 1;
        } else if (data < tree->data) {
            tree = tree->left_s;
        } else {
            tree = tree->right_s;
        }
    }

    return 0;    
}

void bst_post_order(tree_ptr tree) {
    if (tree) {
        bst_post_order(tree->left_s);
        bst_post_order(tree->right_s);
        printf("%d ", tree->data);
    }
}

void bst_in_order(tree_ptr tree) {
    if (tree) {
        bst_in_order(tree->left_s);
        printf("%d ", tree->data);
        bst_in_order(tree->right_s);
    }
}

void bst_pre_order(tree_ptr tree) {
    if (tree) {
        printf("%d ", tree->data);
        bst_pre_order(tree->left_s);
        bst_pre_order(tree->right_s);
    }
}

void bst_breadth(tree_ptr tree, int size) {
    tree_ptr *tree_queue, tmp;
    int queue_head = 0;
    int queue_size = 0;

    tree_queue = malloc(size * sizeof(tree_ptr));

    if (!tree_queue) exit(1);

    if (tree) {
        tree_queue[queue_head + queue_size] = tree;
        queue_size++;

        while (queue_size) {
            tmp = tree_queue[queue_head];
            queue_head++;
            queue_size--;
            printf("%d ", tmp->data);

            if (tmp->left_s) {
                tree_queue[queue_head + queue_size] = tmp->left_s;
                queue_size++;
            }

            if (tmp->right_s) {
                tree_queue[queue_head + queue_size] = tmp->right_s;
                queue_size++;
            }
        }
    }

    free(tree_queue);
}

void bst_destroy(tree_ptr tree) {
    if (tree) {
        bst_destroy(tree->left_s);
        bst_destroy(tree->right_s);
        free(tree);
    }
}

int bst_decoder(char *instruction) {
    if (!strcmp(instruction, "inserir")) {
        return INSERT;
    } else if (!strcmp(instruction, "buscar")) {
        return SEARCH;
    } else if (!strcmp(instruction, "pos-ordem")) {
        return POST_ORDER;
    } else if (!strcmp(instruction, "em-ordem")) {
        return IN_ORDER;
    } else if (!strcmp(instruction, "pre-ordem")) {
        return PRE_ORDER;
    } else if (!strcmp(instruction, "largura")) {
        return BREADTH;
    } else if (!strcmp(instruction, "terminar")) {
        return FINISH;
    } else {
        return INVALID;
    }
}
