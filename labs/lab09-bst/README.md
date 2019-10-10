# Árvore de busca binária

Este trabalho consiste em escrever um programa com funções para manipular uma árvore de busca binária para inteiros.

## Entrada

O programa deve criar uma árvore vazia e em seguida deve processá-la de acordo com comandos da entrada-padrão, que podem ser da seguinte forma:

- inserir x

Ao ler o comando inserir x, onde x é um inteiro, o programa deve inserir a chave x na árvore de busca binária. A árvore não deve ter elementos repetidos, então se x já pertence à árvore ele não deve ser inserido de novo.

- buscar x

Ao ler o comando buscar x, onde x é um inteiro, o programa deve buscar a chave x na árvore e imprimir "x pertence" ou "x nao pertence" em uma linha.

- pos-ordem
- em-ordem
- pre-ordem
- largura

Ao ler um desses comandos o programa deve imprimir as chaves na ordem em que forem visitadas por um percurso em profundidade em pós-ordem, em-ordem, em pré-ordem ou por um percurso em largura. As chaves devem ser impressas seguidas por um espaço, em uma única linha. Se a árvore estiver vazia então o programa deve imprimir "vazia" em uma linha.

- terminar

Ao ler esse comando o programa deve desalocar a árvore e terminar. 

## Saída

Exemplo

Entrada:

inserir 6122  
inserir 3937  
inserir 8924  
inserir 2553  
inserir 5031  
inserir 5897  
inserir 7613  
inserir 9452  
inserir 1381  
inserir 4410  
em-ordem  
pre-ordem  
pos-ordem  
largura  
buscar 51  
buscar 4410  
buscar 6122  
terminar

Saída:

1381 2553 3937 4410 5031 5897 6122 7613 8924 9452  
6122 3937 2553 1381 5031 4410 5897 8924 7613 9452  
1381 2553 4410 5897 5031 3937 7613 9452 8924 6122  
6122 3937 8924 2553 5031 7613 9452 1381 4410 5897  
51 nao pertence  
4410 pertence  
6122 pertence

### Requisitos adicionais

- Os tipos e funções da árvore devem ser definidos em um arquivo .h e implementados em um arquivo .c e o programa principal deve ser um outro arquivo .c.
- Cada operação deve ser implementada por uma função.
