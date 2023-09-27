# Only works on Linux, in Windows directories are different.
echo "--- Cleaning build directory ---\n"
echo "--- done! ---\n"
rm -rf ./build/*
echo "--- Compiling tad-matrix ---\n"
gcc -Wall -c -o ./build/tad-matrix.o ./tad-matrtix/matrix.c
echo "--- done! ---\n"
echo "--- Compiling main ---\n"
gcc -Wall -I./tad-matrix/ -o ./build/main.o  ./main.c ./build/tad-matrix.o -lm
echo "--- done! ---\n"