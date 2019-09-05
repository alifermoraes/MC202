/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 52-2palindrome
 * 
 * Um palíndrome é uma cadeia de caracteres que pode ser lida para frente e
 * para trás e ainda resultar na mesma palavra, por exemplo ababababa. Assim,
 * por definição, a cadeia vazia, todas as cadeias que contém 1 caractere e
 * todas as cadeias que contém 2 caracteres iguais são palíndromes. O
 * comprimento de um palíndrome é o número de caracteres no palíndrome.
 * Um 2-palíndrome é uma cadeia de caracteres que tenha pelo menos 2
 * palíndromes diferentes como subcadeia, cada um com comprimento maior ou
 * igual a 3 e que não sejam um contido no outro. Por exemplo, o palíndrome
 * AAAA está contido no palíndrome AAAAA. Se o mesmo palíndrome ocorre em
 * posições distintas eles não são considerados diferentes. Palíndromes em um
 * 2-palíndrome podem se sobrepor parcialmente. Por exemplo, a cadeia ABASA é
 * um 2-palindrome e a cadeia BAAAB não é.
 * 
 * Seu programa deve copiar somente os 2-palíndromes da entrada para a saída. A
 * entrada para seu programa é uma seqüência de linhas. Cada linha está vazia
 * ou contém uma ou mais palavras separada por um ou mais espaços e somente com
 * letras maiúsculas e sem acentos. Cada linha na entrada contém no máximo 255
 * caracteres. A saída deve conter um 2-palíndrome por a linha na ordem de
 * ocorrência na entrada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i, j, word_len, counter, is_repeated;
    char word_forwards[256], word_backwards[256], substring[4];
    char *comparison;
    char **substrings_vector;

    while (scanf("%s ", word_forwards) != EOF) {
        word_len = strlen(word_forwards);
        counter = 0;

        /* Inverte a palavra lida e armazena em word_backwards */
        for (i = 0; i < word_len; i++) {
            word_backwards[i] = word_forwards[word_len - 1 - i]; 
        } word_backwards[i] = '\0';

        substrings_vector = malloc((word_len - 2) * sizeof(char*));

        for (i = 0; i < word_len - 2; i++) {
            is_repeated = 0;
            strncpy(substring, (word_forwards + i), 3);
            substring[3] = '\0';
            substrings_vector[i] = malloc(sizeof(char[4]));
            strcpy(substrings_vector[i], substring);
            comparison = strstr(word_backwards, substring);

            for (j = 0; j < i; j++) {
                if (!(strcmp(substrings_vector[j], substring))) {
                    is_repeated = 1;
                }
            }
            

            if (comparison && !is_repeated) {
                counter++;
            }
        }

        if (counter >= 2) {
            printf("%s\n", word_forwards);
        }

        for (i = 0; i < word_len - 2; i++) {
            free(substrings_vector[i]);
        }

        free(substrings_vector);
    }

    return EXIT_SUCCESS;
}
