Instruções de uso para o exercício 2 da lista 2

# Compilação e Execução do programa
Para compilar o programa utilize o comando

gcc main.c matrix.c -o a.out

Após isso, execute o arquivo a.out com o comando

./a.out

# Como usar
Ao executar o programa uma mensagem irá solicitar qual a operação a ser feita, com cada uma delas associada à um número.
Para realizar por exemplo, a operação de (A*B)^n basta digitar o número 5.

Feito isso o programa irá executar as instruções específicas de cada operação, segue um exemplo de execução para cada uma das operações

## Soma de Matrizes
Operação:
1

Tamanho das matrizes:
3 3

Primeira matriz:
1 2 3
3 2 1
0 1.2 100

Segunda matriz:
0.42 2 10
1000 0 -4
9 -0.2 1

Resultado:
1.420000 4.000000 13.000000 
1003.000000 2.000000 -3.000000 
9.000000 1.000000 101.000000 

## Subtração de Matrizes
Operação:
2

Tamanho das matrizes:
3 3

Primeira matriz:
1 2 3
3 2 1
0 1.2 100

Segunda matriz:
0.42 2 10
1000 0 -4
9 -0.2 1

Resultado: 
0.580000 0.000000 -7.000000 
-997.000000 2.000000 5.000000 
-9.000000 1.400000 99.000000 

## Multiplicação de Matriz por escalar
Operação 3

Tamanho da matriz:
2 4

Matriz:
0 -9 2 1.5
-0.28 10 2023 1

Escalar:
0.5

Resultado:
0.000000 -4.500000 1.000000 0.750000 
-0.140000 5.000000 1011.500000 0.500000 

## Multiplicação de Matrizes
Operação: 
4

Tamanho da primeira matriz:
3 2

Tamanho da segunda matriz:
2 3

Primeira matriz:
1 2
0 -1
-0.5 10.1

Segunda matriz:
0 1 -1 
2.25 0 3

Resultado:
4.500000 1.000000 5.000000 
-2.250000 0.000000 -3.000000 
22.725000 -0.500000 30.800001 

## Potência de produto de matrizes
Operação:
5

Tamanho da primeira matriz:
2 3

Tamanho da segunda matriz:
3 2

Primeira matriz:
1 2 10.1
73 0 0

Segunda matriz:
1 -1 
1 1.1
0.1 -11

Potência:
3

Resultado:
521379.562500 326441.562500 
-216835.593750 750126.250000 