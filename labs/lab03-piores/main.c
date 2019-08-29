/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 03-piores
 * 
 * Professores frequentemente ouvem desculpas de alunos que não entregaram seus
 * trabalhos. Algumas são relatos de casualidades cotidianas, outras são apenas
 * esfarrapadas. Escreva um programa para escolher as piores desculpas segundo
 * algumas palavras-chave. 
 *
 * Entrada
 * A entrada para o programa consiste de vários conjuntos de dados. A linha 1
 * de cada conjunto tem dois inteiros. O primeiro (1 ≤ K ≤ 20) define o número
 * de palavras-chave. O segundo (1 ≤ E ≤ 100) define o número de desculpas no
 * conjunto. As linhas 2 a K + 1 têm uma palavra-chave cada. Todas as
 * palavras-chave terão apenas caracteres alfabéticos minúsculos e não terão
 * brancos. 
 * As linhas K + 2 a K + E + 1 têm uma desculpa cada. Cada desculpa poderá
 * conter qualquer caractere alfanumérico maiúsculo ou minúsculo, espaços ou
 * quaisquer dos sinais de pontuação ".,!? e não excederá 100 caracteres de
 * comprimento. Nenhuma desculpa será formada apenas por espaços. 
 *
 * Saida
 * Para cada conjunto de entrada, seu programa você deve imprimir as piores
 * desculpas do conjunto. As piores desculpas são aquelas que contêm o maior
 * número de ocorrências de palavras-chave. Uma palavra-chave ocorre em uma
 * desculpa se ela existir na desculpa de forma contígua e se for delimitada
 * pelo início da linha, pelo fim da linha, por um caractere não alfabético ou
 * por um espaço.
 * Para cada conjunto de entrada, seu programa deve imprimir uma única linha
 * com o número do conjunto imediatamente após a cadeia "Conjunto de desculpas
 * #". As linhas seguintes devem) conter as piores desculpas, uma por linha,
 * exatamente como aparece na entrada. Se houver mais de uma pior desculpa, seu
 * programa deverá imprimi-las na ordem em que aparecem na entrada. Após cada
 * conjunto de saída, seu programa deve imprimir uma linha em branco. 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void free_list(char** list, int size);

int main (void) {
    int keywords, excuses;
    int i, j, counter = 1;
    char* comparison = NULL;
    char** keywords_list = NULL;
    char** excuses_list = NULL;

    do {
        scanf(" %d %d", &keywords, &excuses);

        printf("Conjunto de desculpas #%d\n", counter);

        keywords_list = malloc(keywords * sizeof(char*));
        excuses_list = malloc(excuses * sizeof(char*));

        for (i = 0; i < keywords; i++) {
            keywords_list[i] = malloc(sizeof(char[31]));
            scanf(" %[^\n]", keywords_list[i]);
        }

        for (i = 0; i < excuses; i++) {
            excuses_list[i] = malloc(sizeof(char[101]));
            scanf(" %[^\n]", excuses_list[i]);
            for(j = 0; j < keywords && !comparison; j++) {
                comparison = strstr(excuses_list[i], keywords_list[j]);
            }

            if (comparison) {
                printf("%s\n", excuses_list[i]);
            }

            comparison = NULL;
        }

        printf("\n");
        counter++;

        free_list(keywords_list, keywords);
        free_list(excuses_list, excuses);
    } while (fgetc(stdin) != EOF);


    return EXIT_SUCCESS;
}

void free_list(char** list, int size) {
    int i;

    for (i = 0; i < size; i++) {
        free(list[i]);
    }

    free(list);
}