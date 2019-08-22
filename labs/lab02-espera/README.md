# Atendimento
Uma loja tem uma fila única que distribui clientes entre os funcionários do atendimento. Um funcionário atende apenas um cliente de cada vez. No início do dia, todos os atendentes estão livres e a fila está vazia. Escreva um programa para calcular informações sobre a espera dos clientes pelo atendimento.

## Entrada
A primeira linha contém dois inteiros, C e N, separados por um espaço. C é o número de atendentes da loja e N é o número de clientes que virão naquele dia. C está no intervalo [1,10] e N está no intervalo [1,1000]. Cada uma das N linhas seguintes terão informação sobre um cliente na forma de dois inteiros T e D separados por um espaço. T é o momento, em minutos a partir da abertura da loja, em que o cliente entra na fila e D é o tempo em minutos para atender o cliente. T está no intervalo [0,300] e D está no intervalo [1,10]. As linhas estão ordenadas pelo momento de entrada dos clientes na fila.

## Saída
A primeira linha da saída deve informar a espera média ao longo do dia, como ilustrado no exemplo abaixo. A segunda linha deve informar o número de clientes que esperaram na fila por mais de 10 minutos.

## Exemplo
Para a entrada:  
1 20  
11 2  
40 2  
40 5  
44 9  
59 3  
62 5  
63 8  
63 9  
75 10  
99 8  
103 1  
103 7  
105 8  
110 6  
111 9  
126 8  
238 10  
239 9  
245 1  
249 4  
a saída será:  
Espera media para 20 clientes: 5.4 minutos  
Numero de clientes que esperaram mais que 10 minutos: 5
