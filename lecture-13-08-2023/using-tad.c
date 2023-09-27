#include "conjuntos.h"
#include<stdlib.h>
#include<stdio.h>

int main(){
    int *ptrA = malloc(sizeof(int)*4);
    int *ptrB = malloc(sizeof(int)*4);
    int sizeA = 4;
    int *ptrSizeA = &sizeA;
    int sizeB = 4;
    int *ptrSizeB = &sizeB;
    for(int i=0; i<4; i++){
        ptrA[i] = i+1;
        ptrB[i] = i+5;
    }

    int *res;

    res = uniao(ptrA, ptrSizeA, ptrB, ptrSizeB);
    for(int i=0; i<(sizeA+sizeB); i++, res++){
        printf("%d", *res);
    }

    return 0;
}