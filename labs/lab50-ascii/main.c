/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 50-ascii
 * 
 * Tabela ASCII
 *
 * A tabela ASCII é uma das formas possíveis de mapear inteiros em símbolos.
 * São 128 códigos, de 0 a 127, sendo que os primeiros 32 e o último são
 * considerados símbolos de controle e os demais são imprimíveis.
 *
 * Escreva um programa em C para imprimir uma tabela ASCII como a do modelo
 * abaixo. No exemplo algumas linhas foram suprimidas e estão representadas por
 * três  pontos. O programa não recebe nenhuma entrada.
*/

#include <stdio.h>

int main(void) {
    int i, j;
    char c = 32;

    printf("      +0 +1 +2 +3 +4 +5 +6 +7 \n");
    printf("    +------------------------ \n");

    printf("%3d | ", c);
    for (i = 1; i < 9; i++) {
        printf("%2c ", c++);
    }

    printf("\n");

    for (j = 0; j < 10; j++) {
        printf("%3d | ", c);

        for (i = 0; i < 8; i++) {
            printf("%2c ", c++);
        }

        printf("\n");
    }
    
    printf("%3d | ", c);

    for (i = 0; i < 7; i++) {
        printf("%2c ", c);
        c++;
    }

    printf("   \n");

    return 0;
}

