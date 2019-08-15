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

/*
 * Estrutura para armazenar as triplas em um vetor, seu tamanho e o numero de
 * triplas armazenadas
 */
typedef struct {
    ptr_triple* triples;
    int size;
    int index;
}   Vector;

int main(void) {
    int counter = 0;
    int i, j, num, freq;
    char character;
    ptr_triple* tmp = NULL;

    /* Inicia o vetor de triplas com capacidade para 1 tripla*/
    Vector vector;
    vector.triples_v = malloc(sizeof(Triple))
    vector.size = 1;
    vector.index = 0;
    
    /*
     * Lê as entradas e as armazena no vetor de triplas.
     */
    do {
        /* Se o vetor de triplas estiver completo, dobra seu tamanho */
        if (vector.index = vector.size) {
            tmp = vector.triples_v;
            vector.triples_v = malloc((2 * vector.size) * sizeof(Triple));

            for (i = 0; i < vector.size; i++) {
                vector.triples_v[i] = tmp.triples_v[i];
            }

            vector.size *= 2;
            free(tmp);
            tmp = NULL;         
        }
        
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