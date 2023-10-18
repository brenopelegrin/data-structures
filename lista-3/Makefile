CC = gcc
CFLAGS = -Wall

TARGET = linkedlistqueue

default: main

main: tadqueuelinkedlist
	@echo "\n> compiling main\n"
	$(CC) $(CFLAGS) -I./tad-queuelinkedlist -o build/main.o main.c -lm ./tad-queuelinkedlist/build/queuelkdlist.o

tadqueuelinkedlist:
	@echo "\n> compiling tad-queuelinkedlist\n"
	$(CC) $(CFLAGS) -c -o tad-queuelinkedlist/build/queuelkdlist.o ./tad-queuelinkedlist/queuelkdlist.c
	
clean:
	@echo "cleaning build"
	rm -rf ./build/*
	rm -rf ./tad-queuelinkedlist/build/*