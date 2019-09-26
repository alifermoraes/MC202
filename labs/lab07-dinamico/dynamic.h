/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 07-dinamico
 *
 * Vetor dinâmico
 * Vamos dizer que um conjunto de registros está em sequência se a ordem relativa entre eles é
 * importante. Por exemplo, pessoas em uma fila de atendimento formam uma sequência.
 * 
 * Neste trabalho você deve implementar um vetor dinâmico para armazenar uma sequência de números
 * inteiros. O vetor dinâmico deve permitir inserção no início e no final da sequência, remoção do
 * primeiro e do último elementos e recuperação do primeiro e do último elementos.
 * 
 * A sequência deve ser implementada de forma circular, isto é, o primeiro elemento dela deve poder
 * estar em qualquer posição do vetor. Dessa forma, qualquer uma dessas operações acima poderá ser
 * realizada em tempo constante, não é necessário fazer deslocamento dos dados armazenados no vetor
 * para a esquerda ou para a direita.
 * 
 * Por exemplo, a sequência circular de chaves inteiras [2,9,5,7] pode estar armazenada de várias
 * formas em um vetor de tamanho 8:
 * 
 * 2 9 5 7 _ _ _ _  
 * _ _ 2 9 5 7 _ _  
 * _ _ _ _ 2 9 5 7  
 * 5 7 _ _ _ _ 2 9  
 * 9 5 7 _ _ _ _ 2 
 * 
 * Em todas elas, o primeiro elemento da sequência é o 2 e o último é o 7. Observe que os números
 * não estão ordenados, mas a ordem relativa entre eles deve ser preservada.
 * 
 * A política de redimensionamento do vetor deve ser dobrar quando estiver cheio e reduzir à metade
 * quando estiver 1/4 ocupado. Dessa forma, durante o processamento, o número de posições vazias do
 * vetor não deveria exceder 3n, onde n é o número de posições ocupadas.
 * 
 * Obviamente, quando o vetor for redimensionado, o conteúdo da seqüência e a ordem relativa entre
 * os elementos da seqüência devem ser preservados. 
 */

#ifndef _DYNAMIC_H
#define _DYNAMIC_H

#define INSERT_FIRST    1
#define REMOVE_FIRST    2
#define PRINT_FIRST     3
#define INSERT_LAST     4
#define REMOVE_LAST     5
#define PRINT_LAST      6
#define IS_EMPTY        7
#define EXIT            0
#define INC             1
#define DEC             0

typedef struct array {
    int *data;
    int head;
    int size;
    int max_size;
} Array;

Array dynamic_create(void);
void dynamic_inject(Array *array, int data);
void dynamic_eject(Array *array);
void dynamic_print_head(Array array);
void dynamic_push(Array *array, int data);
void dynamic_pop(Array *array);
void dynamic_print_tail(Array array);
void dynamic_is_empty(Array array);
char dynamic_decoder(char *instruction);
int dynamic_resize(Array *array, int inc_dec);

#endif /* _DYNAMIC_H */
