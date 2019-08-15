/*
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
 * O programa recebe como entrada uma seqüência de triplas (número,freqencia,caractere). Para cada seqüência ele deve imprimir uma barra, produzindo um gráfico
 * como no exemplo abaixo.
 *
 * Haverá pelo menos uma tripla na entrada, e todas são bem formadas. O número é menor que 1000 e a freqüência é maior ou igual a 1 e menor que 100.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int num;
    int freq;
    char character;
} Triple;

typedef Triple * ptr_triple;

int main(void) {
    int counter = 0;
    int i, j, num, freq;
    char _char;
    ptr_triple* triple_v;

    triple_v = malloc(1000 * sizeof(ptr_triple));

    do {
        triple_v[counter] = malloc(sizeof(Triple));
        scanf(" (%d,%d,%c)", &triple_v[counter]->num, &triple_v[counter]->freq, &triple_v[counter]->character);
        counter++;
    } while (getchar() != EOF);

    for (i = 0; i < counter; i++) {
        num = triple_v[i]->num;
        freq = triple_v[i]->freq;
        _char = triple_v[i]->character;

            printf("%3d |", num);
            for (j = 0; j < freq; j++) {
                printf("%c", _char);
            }

            printf(" %d\n", freq);
    }

    return EXIT_SUCCESS;
}