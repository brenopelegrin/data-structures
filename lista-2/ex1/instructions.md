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
cd ./build && ./main.o
```
Se estiver no Windows, compile e rode manualmente manualmente, baseando-se no script do Makefile.