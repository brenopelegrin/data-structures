Todos os códigos foram compilados e testados utilizando o GCC GNU C/C++
Compiler, rodando em um kernel Linux 5.19 do Ubuntu 22.04 LTS:

```
base ❯ uname -a
Linux breno-lenovo 5.19.0-41-generic #42~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Tue Apr 18 17:40:00 UTC 2 x86_64 x86_64 x86_64 GNU/Linux
```

As informações e instruções dos exercícios estão expostas abaixo.

## Exercício 1

### Instruções de compilação e como rodar
Para compilar, primeiramente entre no diretório do ex1:
```bash
cd ex1
```
Em seguida, se estiver em um SO baseado em UNIX e tiver o ``make`` e ``GCC`` instalados:
```bash
make clean && make
```
Após isso, serão gerados os arquivos compilados para o main e o tad-complex no diretório build.
Para rodar, faça:
```
./build/main.o
```
Se estiver no Windows, compile e rode manualmente manualmente, baseando-se no script do Makefile.

### Exemplos de teste

Exemplo 1:
z1 = 1.034 - 0.456 i
z2 = 0.003 + 1.904 i

Nesse exemplo, todas as operações deveriam funcionar sem erro.

Output do terminal: 

```
~/usp/data-struct/lista-2/ex1 main*
base ❯ ./build/main.o
--- Número complexo n1 ---
Digite a parte real: 1.034
Digite a parte imaginária: -0.456

--- Número complexo n2 ---
Digite a parte real: 0.003
Digite a parte imaginária: 1.904


--- Calculadora de complexos ---
1 - Adição (n1 + n2)
2 - Subtração (n1 - n2)
3 - Multiplicação (n1 * n2)
4 - Divisão (n1 / n2)
5 - Conjugação de n1
6 - Conjugação de n2
7 - Multiplicação de n1 por escalar
8 - Multiplicação de n2 por escalar
0 - Sair

> Digite a operação que você deseja realizar: 1
Resultado: 1.0370 + 1.4480 i

> Digite a operação que você deseja realizar: 2
Resultado: 1.0310 + -2.3600 i

> Digite a operação que você deseja realizar: 3
Resultado: 0.8713 + 1.9674 i

> Digite a operação que você deseja realizar: 4
Resultado: -0.2386 + -0.5434 i

> Digite a operação que você deseja realizar: 5
Resultado: 1.0340 + 0.4560 i

> Digite a operação que você deseja realizar: 6
Resultado: 0.0030 + -1.9040 i

> Digite a operação que você deseja realizar: 7
Digite o escalar: 1.5
Resultado: 1.5510 + -0.6840 i

> Digite a operação que você deseja realizar: 8
Digite o escalar: 0.7
Resultado: 0.0021 + 1.3328 i

> Digite a operação que você deseja realizar: 0
Saindo...
```

Exemplo 2:
z1 = 1.0 + 4.0 i
z2 = 0.0 + 0.0 i

Nesse exemplo, todas as operações exceto divisão devem funcionar, já que é impossível dividir por zero.

Output do terminal:

~/usp/data-struct/lista-2/ex1 main* ⇣
base ❯ ./build/main.o
--- Número complexo n1 ---
Digite a parte real: 1.0
Digite a parte imaginária: 4.0

--- Número complexo n2 ---
Digite a parte real: 0.0
Digite a parte imaginária: 0.0


--- Calculadora de complexos ---
1 - Adição (n1 + n2)
2 - Subtração (n1 - n2)
3 - Multiplicação (n1 * n2)
4 - Divisão (n1 / n2)
5 - Conjugação de n1
6 - Conjugação de n2
7 - Multiplicação de n1 por escalar
8 - Multiplicação de n2 por escalar
0 - Sair

> Digite a operação que você deseja realizar: 1
Resultado: 1.0000 + 4.0000 i

> Digite a operação que você deseja realizar: 2
Resultado: 1.0000 + 4.0000 i

> Digite a operação que você deseja realizar: 3
Resultado: 0.0000 + 0.0000 i

> Digite a operação que você deseja realizar: 4
Erro: divisão por zero.

> Digite a operação que você deseja realizar: 5
Resultado: 1.0000 + -4.0000 i

> Digite a operação que você deseja realizar: 6
Resultado: 0.0000 + -0.0000 i

> Digite a operação que você deseja realizar: 7
Digite o escalar: 5.3
Resultado: 5.3000 + 21.2000 i

> Digite a operação que você deseja realizar: 8
Digite o escalar: 0.45
Resultado: 0.0000 + 0.0000 i

> Digite a operação que você deseja realizar: 0
Saindo...