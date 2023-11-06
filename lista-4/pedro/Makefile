CC = gcc
CFLAGS = -Wall

TARGET = double_list

default: main

main: double_list
	@echo "=== Compiling main ==="
	$(CC) $(CFLAGS) -I./tad-double_list/ -o ./build/main.o  ./main.c ./build/tad-double_list.o -lm
	@echo "=== Done compiling main ==="

double_list:
	@echo "=== Compiling tad-double_list ==="
	$(CC) $(CFLAGS) -c -o ./build/double_list.o ./tad-double_list/double_list.c
	@echo "=== Done compiling tad-double_list ===\n"

clean:
	rm -rf ./build/*
