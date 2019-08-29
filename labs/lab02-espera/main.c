/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 02-espera
 * 
 * Atendimento
 * Uma loja tem uma fila única que distribui clientes entre os funcionários do
 * atendimento. Um funcionário atende apenas um cliente de cada vez. No início
 * do dia, todos os atendentes estão livres e a fila está vazia. Escreva um
 * programa para calcular informações sobre a espera dos clientes pelo
 * atendimento.
 * 
 * Entrada
 * A primeira linha contém dois inteiros, C e N, separados por um espaço. C é o
 * número de atendentes da loja e N é o número de clientes que virão naquele
 * dia. C está no intervalo [1,10] e N está no intervalo [1,1000]. Cada uma das
 * N linhas seguintes terão informação sobre um cliente na forma de dois
 * inteiros T e D separados por um espaço. T é o momento, em minutos a partir
 * da abertura da loja, em que o cliente entra na fila e D é o tempo em minutos
 * para atender o cliente. T está no intervalo [0,300] e D está no intervalo
 * [1,10]. As linhas estão ordenadas pelo momento de entrada dos clientes na
 * fila.
 * 
 * Saída
 * A primeira linha da saída deve informar a espera média ao longo do dia, como
 * ilustrado no exemplo abaixo. A segunda linha deve informar o número de
 * clientes que esperaram na fila por mais de 10 minutos. 
 */

#include <stdlib.h>
#include <stdio.h>

#define GREATER(a, b) a > b ? a : b

int main(void) {
    int *attendants;
    int i, j, aux;
    int attendants_num, custommers_num;
    int entrance_time, attendance_time;
    int more_than_10 = 0, total_waiting = 0, waiting_time;
    float mean_waiting_time;


    scanf(" %d %d", &attendants_num, &custommers_num);

    /**
     * Vetor que armazena o instante ate o qual cada atendente estara ocupado,
     * inicia todos em 0 pois ao abrir a loja os atendentes nao estao atendendo
     */
    attendants = calloc(attendants_num, sizeof(int));

    for (i = 0; i < custommers_num; i++) {
        scanf(" %d %d", &entrance_time, &attendance_time);

        /**
         * Calcula o tempo de espera de cada cliente baseado no instante de
         * entrada do cliente e o instante em que um atendente estara disponivel
         */
        waiting_time = attendants[0] - entrance_time;
        waiting_time = GREATER(0, waiting_time);

        /* Debugging */
        #ifdef DEBUG
            printf("Instante de entrada do cliente #%d: %d, ", i + 1,
                    entrance_time);
            printf("instante de atendimento do cliente #%d: %d, ", i + 1,
                   MAIOR(attendants[0], entrance_time));
            printf("espera do cliente #%d: %d\n", i + 1, waiting_time);
        #endif

        /**
         * Computa o tempo de espera caso todos os atendentes estejam
         * ocupados e atribui o tempo de atendimento do cliente ao proximo
         * atendente que estara disponivel
         */
        if (waiting_time) {
            if (waiting_time > 10) {
                more_than_10++;
            }

            total_waiting += waiting_time;
            attendants[0] += attendance_time;
        } else { /* Caso haja atendentes disponiveis  */
            attendants[0] = entrance_time + attendance_time;
        }

        /* Debugging */
        #ifdef DEBUG
            printf("Espera total: %d\n", total_waiting);
            printf("Atendente ocupado ate: %d\n", attendants[0]);
        #endif

        /**
         * Mantem o vetor de atendentes ordenado de tal forma que os atendentes
         * que terminarao o atendimento primeiro estejam sempre na primeira
         * posicao, o proximo na segunda e assim por diante.
         */
        for (j = 0; j < attendants_num - 1; j++) {
            if (attendants[j] > attendants[j + 1]) {
                aux = attendants[j + 1];
                attendants[j + 1] = attendants[j];
                attendants[j] = aux;
            }
        }
    }

    free(attendants);

    mean_waiting_time = (float) total_waiting  / custommers_num;

    printf("Espera media para %d clientes: %.1f minutos\n", custommers_num,
            mean_waiting_time);
    printf("Numero de clientes que esperaram mais que 10 minutos: %d\n",
           more_than_10);

    return EXIT_SUCCESS;
}