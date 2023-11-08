CC = gcc
CFLAGS = -Wall

TARGET = doublelinkedlist

default: main

main: double_lkdlist
	@echo "\n> compiling main\n"
	$(CC) $(CFLAGS) -I./tad-double_lkdlist -o build/main.o main.c -lm ./tad-double_lkdlist/build/double_lkdlist.o

double_lkdlist:
	@echo "\n> compiling tad-double_lkdlist\n"
	$(CC) $(CFLAGS) -c -o tad-double_lkdlist/build/double_lkdlist.o ./tad-double_lkdlist/double_lkdlist.c
	
clean:
	@echo "\n> cleaning build\n"
	rm -rf ./build/*
	rm -rf ./tad-double_lkdlist/build/*