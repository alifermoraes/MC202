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
#include "list.h"

Array dynamic_create(void) {
    Array array;

    array.data = malloc(sizeof(int));
    array.head = 0;
    array.size = 0;
    array.max_size = 1;

    return array;
}

void dynamic_inject(Array *array, int data) {
    if (!(array->size)) {
        array->data[0] = data;
        array->head = 0;
    } else {
        if (array->size == array->max_size) {
            dynamic_resize(array, INC);
        }

        array->head = ((array->head - 1) + array->max_size) % array->max_size;
        array->data[array->head] = data;
    }

    array->size++;
}

void dynamic_eject(Array *array) {
    if (array->size) {
        data = array->data[array->head];
        array->head = (array->head + 1) % array->max_size;
        array->size--;
    }
}

void dynamic_print_head(Array array) {
    if (array.size) {
        printf("%d\n", array.data[array.head]);
    }
}

void dynamic_push(Array *array, int data) {
    int tail;

    if (!(array->size)) {
        array->data[0] = data;
        array->head = 0;
    } else {
        if (array->size == array->max_size) {
            dynamic_resize(array, INC);
        }

        tail = (array->head + array->size) % array->max_size;
        array->data[tail] = data;
    }

    array->size++;
}

void dynamic_pop(Array *array) {
    if (array->size) {
        array->size--;
    }
}

void dynamic_print_tail(Array array) {
    int tail;

    tail = (array.head + array.size - 1) % array.max_size;

    if (array.size) {
        printf("%d\n", array.data[tail]);
    }
}

int dynamic_is_empty(Array array) {
    return array.size;
}

static void dynamic_resize(Array *array, int inc_dec) {
    /* Implementar */
}
