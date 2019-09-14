/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 05-triangular
 * 
 * Jagged array
 * Em C, um array multidimensional é implementado colocando todos os elementos dele na memória
 * seqüencialmente, por linhas. Os elementos são acessados calculando um deslocamento a partir do
 * primeiro elemento do array.
 * Outra forma de implementar um array com n dimensões é usando um array unidimensional (vetor) de
 * apontadores para arrays com n-1 dimensões. Essa forma de implementação é usada por várias
 * linguagens de programação (mas não C, como vimos). Dessa forma um array 3 x 3 x 3 seria
 * implementado como na figura abaixo.
 * 
 * Um jagged array é um array multidimensional implementado usando apontadores e com elementos de
 * tamanhos diferentes, por exemplo, matrizes triangulares e outras, como as que estão ilustradas
 * abaixo.
 * Escreva um programa para ler uma matriz triangular inferior de números fracionários fornecidos
 * na entrada padrão, armazená-los dinamicamente na memória como um jagged array e calcular os
 * valores normalizados. O programa deve usar a quantidade mínima de memória possível.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    int i, j;
    int lines, elements = 0;
    double mean = 0, std_deviation = 0;
    double **jagged_array;

    scanf(" %d", &lines);
    jagged_array = malloc(lines * sizeof(double*));

    for (i = 0; i < lines; i++) {
        jagged_array[i] = malloc((i + 1) * sizeof(double));

        for (j = 0; j < (i + 1); j++) {
            scanf(" %lf", &jagged_array[i][j]);
            mean += jagged_array[i][j];
            elements++;
        }
    }

    mean /= elements;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < (i + 1); j++) {
            std_deviation += pow((jagged_array[i][j] - mean), 2);
        }
    }

    std_deviation = sqrt(std_deviation / elements);

    for (i = 0; i < lines; i++) {
        for (j = 0; j < (i + 1); j++) {
            printf("%.12lf ", (jagged_array[i][j] - mean) / std_deviation);
        }

        printf("\n");
        free(jagged_array[i]);
    }

    printf("\n%.12lf %.12lf \n", mean, std_deviation);
    free(jagged_array);

    return EXIT_SUCCESS;
}
