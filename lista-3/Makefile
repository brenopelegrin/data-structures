CC = gcc
CFLAGS = -Wall

TARGET = linkelistqueue
SRCS = main.c tad-queue/queue.c tad-linkedlist/lkdlist.c
OBJS = main.o tad-queue/queue.o tad-linkedlist/lkdlist.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c lkdlist.h
	$(CC) $(CFLAGS) -c tad-queue/queue.c

lkdlist.o: lkdlist.c lkdlist.h
	$(CC) $(CFLAGS) -c tad-linkedlist/lkdlist.c

clean:
	rm -f $(TARGET) 
	rm -r *.o
	rm tad-linkedlist/*.o
	rm tad-queue/*.o