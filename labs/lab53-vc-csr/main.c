/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 53-vc-csr
 *
 *  Uma matriz m x n é esparsa se tem proporcionalmente muitos zeros. "Muitos" não é uma quantidade
 * definida claramente, mas em geral se a matriz tem um número de entradas não-zero proporcional a
 * m + n então ela é considerada esparsa.
 *
 * Por exemplo, suponha uma matriz de int 1.000 x 3.000 que tenha 3.000 entradas não-zero. Essa
 * matriz é esparsa. Ela ocupa 12.000.000 bytes na memória, mas apenas 12.000 bytes não são zeros.
 *
 * Uma forma mais econômica de armazenar uma matriz esparsa é o vetor-de-coordenadas. Nessa
 * representação, cada entrada não-zero é representada por uma tripla (i, j, M[i,j]) e tais triplas
 * são armazenadas em um vetor. Tipicamente (mas não obrigatoriamente) o vetor-de-coordenadas é
 * mantido ordenado por i e, para o mesmo i, ordenado por j.
 *
 * A matriz suposta previamente, com 3.000 não-zeros, seria armazenada em um vetor de 36.000 bytes.
 * 
 * Para recuperar a entrada M[i,j], é necessário fazer uma busca no vetor de coordenadas para
 * encontrar a linha i e depois fazer uma busca para encontrar a coluna j.
 *
 * Uma outra forma de representação de matrizes esparsas que permite recuperação mais rápida que o
 * vetor-de-coordenadas é a CSR (compressed sparse row).
 *
 * Seja M uma matriz m x n com k células diferentes de zero, com linhas e colunas indexadas a
 * partir de 0. A representação CSR usa 3 vetores:
 *
 * - A, de tamanho k, armazenas as células não-zero de M por linhas.
 * - C, de tamanho k, armazena a coluna de cada elemento de A.
 * - R, de tamanho m+1, armazena a posição em A do primeiro elemento em cada linha não-vazia de M.
 * - R[m] é igual a k.
 * - Se a linha i estiver vazia então R[i] será igual a R[t], onde t é a primeira linha depois da
 * linha i que não é vazia. Se não houver tal t então R[i]=R[m].
 * - R[i+1]-R[i] é o número de células não-zero na linha i. 
 *
 * Um elemento M[i,j] pode ser recuperado da seguinte forma:
 *
 * - Inspecionam-se R[i] e R[i+1] para determinar o intervalo ocupado pelos elementos da linha i em
 * - C (e também em A).
 * - Se R[i] é igual a R[i+1] então M[i,j] é igual a zero. Senão j é procurado em C[R[i]], ...,
 * - C[R[i+1]-1].
 * - Se j existe em [C[R[i]], ..., C[R[i+1]-1] então o valor de A na mesma posição de C em que j foi
 * encontrado é M[i,j]. Senão M[i,j] é igual a zero. 
 *
 * Por exemplo, a matriz 4 x 8
 *
 * 0  0  0  0  2  0  6  5
 * 4  0  0  0  0  1  0  0
 * 0  0  0  0  0  0  0  0
 * 0  0  0  0  3  0  8  1
 *
 * é representada como um vetor-de-coordenadas da forma
 *
 * (0,4,2) (0,6,6) (0,7,5) (1,0,4) (1,5,1) (3,4,3) (3,6,8) (3,7,1)
 *
 * e é representada da seguinte forma em CSR
 *
 * A  =  2  6  5  4  1  3  8  1
 * C  =  4  6  7  0  5  4  6  7
 * R  =  0  3  5  5  8
 *
 * Escreva um programa para manipular uma matriz esparsa de inteiros M. Inicialmente seu programa
 * deve ler um conjunto de k triplas (i,j,dado) e armazená-las em um vetor-de-coordenadas. Depois
 * deve converter o vetor de coordenadas em CSR. Finalmente, o programa deve usar a representação
 * CSR para recuperar entradas da matriz esparsa.
 * 
 * A entrada inicia-se com uma linha contendo o valor inteiro k, k>0. Depois seguem-se k linhas
 * contendo i, j e dado, i,j≥0. As linhas seguintes têm i e j cada, i,j≥0, e formam uma seqüência
 * de coordenadas que devem ser usadas como consulta para recuperar um dado da matriz. A seqüência
 * de consultas é terminada por valores -1. 
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int c_row;
    int c_col;
    int c_val;
} Coordinates;

int main(void) {
    int i, j;
    int values;
    int row, col, val;
    int *A, *C, *R;
    Coordinates tmp;
    Coordinates *coordinates;

    scanf(" %d", &values);
    coordinates = malloc(values * sizeof(Coordinates));

    for (i = 0; i < values; i++) {
        scanf(" %d %d %d", &coordinates[i].c_row, &coordinates[i].c_col, &coordinates[i].c_val);

        /* Ordena as triplas por linhas e colunas */
        for (j = i; j > 0; j--) {
            if ((coordinates[j].c_row < coordinates[j - 1].c_row) ||
                ((coordinates[j].c_row == coordinates[j - 1].c_row) &&
                (coordinates[j].c_col < coordinates[j - 1].c_col))) {
                tmp = coordinates[j];
                coordinates[j] = coordinates[j - 1];
                coordinates[j - 1] = tmp;
            }
        }
    }

    A = malloc(values * sizeof(int));
    C = malloc(values * sizeof(int));
    R = malloc((coordinates[i - 1].c_row + 2) * sizeof(int));

    /*
    for (i = 0; i < values; i++) {
        printf("(%d, %d, %d) ", coordinates[i].c_row, coordinates[i].c_col, coordinates[i].c_val);
    }

    printf("\n");*/
    free(A);
    free(C);
    free(R);
    free(coordinates);

    return EXIT_SUCCESS;
}
