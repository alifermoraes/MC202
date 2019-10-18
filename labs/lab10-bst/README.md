# Árvore de busca binária parte 2

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

- remover x

Ao ler o comando remover x, onde x é um inteiro, o programa deve remover a chave x da árvore binária de busca se houver. O programa deve usar sempre o *sucessor* de um nó para a substituição de um nó que tenha dois filhos.

- minimo
- maximo

Ao ler um desses comandos o programa deve imprimir a menor chave ou a maior chave na árvore, respectivamente. Se a árvore estiver vazia então o programa deve imprimir "vazia" em uma linha.

- sucessor x
- predecessor x

Ao ler um desses comandos, onde x é um inteiro, o programa deve imprimir o sucessor de x ou o precessor de x, respectivamente. Se x não estiver na árvore ou não tiver sucessor ou predecessor o programa deve imprimir "nao ha" em uma linha.

- buscar-intervalo x y

Ao ler o comando buscar-intervalo x y, onde x e y são inteiros, o programa deve imprimir todas as chaves contidas intervalo [x,y] em ordem crescente, separadas por espaço e em uma linha. Se não houver chaves no intervalo o programa deve imprimir "nenhuma" em uma linha.

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
predecessor 1381  
sucessor 6122  
remover 4410  
em-ordem  
buscar-intervalo 1500 5031  
terminar

Saída:

nao ha  
7613  
1381 2553 3937 5031 5897 6122 7613 8924 9452   
2553 3937 5031 

### Requisitos adicionais

- Os tipos e funções da árvore devem ser definidos em um arquivo .h e implementados em um arquivo .c e o programa principal deve ser um outro arquivo .c.
- Cada operação deve ser implementada por uma função.
