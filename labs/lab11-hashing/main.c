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
#include <stdio.h>
#include "hashing.h"

int main(void) {
    hash_node **hash_table;
    char instruction, key[251];
    int id = 0;

    hash_table = hashing_create_table();

    do {
        scanf(" %c", &instruction);

        switch (instruction) {
        case INSERT:
            scanf(" %s", key);
            hashing_insert(hash_table, key, &id);
            break;
        case SEARCH:
            scanf(" %s", key);
            if (hashing_search(hash_table, key) >= 0) {
                printf("%s encontrada, id %d\n", key, hashing_search(hash_table, key));
            } else {
                printf("%s nao encontrada\n", key);
            }
            break;
        case DELETE:
            scanf(" %s", key);
            hashing_delete(hash_table, key);
            break;
        case FINISH:
            hashing_destroy(hash_table);
            break;
        default:
            break;
        }
    } while (instruction != FINISH);

    return EXIT_SUCCESS;
}
