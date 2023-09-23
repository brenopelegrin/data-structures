echo "--- Compiling tad-complex ---\n"
gcc -c -o ./tad-complex/complex.o ./tad-complex/complex.c
echo "--- done! ---\n"
echo "--- Compiling main ---\n"
gcc -I./tad-complex/ -o main.o  main.c ./tad-complex/complex.o -lm
echo "--- done! ---\n"