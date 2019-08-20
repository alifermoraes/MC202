/*
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 01-sumatriz
 * 
 * Submatriz
 * Dada uma matriz de inteiros positivos n por m, estamos interessados em
 * encontrar a maior soma de elementos possível em uma submatriz de tamanho r
 * por s.
 *
 * Entrada
 * A entrada tem uma linha com inteiros n, m, r, s separados por espaços, sendo
 * que 1≤n≤1000, 1≤m≤1000, 1≤r≤n e 1≤s≤m. Depois vêm n linhas com m inteiros
 * cada, com os números em cada linha e coluna da matriz.
 *
 * Saída
 * O programa deve imprimir o valor da maior soma possível em uma submatriz de
 * tamanho r por s em uma única linha.
 */

#include <stdio.h>
#include <limits.h>

#define MAIOR(a, b) a > b ? a : b

int main(void) {
    int lines, columns, sub_lines, sub_columns;
    int result = INT_MIN;
    int sum, value;
    int i, j;

    /**
     * Le os dados de entrada e cria uma matriz extendida com a primeira linha  * e primeira coluna compostas por zeros
     */
    scanf(" %d %d %d %d", &lines, &columns, &sub_lines, &sub_columns);

    int M[lines + 1][columns + 1];
    for (i = 0; i <= lines; i++)
        M[i][0] = 0;
    
    for (i = 0; i <= columns; i++)
        M[0][i] = 0;

    /**
     * Le os valores de entrada na matriz, salvando em cada posicao i, j a
     * soma dos valores compreendidos pela submatriz de dimensao i x j
     */
    for (i = 1; i <= lines; i++) {
        for (j = 1; j <= columns; j++) {
            scanf(" %d", &value);
            M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1] + value;
        }
    }

    /**
     * Percorre a matriz de somas, retornando a maior soma de uma submatriz de dimensao sub_lines x sub_columns
     */

    for (i = sub_lines; i <= lines; i++) {
        for (j = sub_columns; j <= columns; j++) {
            sum = M[i][j] + M[i - sub_lines][j - sub_columns] -
            M[i - sub_lines][j] - M[i][j - sub_columns];

            result = MAIOR(sum, result);
        }
    }

    printf("%d\n", result);

    return 0;
}