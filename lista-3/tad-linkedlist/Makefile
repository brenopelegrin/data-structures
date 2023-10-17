CC = gcc
CFLAGS = -Wall

TARGET = linkedlistqueue

default: main

main: tadlinkedlist
	$(CC) $(CFLAGS) -I./ -o main.o main.c lkdlist.o -lm

tadlinkedlist:
	$(CC) $(CFLAGS) -c -o lkdlist.o lkdlist.c
	
clean:
	rm -rf ./build/*