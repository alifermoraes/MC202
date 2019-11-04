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
    char instruction;

    do {
        scanf(" %c", &instruction);

        switch (instruction) {
        case INSERT:
            break;
        case SEARCH:
            break;
        case DELETE:
            break;
        case FINISH:
            break;
        default:
            break;
        }
    } while (instruction != FINISH);

    return EXIT_SUCCESS;
}
