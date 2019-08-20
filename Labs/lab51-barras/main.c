/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 51-barras
 * 
 * Escreva um programa em C para imprimir um gráfico de frequências na tela.
 *
 * Entrada e saída
 * O programa recebe como entrada uma seqüência de triplas (número,freqencia
 * caractere). Para cada seqüência ele deve imprimir uma barra, produzindo um
 * gráfico
 * como no exemplo abaixo.
 *
 * Haverá pelo menos uma tripla na entrada, e todas são bem formadas. O número
 * é menor que 1000 e a freqüência é maior ou igual a 1 e menor que 100.
 */

#include <stdlib.h>
#include <stdio.h>

/* Estrutura para armazenar os valores da tripla ordenadamente */
typedef struct {
    int number;
    int frequency;
    char character;
} Triple;

typedef Triple * ptr_triple;

int main(void) {
    int i, j, num, freq, v_size, v_index;
    char character;
    ptr_triple tmp = NULL;

    /* Inicia o vetor de triplas com capacidade para 1 tripla */
    ptr_triple v_triples = malloc(sizeof(Triple));
    v_size = 1;
    v_index = 0;
    
    /* Lê as entradas e as armazena no vetor de triplas */
    do {
        /* Se o vetor de triplas estiver cheio, dobra seu tamanho */
        if (v_index == v_size) {
            tmp = v_triples;
            v_size *= 2;
            v_triples = malloc(v_size * sizeof(Triple));

            for (i = 0; i < v_size; i++) {
                v_triples[i] = tmp[i];
            }

            free(tmp);
            tmp = NULL;         
        }
        
        scanf(" (%d,%d,%c)", &v_triples[v_index].number,
              &v_triples[v_index].frequency, &v_triples[v_index].character);
        v_index++;
    } while (getchar() != EOF);

    for (i = 0; i < v_index; i++) {
        num = v_triples[i].number;
        freq = v_triples[i].frequency;
        character = v_triples[i].character;

            printf("%3d |", num);
            for (j = 0; j < freq; j++) {
                printf("%c", character);
            }

            printf(" %d\n", freq);
    }

    free(v_triples);
    v_triples = NULL;  

    return EXIT_SUCCESS;
}