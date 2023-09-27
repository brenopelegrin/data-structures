#include<stdio.h>
#include "mod.h"

int main(int argc, char *argv[]){
	int test = 7;
	int *ptr = &test;
	int value = returnIntSimples(ptr);
	printf("value: %d\n", value);
	printf("Hello World!\n");
	return 0;
}
