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

static unsigned int hashing_function(char *string);

hash_node **hashing_create_table(void) {
    hash_node **hash_table;
    int i;

    hash_table = calloc(TABLE_SIZE, sizeof(hash_node*));

    if (!hash_table) return NULL;

    return hash_table;
}

void hashing_insert(hash_node **hash_table, char *string) {
    hash_node *tmp, *new;
    unsigned int id;

    id = hashing_function(string);
    new = malloc(sizeof(hash_node));

    if (!new) exit(1);

    strcpy(new->string, string);
    new->next = NULL;

    if (!((*hash_table)[id])) {
        (*hash_table)[id] = new;
    } else {
        for (tmp = (*hash_table)[id]; tmp->next; tmp = tmp->next);
        tmp->next = new;
    }
}

static unsigned int hashing_function(char *string) {
    unsigned int hash = 0;

    while (*string) {
        hash += *(string++);
    }

    return hash % TABLE_SIZE;
}