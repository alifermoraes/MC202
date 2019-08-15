/*
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 01-sumatriz
 * 
 * Submatriz
 * Dada uma matriz de inteiros positivos n por m, estamos interessados em encontrar a maior soma de
 * elementos possível em uma submatriz de tamanho r por s.
 *
 * Entrada
 * A entrada tem uma linha com inteiros n, m, r, s separados por espaços, sendo que 1≤n≤1000,
 * 1≤m≤1000, 1≤r≤n e 1≤s≤m. Depois vêm n linhas com m inteiros cada, com os números em cada linha
 * e coluna da matriz.
 *
 * Saída
 * O programa deve imprimir o valor da maior soma possível em uma submatriz de tamanho r por s em
 * uma única linha.
 */

#include <stdio.h>

#define MAIOR(a, b) a > b ? a : b

int main(void) {
    int lines, columns, sub_lines, sub_columns;
    int sum, result = 0;
    int i, j, k, l;

    /* Le os dados de entrada e cria a matriz*/
    scanf(" %d %d %d %d", &lines, &columns, &sub_lines, &sub_columns);

    int M[lines][columns];

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            scanf(" %d", &M[i][j]);
        }
    }

    /* Calcula as somas das submatrizes e retorna o maior valor obtido */
    for (i = 0; i <= lines - sub_lines; i++) { /* Laço para percorrer a matriz original e avaliar cada submatriz possivel */
        for (j = 0; j <= columns - sub_columns; j++) {
            sum = 0;

            for (k = i; k < i + sub_lines; k++) { /* Laço para percorrer e somar os valores das submatrizes */
                for (l = j; l < j + sub_columns; l++) {
                    sum += M[k][l];
                }
            }

            result = MAIOR(result, sum);
        }

    }

    printf("%d\n", result);

    return 0;
}