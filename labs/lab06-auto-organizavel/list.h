/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 06-auto-organizavel
 *
 * Lista auto-organizável
 *
 * Em uma lista não há uma forma simples que facilite a recuperação dos registros armazenados nos
 * nós: para recuperar o nó na posição i de uma lista é preciso percorrê-la a partir da cabeça,
 * fazendo i acessos a nós.
 *
 * Em muitas aplicações, as freqüências com que os registros são recuperados não são uniformes. Faz
 * sentido que os registros que são recuperados com maior freqüência sejam colocados mais próximos
 * da cabeça, mas tipicamente tais freqüências não são conhecidas e mudam ao longo do tempo.
 *
 * Estratégias de permutação podem ser aplicadas para reduzir o número de acessos a nós da lista
 * durante a recuperação de registros em uma lista. Tais estratégias movem o registro que acabou de
 * ser recuperado um certo número de posições em direção ao início da lista, sem modificar a ordem
 * relativa dos demais registros. Listas acompanhadas de alguma estratégia desse tipo foram
 * chamadas de listas auto-organizáveis.
 * 
 * Algumas estratégias de permutação foram propostas na literatura. As mais usadas incluem:
 * - Move-to-front (MTF): quando um registro é recuperado ele é movido para o início da lista, se
 * ele ainda não estiver no início da lista.
 * - Transpose (TR): quando um registro é recuperado ele é trocado de posição com o registro que o
 * precede, se ele ainda não estiver no início da lista.
 * - Count (C): cada registro tem um contador do número de acessos. Quando um registro é recuperado
 * o contador é incrementado e ele é movido para uma posição anterior a todos os registros com
 * contador menor ou igual ao dele. 
 */

#ifndef _LIST_H_
#define _LIST_H_

#define MTF 0
#define TR  1
#define C   2

typedef struct node {
    int key;
    int counter;
    struct node *next;
} Node;

typedef Node * node_ptr;

node_ptr list_create(int size);
void list_destroy(node_ptr list);
int list_move_to_front(node_ptr *list, int key);
int list_transpose(node_ptr *list, int key);
int list_count(node_ptr *list, int key);

#endif /* define _LIST_H_ */
