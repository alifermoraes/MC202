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
    int i, j;
    int word_len, counter3, counter4, is_repeated;
    char word[256], substring[5];
    char repeated_substrings[256][5];
    char substrings_pal[256][5];

    while (scanf("%s ", word) != EOF) {
        word_len = strlen(word);
        counter3 = 0;
        counter4 = 0;

        for (i = 0; i < word_len - 3; i++) {
            is_repeated = 0;
            strncpy(substring, (word + i), 4);
            substring[4] = '\0';
            strcpy(repeated_substrings[i], substring);

            for (j = 0; j < i; j++) {
                if (!strcmp(repeated_substrings[j], substring)) {
                    is_repeated = 1;
                }
            }

            if (((substring[0] == substring[3]) && (substring[1] == substring[2])) && !is_repeated) {
                strcpy(substrings_pal[counter4], substring);
                counter4++;
            }
        }

        for (i = 0; i < word_len - 2; i++) {
            is_repeated = 0;
            strncpy(substring, (word + i), 3);
            substring[3] = '\0';
            strcpy(repeated_substrings[i], substring);

            for (j = 0; j < i; j++) {
                if (!strcmp(repeated_substrings[j], substring)) {
                    is_repeated = 1;
                }
            }

            for (j = 0; j < counter4; j++) {
                if (strstr(substrings_pal[j], substring)) {
                    is_repeated = 1;
                }
            }

            if ((substring[0] == substring[2]) && !is_repeated) {
                counter3++;
            }
        }

        if ((counter3 + counter4) >= 2) {
            printf("%s\n", word);
        }
    }

    return EXIT_SUCCESS;
}
