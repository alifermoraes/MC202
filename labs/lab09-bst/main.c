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
#include "binary_search_tree.h"

int main(void) {
    tree_ptr tree;
    char operation, instruction[11];
    int data, tree_size = 0;

    tree = bst_create();

    do {
        scanf(" %s", instruction);
        operation = bst_decoder(instruction);

        switch (operation) {
        case INSERT:
            scanf(" %d", &data);
            if (bst_insert(&tree, data)) {
                tree_size++;
            }
            break;
        case SEARCH:
            scanf(" %d", &data);
            if (bst_search(tree, data)) {
                printf("%d pertence\n", data);
            } else {
                printf("%d nao pertence\n", data);
            }
            break;
        case POST_ORDER:
            if (tree) {
                bst_post_order(tree);
            } else {
                printf("vazia");
            }
            printf("\n");
            break;
        case IN_ORDER:
            if (tree) {
                bst_in_order(tree);
            } else {
                printf("vazia");
            }
            printf("\n");
            break;
        case PRE_ORDER:
            if (tree) {
                bst_pre_order(tree);
            } else {
                printf("vazia");
            }
            printf("\n");
            break;
        case BREADTH:
            if (tree) {
                bst_breadth(tree, tree_size);
            } else {
                printf("vazia");
            }
            printf("\n");
            break;
        case FINISH:
            bst_destroy(tree);
            break;
        default:
            break;
        }
    } while (operation != FINISH);

    return EXIT_SUCCESS;
}
