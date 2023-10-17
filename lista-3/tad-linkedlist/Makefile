CC = gcc
CFLAGS = -Wall

TARGET = linkedlistqueue

default: main

main: tadlinkedlist
	$(CC) $(CFLAGS) -I./ -o build/main.o main.c build/lkdlist.o -lm

tadlinkedlist:
	$(CC) $(CFLAGS) -c -o build/lkdlist.o lkdlist.c
	
clean:
	rm -rf ./build/*