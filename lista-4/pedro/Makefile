CC = gcc
CFLAGS = -Wall

TARGET = main.out

all: main.out

main.out: my_string.o double_list.o main.c
	@echo "=== Compiling main ==="
	$(CC) $(CFLAGS) -I./tad-double_list/ -o ./build/main.out  ./main.c ./build/double_list.o ./build/my_string.o -lm
	@echo "=== Done compiling main ===\n"

double_list.o: my_string.o ./tad-double_list/double_list.c
	@echo "=== Compiling tad-double_list ==="
	$(CC) $(CFLAGS) -I./tad-my_string/ -c -o ./build/double_list.o ./tad-double_list/double_list.c
	@echo "=== Done compiling tad-double_list ===\n"

my_string.o: ./tad-my_string/my_string.c
	@echo "=== Compiling tad-my_string ==="
	$(CC) $(CFLAGS) -c -o ./build/my_string.o ./tad-my_string/my_string.c
	@echo "=== Done Compiling tad-my_string ===\n"

clean:
	rm -rf ./build/*