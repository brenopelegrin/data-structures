#include "conjuntos.h"
#include<stdlib.h>

int *uniao(int *A, int* sizeA, int *B, int* sizeB){
	int *new = malloc(sizeof(int) * (*sizeA + *sizeB));
	for(int *ptr = A, i=0;i<*sizeA; ptr++, i++){
		new[i] = *ptr;
	}
	for(int *ptr = B, i=0;i<*sizeB; ptr++, i++){
		new[i + *sizeA] = *ptr;
	}
	return new;
}
