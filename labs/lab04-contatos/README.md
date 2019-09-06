# Contatos
Este trabalho consiste em fazer um programa que manipule uma coleção de contatos. Seu programa deve ser capaz de organizar até 1.000 contatos. O programa deve ser capaz de inserir registros, remover registros, recuperar registros e imprimir todos os registros da coleção. A entrada consiste de um caractere que especifica a operação, seguido de linhas de acordo com cada operação, que pode ser:
- i para inserção. As quatro linhas seguintes conterão nome, endereço, telefone e data de aniversário. O nome tem até 50 caracteres, o endereço até 100, o telefone até 12 dígitos e a data de aniversário tem o formato dd/mm/aa.
- r para remoção. A linha seguinte tem uma cadeia de caracteres representando um nome. Seu programa deve remover todos os registros que tenham nome exatamente igual ao digitado. O programa deve imprimir o número de registros removidos.
- b para busca. A linha seguinte tem uma cadeia de caracteres representando um nome. Seu programa deve imprimir todos os registros que tenham nome contendo alguma parte que é igual ao nome digitado, na ordem em que foram inseridos.
- p para impressão. Seu programa deve imprimir todos os registros na agenda, na ordem em que foram inseridos.
- f para finalizar o programa.

## Para a entrada
i  
Fulano  
Rua A, 1 - Centro  
11212134512  
31/11/31  
p  
b  
Fulana  
i  
Fulana  
Rua B, 2 - Centro  
11212134512  
01/01/50  
p  
b  
Fulana  
r  
Fulano  
p  
r  
Fulana  
p  
f

## a saída esperada é
Contato para Fulano inserido.

Listagem:  
(1) Fulano	Rua A, 1 - Centro	11212134512	31/11/31

Resultado da busca:  
Nenhum contato.

Contato para Fulana inserido.

Listagem:  
(1) Fulano	Rua A, 1 - Centro	11212134512	31/11/31  
(2) Fulana	Rua B, 2 - Centro	11212134512	01/01/50

Resultado da busca:  
(2) Fulana	Rua B, 2 - Centro	11212134512	01/01/50

Contatos de Fulano removidos: 1.

Listagem:  
(1) Fulana	Rua B, 2 - Centro	11212134512	01/01/50

Contatos de Fulana removidos: 1.

Listagem:  
Nenhum contato.

e tem uma linha no final.

### Requisitos adicionais  
- Seu programa deve usar struct para armazenar os contatos.
- Cada funcionalidade (inserir, buscar, remover, imprimir) deve ser implementada por uma função distinta.
- Não deve haver variáveis globais.