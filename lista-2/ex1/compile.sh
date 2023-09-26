# Only works on Linux, in Windows directories are different.
echo "--- Cleaning build directory ---\n"
echo "--- done! ---\n"
rm -rf ./build/*
echo "--- Compiling tad-complex ---\n"
gcc -Wall -c -o ./build/tad-complex.o ./tad-complex/complex.c
echo "--- done! ---\n"
echo "--- Compiling main ---\n"
gcc -Wall -I./tad-complex/ -o ./build/main.o  ./main.c ./build/tad-complex.o -lm
echo "--- done! ---\n"