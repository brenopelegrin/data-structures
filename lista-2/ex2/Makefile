CC = gcc
CFLAGS = -Wall

TARGET = matrix

default: main

main: tadmatrix
	@echo "=== Compiling main ==="
	$(CC) $(CFLAGS) -I./tad-matrix/ -o ./build/main.o  ./main.c ./build/tad-matrix.o -lm
	@echo "=== Done compiling main ==="

tadmatrix:
	@echo "=== Compiling tad-matrix ==="
	$(CC) $(CFLAGS) -c -o ./build/tad-matrix.o ./tad-matrix/matrix.c
	@echo "=== Done compiling tad-matrix ===\n"

clean:
	rm -rf ./build/*