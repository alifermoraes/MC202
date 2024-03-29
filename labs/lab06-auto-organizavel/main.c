/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 06-auto-organizavel
 *
 * Lista auto-organizável
 *
 * Em uma lista não há uma forma simples que facilite a recuperação dos registros armazenados nos
 * nós: para recuperar o nó na posição i de uma lista é preciso percorrê-la a partir da cabeça,
 * fazendo i acessos a nós.
 *
 * Em muitas aplicações, as freqüências com que os registros são recuperados não são uniformes. Faz
 * sentido que os registros que são recuperados com maior freqüência sejam colocados mais próximos
 * da cabeça, mas tipicamente tais freqüências não são conhecidas e mudam ao longo do tempo.
 *
 * Estratégias de permutação podem ser aplicadas para reduzir o número de acessos a nós da lista
 * durante a recuperação de registros em uma lista. Tais estratégias movem o registro que acabou de
 * ser recuperado um certo número de posições em direção ao início da lista, sem modificar a ordem
 * relativa dos demais registros. Listas acompanhadas de alguma estratégia desse tipo foram
 * chamadas de listas auto-organizáveis.
 * 
 * Algumas estratégias de permutação foram propostas na literatura. As mais usadas incluem:
 * - Move-to-front (MTF): quando um registro é recuperado ele é movido para o início da lista, se
 * ele ainda não estiver no início da lista.
 * - Transpose (TR): quando um registro é recuperado ele é trocado de posição com o registro que o
 * precede, se ele ainda não estiver no início da lista.
 * - Count (C): cada registro tem um contador do número de acessos. Quando um registro é recuperado
 * o contador é incrementado e ele é movido para uma posição anterior a todos os registros com
 * contador menor ou igual ao dele. 
 */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
    int i, count = 0;
    int keys, requests;
    int *requests_list;
    int mtf = 0, tr = 0, c = 0;
    node_ptr list = NULL;

    scanf(" %d", &keys);
    scanf(" %d", &requests);

    requests_list = malloc(requests * sizeof(int));

    for (i = 0; i < requests; i++) {
        scanf(" %d", &requests_list[i]);
    }


    while (count < 3) {
        list = list_create(keys);

        for (i = 0; i < requests; i++) {
            switch(count) {
            case MTF:
                mtf += list_move_to_front(&list, requests_list[i]);
                break;
            case TR:
                tr += list_transpose(&list, requests_list[i]);
                break;
            case C:
                c += list_count(&list, requests_list[i]);
                break;
            default:
                break;
            }
        }

        list_destroy(list);
        count++;
    }

    free(requests_list);
    printf("%d %d %d\n", mtf, tr, c);

    return EXIT_SUCCESS;
}
