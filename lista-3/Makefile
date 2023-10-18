CC = gcc
CFLAGS = -Wall

TARGET = linkedlistqueue

default: main

main: tadqueue
	@echo "compiling main\n"
	$(CC) $(CFLAGS) -I./tad-linkedlist -I./tad-queue -o build/main.o main.c -lm ./tad-linkedlist/build/lkdlist.o -lm ./tad-queue/build/queue.o

tadqueue: tadlinkedlist
	@echo "compiling tad-queue\n"
	$(CC) $(CFLAGS) -c -o tad-queue/build/queue.o ./tad-queue/queue.c

tadlinkedlist:
	@echo "compiling tad-linkedlist\n"
	$(CC) $(CFLAGS) -c -o tad-linkedlist/build/lkdlist.o ./tad-linkedlist/lkdlist.c
	
clean:
	@echo "cleaning build"
	rm -rf ./build/*
	rm -rf ./tad-linkedlist/build/*
	rm -rf ./tad-queue/build/*