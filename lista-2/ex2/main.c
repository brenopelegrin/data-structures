#include<stdlib.h>
#include<stdio.h>
#include "mymatrix.h"

int main(int argc, char *argv[]){

    int erro,i,j,k;
    Matrix m1,m2,mres;
    
    Create(&m1,2,3);Create(&m2,3,1);//Create(&mres,m,n);

    for(i=1,j=3;i<4;i++,j--){
        SetValue(&m1,i,0,i-1,&erro);
        SetValue(&m1,j,1,i-1,&erro);
        SetValue(&m2,i,i-1,0,&erro);
    }
    
    PrintMatrix(&m1,&erro);
    printf("===\n");
    PrintMatrix(&m2,&erro);
    printf("------------------\n");
    MultiplyMatrix(&m1,&m2,&mres,&erro);
    PrintMatrix(&mres,&erro);
    PrintError(erro);

    return 0;
}