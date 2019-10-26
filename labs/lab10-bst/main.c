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

#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"

int main(void) {
    tree_ptr tree, tmp;
    char operation, instruction[17];
    int data, r_min, r_max, flag = 0, tree_size = 0;

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
        case DELETE:
            scanf(" %d", &data);
            if (bst_delete(&tree, data)) {
                tree_size--;
            }
            break;
        case MIN:
            tmp = bst_min(tree);

            if (tmp) {
                printf("%d\n", tmp->data);
            } else {
                printf("vazia\n");
            }
            break;
        case MAX:
            tmp = bst_max(tree);

            if (tmp) {
                printf("%d\n", tmp->data);
            } else {
                printf("vazia\n");
            }
            break;
        case SUCCESSOR:
            scanf(" %d", &data);
            tmp = bst_successor(tree, data);

            if (tmp) {
                printf("%d\n", tmp->data);
            } else {
                printf("nao ha\n");
            }
            break;
        case PREDECESSOR:
            scanf(" %d", &data);
            tmp = bst_predecessor(tree, data);

            if (tmp) {
                printf("%d\n", tmp->data);
            } else {
                printf("nao ha\n");
            }
            break;
        case RANGE_SEARCH:
            scanf(" %d %d", &r_min, &r_max);
            bst_range_search(tree, r_min, r_max, &flag);
            
            if (flag) {
                printf("\n");
                flag = 0;
            } else {
                printf("nenhuma\n");
            }
        case FINISH:
            bst_destroy(tree);
            break;
        default:
            break;
        }
    } while (operation != FINISH);

    return EXIT_SUCCESS;
}
