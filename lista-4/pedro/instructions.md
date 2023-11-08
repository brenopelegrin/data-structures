# Lista 4

Disciplina: Estrutura de Dados (2º Semestre de 2023)

Esse projeto implementa uma lista duplamente encadeada de strings (arrays de caracteres).

Alunos:
    - Breno Henrique Pelegrin da Silva (13687303)
    - Pedro Martins Oliveira (13696213)

Os códigos foram compilados e testados utilizando GCC GNU C/C++ Compiler rodando em um kernel linux.

# Instruções de Compilação

A compilação do programa é feita através de um Makefile, portanto é necessário que o usuário possua `make` e `GCC` instalados em sua máquina.

Para realizar a compilação basta executar o comando abaixo dentro do diretório do programa:

```bash
make clean && make
```

Após isso serão gerados os arquivos compilados em `./build/`

Para rodar o programa basta executar:

```bash
./build/main.out
```

Caso o usuário esteja em uma máquina Windows ele tera que compilar e executar o programa manualmente se baseando no Makefile.

# Exemplos de Uso

Ao executar o programa será impresso no terminal uma guia com as operações possíveis de serem realizadas na lista:

```bash
1 - Inserir nome por índice
2 - Inserir nome ordenadamente (ordem alfabética)
3 - Verificar se nome existe
4 - Remover nome
5 - Ordenar lista
6 - Verificar se a lista está ordenada
7 - Imprimir Elementos
8 - Imprimir Elementos na ordem invertida
9 - Imprimir o tamanho da lista
0 - Sair
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 
```

Então o programa irá pedir que o usuário insira o número correspondente à operação que ele deseja fazer, para inserir um nome por índice por exemplo basta digitar o número 1.

O programa pode realizar quantas operações o usuário desejar, para terminar a execução basta realizar a operação de saída (correspondente ao 0).

Segue agora uma breve descrição do uso de cada uma das operações.

### Inserir nome por índice

Essa operação insere um nome na lista na posição definida pelo usuário.

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 1

Digite o nome que deseja inserir:
```

Ao digitar o nome o usuário deve inserir a posição em que ela será inserido.

```bash
Digite o nome que deseja inserir:
Pedro 

Digite a posição em que deseja inserir: 
```

A contagem das posições começa no valor 0, portanto:
- 0 insere o elemento na primeira posição da lista.
- Qualquer número entre 0 e o tamanho da lista insere o elemento na posição correspondente.
- Qualquer número maior do que o tamanho da lista insere o elemento na última posição da lista.
- -1 insere o elemento na última posição da lista.
- Qualquer número menor que -1 é tido como uma posição inválida, o programa irá requisitar que o número seja inserido novamente.

### Inserir nome ordenadamente

Essa operação insere o nome em ordem alfabética na lista.

Ao iniciar a operação, novamente é requisitado que o usuário insira o nome que deseja colocar na lista:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
Pedro 
```

Caso não ocorra nenhum problema será exibida uma mensagem de sucesso:

```bash
Operação realizada com sucesso
```

Porém, é possível que a lista não esteja previamente ordenada (isso ocorre caso o usuário já tenha inserido nomes fore de ordem usando a inserção por índice) então o programa irá alertar o usuário e perguntar se ele deseja ordenar a lista para inserir o nome:

```bash
Parece que a lista não está ordenada, logo não é possível inserir algo ordenadamente nela
Deseja ordenar a lista e então inserir o nome? [S,N]
```

Ao digitar `S` a lista é ordenada e o nome é inserido.

```bash
Deseja ordenar a lista e então inserir o nome? [S,N]
S
Operação realizada com sucesso
```

Ao digitar `N` a operação é finalizada:

```bash
Deseja ordenar a lista e então inserir o nome? [S,N]
N
Encerrando operacação
```

Se for digitado qualquer outro elemento além de `N` e `S` a operação também é finalizada.

### Verificar se nome existe

O usuário insere um nome e o programa verifica se esse nome já está presenta na lista:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 1

Digite o nome que deseja inserir:
Pedro  

Digite a posição em que deseja inserir: 0
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 3

Digite o nome que deseja verificar se está na lista:
Pedro
O nome está na lista
```

Caso o nome não esteja na lista o programa exibe uma mensagem

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 3

Digite o nome que deseja verificar se está na lista:
Breno
O nome não está na lista
```

### Remover nome

O usuário insere um nome e se ele existir na lista o programa o remove da mesma:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 4

Insira o nome que deseja remover:
Pedro
Operação realizada com sucesso
```

Caso o nome não esteja na lista o programa exibe um aviso:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 4

Insira o nome que deseja remover:
Breno 
O nome não existe na lista, portanto não é possível retira-lo
```

### Ordenar lista

Ordena os elementos da lista em ordem alfabética, maiúsculas e minúsculas possuem o mesmo valor nessa ordenação, portanto não é necessário se preocupar com elas.

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 7

pedRo
StevE
BrEnO

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 5

Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 7

BrEnO
pedRo
StevE
```

Caso a lista esteja vazia o programa exibe uma mensagem:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 5

A lista está vazia, não existe nada para ordenar
```

### Verificar se a lista está ordenada

A operação em questão exibe uma mensagem indicando se a lista está ou não ordenada

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 7

Pedro
Breno

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 6

A lista não está ordenada
```

Ou para o caso de uma lista ordenada:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 6

A lista está ordenada
```

Existe ainda a possibilidade de a lista estar vazia, nesse caso como não é possível averiguar ordenação o programa retorna uma mensagem:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 6 

A lista está vazia, não é possível ver se ela está ordenada
```

### Imprimir elementos

A operação de imprimir elementos mostra todos os elementos presentes na lista:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
BRENO
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
PEDRO
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 7

BRENO
PEDRO
```

Caso a lista não possua nenhum elemento a operação mostra uma mensagem:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 7

Não existe nada para imprimir!
```

### Imprimir elementos em ordem invertida

Assim como a anterior, essa operação também imprime os elementos da lista, porém em ordem invertida.

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
Breno 
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
Pedro
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 8

Pedro
Breno
```

Repare como no exemplo acima os elementos foram colocados ao contrário na ordem alfabética, pois foram inseridos ordenadamente.

Essa operação é muito facilitada devido à implementação de uma lista duplamente encadeada, onde temos a informação do nó anterior a um nó qualquer.

Novamente, para o caso da lista vazia o programa exibe uma mensagem:

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 8

Não existe nada para imprimir!
```

### Imprimir o tamanho da lista

Essa operação apenas imprime a quantidade de elementos na lista.

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
Pedro
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 2

Digite o nome que deseja inserir:
Breno
Operação realizada com sucesso

Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 9

A lista possui 2 elemento(s)
```

### Imprimir o guia de operações novamente

Para simplificar o uso do programa, o usuário pode inserir o valor `-1` no pedido da operação para imprimir novamente a guia de operações.

### Sair do Programa

Para sair do programa basta executar a operação correspondente ao número 0

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 0

Obrigado por utilizar nossos serviços!
```

Não se preocupe, o programa limpa a memória utilizada antes de sair.

### Operações Inválidas

Se for inserido qualquer número que não esteja associado a nenhuma operação o programa exibe uma mensagem de erro e pede que o usuário digite a operação desejada novamente.

```bash
Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): 20

Parece que você inseriu um número inválido, tente novamente!
```

# Alguns Detalhes

O programa manipula os nomes como uma cadeia de caracteres, para poupar memória é alocado um espaço de 30 caracteres para os nomes (sendo esse um espaço suficiente para a maior parte dos nomes).

Porém, caso o usuário precise aumentar esse tamanho ele deve ir ao arquivo `/tad-double_list/double_list.h` e alterar o valor de `MAX_SIZE_NAME`.

```C
#define MAX_SIZE_NAME <insira o tamanho desejado aqui!>
```

Porém cuidado! Colocar valores muito grandes faz com que o programa precise de muita memória, enquanto que valores muito pequenos fazem com que os nomes excedam o limite.