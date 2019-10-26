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
#include <string.h>
#include "binary_search_tree.h"

tree_ptr bst_create(void) {
    return NULL;
}

/* Retorna 1 se adicionar o novo nó com sucesso, caso contrário retorna 0. */
int bst_insert(tree_ptr *tree, int data) {
    tree_ptr new, tmp;

    new = malloc(sizeof(Tree));

    if (!new) exit(1);

    new->data = data;
    new->parent = NULL;
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
                    new->parent = tmp;
                    tmp->left_s = new;
                    return 1;
                }

                tmp = tmp->left_s;
            } else {
                if (!tmp->right_s) {
                    new->parent = tmp;
                    tmp->right_s = new;
                    return 1;
                }

                tmp = tmp->right_s;
            }
        }
    }

    return 1;
}

/* Retorna o nó caso encontre-o, caso contrário retorna NULL. */
tree_ptr bst_search(tree_ptr tree, int data) {
    while (tree) {
        if (tree->data == data) {
            return tree;
        } else if (data < tree->data) {
            tree = tree->left_s;
        } else {
            tree = tree->right_s;
        }
    }

    return NULL;
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

    if (tree) {
        tree_queue = malloc(size * sizeof(tree_ptr));

        if (!tree_queue) exit(1);

        tree_queue[queue_head + queue_size] = tree;
        queue_size++;

        while (queue_size) {
            tmp = tree_queue[queue_head];
            printf("%d ", tmp->data);
            queue_head++;
            queue_size--;

            if (tmp->left_s) {
                tree_queue[queue_head + queue_size] = tmp->left_s;
                queue_size++;
            }

            if (tmp->right_s) {
                tree_queue[queue_head + queue_size] = tmp->right_s;
                queue_size++;
            }
        }

        free(tree_queue);
    }
}

int bst_delete(tree_ptr *tree, int data) {
    tree_ptr tmp, replacement;

    tmp = bst_search(*tree, data);

    if (!tmp) { /* Chave a ser removida não existe. */
        return 0;
    }

    if (tmp->left_s && tmp->right_s) { /* Nó a ser removido possui dois filhos. */
        replacement = bst_min(tmp->right_s); /* Encontra o sucessor do nó a ser removido. */

        /**
         * O sucessor do nó a ser removido só pode possuir filho direito (pois é o menor valor da
         * sub arvore correspondente), caso possua filho direito esse filho torna-se filho
         * esquerdo do pai do sucessor.
         * O nó a ser removido é substituido por seu sucessor e seus filhos tornam-se filhos
         * do nó sucessor.
         */
        if (tmp->right_s != replacement) { /* O filho direito do nó removido não é o sucessor. */
            replacement->parent->left_s = replacement->right_s;

            if (replacement->right_s) {
                replacement->right_s->parent = replacement->parent;
            }
            
            replacement->right_s = tmp->right_s;
            replacement->right_s->parent = replacement;
        }

        replacement->left_s = tmp->left_s;
        replacement->left_s->parent = replacement;
    } else if (tmp->left_s) { /* Nó a ser removido possui apenas filho esquerdo. */
        replacement = tmp->left_s;
    } else if (tmp->right_s) { /* Nó a ser removido possui apenas filho direito. */
        replacement = tmp->right_s;
    } else { /* Nó a ser removido não possui filhos. */
        replacement = NULL;
    }

    if (replacement) {
        replacement->parent = tmp->parent;
    }

    if (tmp->parent) {
        if (tmp->parent->left_s == tmp) {
            tmp->parent->left_s = replacement;
        } else {
            tmp->parent->right_s = replacement;
        }
    } else { /* Nó a ser removido é a raiz */
        *tree =  replacement;
    }

    free(tmp);

    return 1;
}

tree_ptr bst_min(tree_ptr tree) {
    while (tree && tree->left_s) {
        tree = tree->left_s;
    }

    return tree;
}

tree_ptr bst_max(tree_ptr tree) {
    while (tree && tree->right_s) {
        tree = tree->right_s;
    }

    return tree;
}

tree_ptr bst_successor(tree_ptr tree, int data) {
    tree_ptr tmp, ancestor;

    tmp = bst_search(tree, data);

    if (tmp) {
        if (tmp->right_s) {
            return bst_min(tmp->right_s);
        } else {
            /**
             * Nó não possui filho direito, portanto seu sucessor é o ancestral mais próximo cujo
             * valor é maior do que o do nó em questão.
             */
            ancestor = tmp->parent;

            while (ancestor && (tmp == ancestor->right_s)) {
                tmp = ancestor;
                ancestor = tmp->parent;
            }

            return ancestor;
        }
    }

    return NULL;
}

tree_ptr bst_predecessor(tree_ptr tree, int data) {
    tree_ptr tmp, ancestor;

    tmp = bst_search(tree, data);

    if (tmp) {
        if (tmp->left_s) {
            return bst_max(tmp->left_s);
        } else {
            /**
             * Nó não possui filho esquerdo, portanto seu predecessor é o ancestral mais próximo
             * cujo valor é menor do que o do nó em questão. 
             */
            ancestor = tmp->parent;

            while (ancestor && (tmp == ancestor->left_s)) {
                tmp = ancestor;
                ancestor = tmp->parent;
            }

            return ancestor;
        }
    }

    return NULL;
}

void bst_range_search(tree_ptr tree, int r_min, int r_max, int *flag) {
    if (tree) {
        if (tree->data >= r_min) {
            bst_range_search(tree->left_s, r_min, r_max, flag);
        }

        if ((tree->data >= r_min) && (tree->data <= r_max)) {
            printf("%d ", tree->data);
            *flag = 1;
        }

        if (tree->data <= r_max) {
            bst_range_search(tree->right_s, r_min, r_max, flag);
        }
    }
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
    } else if (!strcmp(instruction, "remover")) {
        return DELETE;
    } else if (!strcmp(instruction, "minimo")) {
        return MIN;
    } else if (!strcmp(instruction, "maximo")) {
        return MAX;
    } else if (!strcmp(instruction, "sucessor")) {
        return SUCCESSOR;
    } else if (!strcmp(instruction, "predecessor")) {
        return PREDECESSOR;
    } else if (!strcmp(instruction, "buscar-intervalo")) {
        return RANGE_SEARCH;
    } else if (!strcmp(instruction, "terminar")) {
        return FINISH;
    } else {
        return INVALID;
    }
}
