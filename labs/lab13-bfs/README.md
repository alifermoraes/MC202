# Busca em largura

Este trabalho consiste em implementar uma busca em largura em um grafo não-orientado G. O grafo deve ser representado por um vetor de adjacências.

## Entrada

A primeira linha da entrada tem n, o número de vértices em G. As linhas seguintes representam arestas {i,j} no formato i,j, tais que 1 <= i,j <= n. O fim das arestas é representado por i=0 e j=0. A última linha é um inteiro v, 1 <= v <= n, que é o vértice inicial da busca em largura.

## Saída

Seu programa deve imprimir os vértices alcançados pela busca em ordem crescente da distância de s. Uma vez que a BFS não impõe qualquer ordem para para percorrer a vizinhança de um vértice, qualquer ordem entre vértices à mesma distância de s será aceita.

Para a entrada:

7  
1,7  
1,2  
4,5  
3,7  
7,2  
0,0  
1

a saída deve ser:

Origem da busca: 1  
Vertices alcancados e distancias:  
1 0  
2 1  
7 1  
3 2

Uma vez que para cada entrada a saída não é necessariamente única, o sqtpm não exibe a saída esperada para os casos-de-teste abertos.