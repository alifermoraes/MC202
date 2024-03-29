/**
 * MC202B - Estrutura de Dados
 *
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 *
 * Trabalho: 11-hashing
 *
 * Hashing de cadeias
 *
 * Este trabalho consiste em implementar uma tabela de hashing para armazenar cadeias do alfabeto
 * {a,b,...,z,A,B,...,Z,_}. No máximo 5.000 cadeias de no máximo 250 caracteres estarão armazenadas
 * na tabela ao mesmo tempo.
 *
 * As colisões devem ser resolvidas usando sondagem com hashing duplo ou encadeamento na própria
 * tabela. Defina o tamanho e a função de hashing para a sua tabela.
 *
 * Escolha também uma função de transformação de cadeias de caracteres em inteiros.
 */

#ifndef _HASHING_H
#define _HASHING_H

#define TABLE_SIZE  4999 /* Número primo mais próximo de 5000. */

#define FINISH  102 /* Caractere f é equivalente à 102 em decimal. */
#define INSERT  105 /* Caractere i é equivalente à 105 em decimal. */
#define SEARCH   98 /* Caractere b é equivalente à 98 em decimal. */
#define DELETE  114 /* Caractere r é equivalente à 114 em decimal. */

typedef struct hash_node {
    char key[251];
    int id;
    struct hash_node *next;
} hash_node;

hash_node **hashing_create_table(void);
void hashing_insert(hash_node **hash_table, char *key, int *id);
int hashing_search(hash_node **hash_table, char *key);
void hashing_delete(hash_node **hash_table, char *key); 
void hashing_destroy(hash_node **hash_table);

#endif /* _HASHING_H */
