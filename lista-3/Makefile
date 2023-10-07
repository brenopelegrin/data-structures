CC = gcc
CFLAGS = -Wall

TARGET = complexos

default: main

main: tadcomplex
	@echo "=== Compiling main ==="
	$(CC) $(CFLAGS) -I./tad-complex/ -o ./build/main.o  ./main.c ./build/tad-complex.o -lm
	@echo "=== Done compiling main ==="

tadcomplex:
	@echo "=== Compiling tad-complex ==="
	$(CC) $(CFLAGS) -c -o ./build/tad-complex.o ./tad-complex/complex.c
	@echo "=== Done compiling tad-complex ===\n"

clean:
	rm -rf ./build/*