Os códigos foram compilados e testados utilizando GCC GNU C/C++ Compiler rodando em um kernel linux.

## Instruções de Compilação

A compilação do programa é feita através de um Makefile, portanto é necessário que o usuário possua `make` e `GCC` instalados em sua máquina.

Para realizar a compilação basta executar o comando abaixo dentro do diretório do programa:

```bash
make clean && make
```

Após isso serão gerados os arquivos de compilados, para rodar o programa basta executar:

```bash
./build/main.o
```

Caso o usuário esteja em uma máquina Windows ele tera que compilar e executar o programa manualmente se baseando no Makefile.

## Exemplo de Uso

Ao executar o programa será disposto uma guia com as operações possíveis:

```
Manipulador de Fila de inteiros®
------------------------
1 - Inserir elemento no final
2 - Inserir multiplos elementos no final
3 - Deletar elemento no topo
4 - Obter elemento no topo (pop)
5 - Imprimir tamanho atual da fila
6 - Verificar se fila está vazia
7 - Verificar se elemento existe na fila
8 - Imprimir elemento em determinado índice
9 - Imprimir fila do primeiro ao último elemento
10- Inverter fila
11- Esvaziar fila
0 - Sair
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
```

Então o usuário deve inserir o número associado à operação que ele deseja realizar. O usuário pode realizar quantas operações desejar.

### Inserir Elemento

O usuário pode inserir elementos na fila utilizando a operação `1` ou `2`.

Na operação `1` ele deverá inserir um valor que será colocado no fim da fila:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
1

Insira o valor que será colocado na fila:
10

Número inserido com sucesso!
```

Além disso, também é possível inserir múltiplos números de uma só vez, isso é feito usando a operação `2`, o usuário deve dizer quantos números ele deseja inserir e então escreve-los:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 4
1 2 3 4

Números inseridos com sucesso!
```

Os números também podem ser inseridos de outras formas, porém eles serão colocados na fila na ordem que forem inseridos:

```
Quantos números você deseja inserir? 4
1
2
3
4

Números inseridos com sucesso!
```

### Retirar Elemento

O usuário pode retirar um elemento da lista usando as operações `3` e `4`

A operação `3` apenas retira o primeiro elemento da lista:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
3

Elemento retirado com sucesso!
```

A operação `4` realiza algo muito semelhante, porém ela também mostra qual foi o elemento que foi retirado:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
1

Insira o valor que será colocado na fila:
10

Número inserido com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
4

Elemento capturado com sucesso, seu valor é 10
```

Ambas as operações retornam uma mensagem caso o usuário tente retirar um elemento de uma fila vazia.

### Imprimir Tamanho da fila

A operação `5` imprime a quantidade de elementos na fila:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 8
0 0 0 0 0 0 0 0

Números inseridos com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
5

O tamanho da fila é: 8
```

### Verificar se a fila está vazia

A operação `6` imprime uma mensagem indicando se a fila está ou não vazia

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
6

A fila está vazia
```

Ou caso ela não esteja vazia:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
6   

A fila não está vazia
```

### Verificar se elemento existe na fila

A operação `7` verifica se um determinado inteiro existe em qualquer posição da fila:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 6
0 0 10 0 0 0

Números inseridos com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
7

Insira o elemento que você deseja descobrir se está na fila: 10

O elemento 10 está na fila
```

Ou caso o elemento não esteja na fila:

```
Insira o elemento que você deseja descobrir se está na fila: 100

O elemento 100 não está na fila
```

### Imprimir elemento em determinado índice

A operação `8` imprime para o usuário o inteiro armazenado em algum índice contanto a partir do 0 (portanto o primeiro elemento seria o 0, o segundo 1 e assim por diante):

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 3
10 20 30

Números inseridos com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
8

Insira uma posição para encontrar o elemento: 0

O elemento na posição 0 é 10

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
8

Insira uma posição para encontrar o elemento: 2

O elemento na posição 2 é 30
```

E também caso o tamanho inserido seja maior do que a fila:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
8

Insira uma posição para encontrar o elemento: 10

A fila não possui nenhum elemento na posição 10
```

Além disso o programa imprime uma mensagem caso o usuário insira um tamanho negativo:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
8

Insira uma posição para encontrar o elemento: -1

Não existem elementos em posição negativa
```

### Imprimir fila

A operação `9` imprime todos os elementos presentes na fila de cima para baixo:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 5
10 20 30 40 50 

Números inseridos com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
9

Fila:
10
20
30
40
50
```

Além disso ela também exibe uma mensagem caso a fila esteja vazia:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
9

Fila vazia!
```

### Inverter fila

A operação `10` inverte todos os elementos da fila:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
2

Quantos números você deseja inserir? 3
1 2 3

Números inseridos com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
10

Fila invertida com sucesso!

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
9

Fila:
3
2
1
```

### Esvaziar fila

A operação `11` elimina todos os elementos da fila, deixando ela vazia:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
11

Fila limpa

Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
6

A fila está vazia
```

Atenção: essa operação não libera a memória utilizada pela fila, isso é feito antes do término da execução do programa.

### Outras operações

Além das operações já citadas, o usuário pode inserir a operação `-1` para imprimir novamente a lista de operações possíveis.

Para terminar a execução do programa o usuário deve realizar a operação `0`, que libera toda a memória utilizada pelo programa e termina sua execução:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
0

Obrigado por utilizar nossos serviços!
```

Qualquer outra número que não esteja associado à uma operação válida recebe uma mensagem de erro:

```
Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)
73

Parece que você inseriu um número inválido.
```