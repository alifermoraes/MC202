/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 11-hashing
 *
 * Hashing de cadeias
 *
 * Este trabalho consiste em implementar uma tabela de hashing para armazenar cadeias do alfabeto
 * {a,b,...,z,A,B,...,Z,_}. No máximo 5.000 cadeias de no máximo 250 caracteres estarão armazenadas
 * na tabela ao mesmo tempo.
 *
 * As colisões devem ser resolvidas usando sondagem com hashing duplo ou encadeamento na própria
 * tabela. Defina o tamanho e a função de hashing para a sua tabela.
 *
 * Escolha também uma função de transformação de cadeias de caracteres em inteiros.
 */

#include <stdlib.h>
#include <string.h>
#include "hashing.h"

static int hashing_function(char *key);

hash_node **hashing_create_table(void) {
    hash_node **hash_table;

    hash_table = calloc(TABLE_SIZE, sizeof(hash_node*));

    if (!hash_table) return NULL;

    return hash_table;
}

void hashing_insert(hash_node **hash_table, char *key, int *id) {
    hash_node *tmp, *new;
    int pos;

    if (hashing_search(hash_table, key) >= 0) { /* Chave ja existe na tabela. */
        return;
    }

    pos = hashing_function(key);
    new = malloc(sizeof(hash_node));

    if (!new) exit(1);

    strcpy(new->key, key);
    new->next = NULL;
    new->id = *id;
    (*id)++;

    if (!hash_table[pos]) { /* Posição vazia na tabela hash. */
        hash_table[pos] = new;
    } else { /* Colisão -> resolve por encadeamento. */
        for (tmp = hash_table[pos]; tmp->next; tmp = tmp->next);
        tmp->next = new;
    }
}

/**
 * Essa função busca se uma cadeia de caracteres pertence à tabela hash.
 * Se a cadeia pertence, a função retorna seu ID, caso contrário retorna -1.
 */
int hashing_search(hash_node **hash_table, char *key) {
    hash_node *tmp;
    int pos;

    pos = hashing_function(key);

    if (hash_table[pos]) { /* Existe algo na posição da tabela onde a cadeia deveria estar? */
        tmp = hash_table[pos];

        while (tmp) {
            if (!strcmp(key, tmp->key)) {
                return tmp->id;
            }

            tmp = tmp->next;
        }
    }

    return -1;
}

void hashing_delete(hash_node **hash_table, char *key) {
    hash_node *curr, *prev;
    int pos;

    pos = hashing_function(key);

    if (hash_table[pos]) {
        prev = NULL;
        curr = hash_table[pos];

        while (curr) {
            if (!strcmp(key, curr->key)) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    hash_table[pos] = NULL;
                }

                free(curr);
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
}

void hashing_destroy(hash_node **hash_table) {
    hash_node *curr, *tmp;
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i]) {
            curr = hash_table[i];

            while (curr) {
                tmp = curr;
                curr = curr->next;

                free(tmp);
            }
        }
    }

    free(hash_table);
}

static int hashing_function(char *key) {
    int hash = 0;

    while (*key) {
        hash += *(key++);
    }

    return hash % TABLE_SIZE;
}
