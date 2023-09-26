CC = gcc
CFLAGS = -Wall

target = matrix

default: main

main: tadmatrix
	@echo "--- Compilando main ---"
	$(CC) $(CFLAGS) -I./tad-matrix/ -o ./build/main.o ./main.c ./build/tad-matrix.o -lm
	@echo "--- Compilação concluída ---\n"

tadmatrix:
	@echo "--- Compilando tad-matrix ---"
	$(CC) $(CFLAGS) -c -o ./build/tad-matrix.o ./tad-matrix/matrix.c
	@echo "--- Compilação concluída ---\n"

clean: 
	rm -rf ./build/*
