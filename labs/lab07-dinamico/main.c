/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 07-dinamico
 *
 * Vetor dinâmico
 * Vamos dizer que um conjunto de registros está em sequência se a ordem relativa entre eles é
 * importante. Por exemplo, pessoas em uma fila de atendimento formam uma sequência.
 * 
 * Neste trabalho você deve implementar um vetor dinâmico para armazenar uma sequência de números
 * inteiros. O vetor dinâmico deve permitir inserção no início e no final da sequência, remoção do
 * primeiro e do último elementos e recuperação do primeiro e do último elementos.
 * 
 * A sequência deve ser implementada de forma circular, isto é, o primeiro elemento dela deve poder
 * estar em qualquer posição do vetor. Dessa forma, qualquer uma dessas operações acima poderá ser
 * realizada em tempo constante, não é necessário fazer deslocamento dos dados armazenados no vetor
 * para a esquerda ou para a direita.
 * 
 * Por exemplo, a sequência circular de chaves inteiras [2,9,5,7] pode estar armazenada de várias
 * formas em um vetor de tamanho 8:
 * 
 * 2 9 5 7 _ _ _ _  
 * _ _ 2 9 5 7 _ _  
 * _ _ _ _ 2 9 5 7  
 * 5 7 _ _ _ _ 2 9  
 * 9 5 7 _ _ _ _ 2 
 * 
 * Em todas elas, o primeiro elemento da sequência é o 2 e o último é o 7. Observe que os números
 * não estão ordenados, mas a ordem relativa entre eles deve ser preservada.
 * 
 * A política de redimensionamento do vetor deve ser dobrar quando estiver cheio e reduzir à metade
 * quando estiver 1/4 ocupado. Dessa forma, durante o processamento, o número de posições vazias do
 * vetor não deveria exceder 3n, onde n é o número de posições ocupadas.
 * 
 * Obviamente, quando o vetor for redimensionado, o conteúdo da seqüência e a ordem relativa entre
 * os elementos da seqüência devem ser preservados. 
 */

#include <stdlib.h>
#include <stdio.h>
#include "dynamic.h"

int main(void) {
    char instruction[13], operation;
    int data;
    Array array;

    array = dynamic_create();

    do {
        scanf(" %s", instruction);
        operation = dynamic_decoder(instruction);

        switch (operation) {
        case INSERT_FIRST:
            scanf(" %d", &data);
            dynamic_inject(&array, data);
            break;

        case REMOVE_FIRST:
            dynamic_eject(&array);
            break;

        case PRINT_FIRST:
            dynamic_print_head(array);
            break;

        case INSERT_LAST:
            scanf(" %d", &data);
            dynamic_push(&array, data);
            break;

        case REMOVE_LAST:
            dynamic_pop(&array);
            break;

        case PRINT_LAST:
            dynamic_print_tail(array);
            break;

        case IS_EMPTY:
            dynamic_is_empty(array);
            break;

        case EXIT:
            free(array.data);
            break;
        
        default:
            break;
        }

    } while (operation != EXIT);

    return EXIT_SUCCESS;
}
