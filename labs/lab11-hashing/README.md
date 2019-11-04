# Hashing de cadeias

Este trabalho consiste em implementar uma tabela de hashing para armazenar cadeias do alfabeto {a,b,...,z,A,B,...,Z,_}. No máximo 5.000 cadeias de no máximo 250 caracteres estarão armazenadas na tabela ao mesmo tempo.

As colisões devem ser resolvidas usando sondagem com hashing duplo ou encadeamento na própria tabela. Defina o tamanho e a função de hashing para a sua tabela.

Escolha também uma função de transformação de cadeias de caracteres em inteiros. Não importa a forma como você faça para este trabalho, mas algumas funções são muito piores que outras em termos de espalhamento. Um exemplo de uma função que funciona bem é a função de hashing djb2 abaixo:

unsigned long djb2(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; // hash * 32 + hash + c
  
  return hash;
}

## Entrada

 Cada linha da entrada para seu programa é iniciada por um caractere que pode ser seguido de um espaço e de uma chave. Os caracteres podem ser i para inserir uma chave na tabela, b para buscar uma cadeia na tabela, r para remover uma cadeia da tabela e f para terminar o programa.

Quando uma cadeia é inserida na tabela ela recebe um identificador único. O identificador de cada cadeia é atribuído seqüencialmente a partir de 0, sem reuso. Cada chave deve ser inserida uma única vez.

Para cada busca pela cadeia c na tabela seu programa deve imprimir "c encontrada, id i" ou "nao encontrada" em uma linha, onde i é o identificador que c recebeu no momento em que foi inserida. As outras ações não geram saída.

## Saída

 Para a entrada

i itdoesntmatter  
i thewaythatyoutakeit  
i itdoesntmatter  
i thewaythatyoumakeit  
b itdoesntmatteR  
b itdoesntmatter  
b thewaythatyoumakeit  
r thewaythatyoumakeit  
b thewaythatyoumakeit  
f

o programa deve produzir como saída:

itdoesntmatteR nao encontrada  
itdoesntmatter encontrada, id 0  
thewaythatyoumakeit encontrada, id 2  
thewaythatyoumakeit nao encontrada
