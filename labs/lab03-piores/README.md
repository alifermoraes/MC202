# As piores desculpas
Professores frequentemente ouvem desculpas de alunos que não entregaram seus trabalhos. Algumas são relatos de casualidades cotidianas, outras são apenas esfarrapadas. Escreva um programa para escolher as piores desculpas segundo algumas palavras-chave.

## Entrada
A entrada para o programa consiste de vários conjuntos de dados. A linha 1 de cada conjunto tem dois inteiros. O primeiro (1 ≤ K ≤ 20) define o número de palavras-chave. O segundo (1 ≤ E ≤ 100) define o número de desculpas no conjunto. As linhas 2 a K + 1 têm uma palavra-chave cada. Todas as palavras-chave terão apenas caracteres alfabéticos minúsculos e não terão brancos.

As linhas K + 2 a K + E + 1 têm uma desculpa cada. Cada desculpa poderá conter qualquer caractere alfanumérico maiúsculo ou minúsculo, espaços ou quaisquer dos sinais de pontuação ".,!? e não excederá 100 caracteres de comprimento. Nenhuma desculpa será formada apenas por espaços.

## Saída
Para cada conjunto de entrada, seu programa você deve imprimir as piores desculpas do conjunto. As piores desculpas são aquelas que contêm o maior número de ocorrências de palavras-chave. Uma palavra-chave ocorre em uma desculpa se ela existir na desculpa de forma contígua e se for delimitada pelo início da linha, pelo fim da linha, por um caractere não alfabético ou por um espaço.

Para cada conjunto de entrada, seu programa deve imprimir uma única linha com o número do conjunto imediatamente após a cadeia "Conjunto de desculpas #". As linhas seguintes devem) conter as piores desculpas, uma por linha, exatamente como aparece na entrada. Se houver mais de uma pior desculpa, seu programa deverá imprimi-las na ordem em que aparecem na entrada. Após cada conjunto de saída, seu programa deve imprimir uma linha em branco.


## Exemplo
Para a entrada:  

3 4  
despertador  
gato  
cachorro  
Meu despertador nao tocou e nao consegui chegar para a prova das 14 horas.  
Tive que levar meu gato para tomar banho no pet-shop.  
Meu cachorro comeu o fio do meu notebook. Depois comeu o DESPERTADOR.  
Minha mae nao me acordou a tempo.  
6 5  
gato  
pneu  
comeu  
despertador  
bode  
cachorro  
Meu gato comeu meu mouse.  
Meu bode comeu meu notebook.  
Meu disquete deu erro de leitura.  
O pneu do trem furou.  
O vento estava muito bom e tive que ir soltar pipas.  

A saída é:  

Conjunto de desculpas #1  
Meu cachorro comeu o fio do meu notebook. Depois comeu o DESPERTADOR.  

Conjunto de desculpas #2  
Meu gato comeu meu mouse.  
Meu bode comeu meu notebook.  
O pneu do trem furou.  

e tem uma linha no final.  

### Sugestões:
 - Comece fazendo um programa que apenas lê a entrada e imprime, depois acrescente as demais funcionalidades. 