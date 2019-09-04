# 2-palíndrome
Um palíndrome é uma cadeia de caracteres que pode ser lida para frente e para trás e ainda resultar na mesma palavra, por exemplo ababababa. Assim, por definição, a cadeia vazia, todas as cadeias que contém 1 caractere e todas as cadeias que contém 2 caracteres iguais são palíndromes. O comprimento de um palíndrome é o número de caracteres no palíndrome.
Um 2-palíndrome é uma cadeia de caracteres que tenha pelo menos 2 palíndromes diferentes como subcadeia, cada um com comprimento maior ou igual a 3 e que não sejam um contido no outro. Por exemplo, o palíndrome AAAA está contido no palíndrome AAAAA. Se o mesmo palíndrome ocorre em posições distintas eles não são considerados diferentes. Palíndromes em um 2-palíndrome podem se sobrepor parcialmente. Por exemplo, a cadeia ABASA é um 2-palindrome e a cadeia BAAAB não é.

Seu programa deve copiar somente os 2-palíndromes da entrada para a saída. A entrada para seu programa é uma seqüência de linhas. Cada linha está vazia ou contém uma ou mais palavras separada por um ou mais espaços e somente com letras maiúsculas e sem acentos. Cada linha na entrada contém no máximo 255 caracteres. A saída deve conter um 2-palíndrome por a linha na ordem de ocorrência na entrada.

## Para a entrada
MOEILIJKHEDEN INVOER  
VERNEDEREN  
AMUMA AMAMA MUMMUM  
AMATRAMA AAAA  
ABATRABAR  
DUMMY  
WORDS  

## A saída é
MOEILIJKHEDEN  
VERNEDEREN  
AMAMA  
MUMMUM  
