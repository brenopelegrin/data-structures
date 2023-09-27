#include<stdlib.h>
#include<stdio.h>
#include "tad-matrix/matrix.h"

void PrintMatrix(Matrix*,int*);
void PrintError(int);
void MatrixInput(Matrix*,int,int);

int main(int argc, char *argv[]){

    int op,erro;
    int m,n;
    int mA,nA,mB,nB;
    int p;
    float val;
    Matrix A,B,C;

    printf("\
Insira o número da operação que deseja realizar:\n\
1: Soma de Matrizes\n\
2: Subtração de Matrizes\n\
3: Multiplicação de matriz por escalar\n\
4: Multiplicação de matrizes\n\
5: Potência de multiplicação de matrizes (para matrizes A e B e a potência n seria (A*B)^n)\n\
> Insira a operação desejada: ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:

        printf("Insira o tamanho das matrizes (no formato \"m n\")\n");
        scanf("%d %d",&m,&n);
        Create(&A,m,n);
        Create(&B,m,n);
        Create(&C,m,n);

        printf("Agora insira os elementos da primeira matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&A,m,n);

        printf("Agora insira os elementos da segunda matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&B,m,n);

        printf("O resultado da soma dessas duas matrizes é:\n");
        SumMatrix(&A,&B,&C,&erro);
        PrintMatrix(&C,&erro);
        break;
    case 2:

        printf("Insira o tamanho das matrizes (no formato \"m n\")\n");
        scanf("%d %d",&m,&n);
        Create(&A,m,n);
        Create(&B,m,n);
        Create(&C,m,n);

        printf("Agora insira os elementos da primeira matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&A,m,n);

        printf("Agora insira os elementos da segunda matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&B,m,n);

        printf("O resultado da soma dessas duas matrizes é:\n");
        SubMatrix(&A,&B,&C,&erro);
        PrintMatrix(&C,&erro);
        break;
    case 3:
        printf("Insira o tamanho da matriz (no formato \"m n\")\n");
        scanf("%d %d",&m,&n);
        Create(&A,m,n);

        printf("Insira os elementos da matriz (no formato que desejar)\n");
        MatrixInput(&A,m,n);

        printf("Insira o valor que irá multiplicar a matriz\n");
        scanf("%f",&val);

        printf("A matriz resultado é:\n");
        MultiplyScalar(&A,val,&erro);
        PrintMatrix(&A,&erro);
        break;
    case 4:

        printf("Insira o tamanho da primeira matriz (no formato \"m n\")\n");
        scanf("%d %d",&mA,&nA);
        Create(&A,mA,nA);

        printf("Insira o tamanho da segunda matriz (no formato \"m n\")\n");
        scanf("%d %d",&mB,&nB);
        Create(&B,mB,nB);

        if(nA!=mB){
            printf("O tamanho das matrizes não é compatível\n");
            break;
        } else{
            Create(&C,mA,nB);
        }

        printf("Agora insira os elementos da primeira matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&A,mA,nA);

        printf("Agora insira os elementos da segunda matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&B,mB,nB);

        printf("O resultado da multiplicação dessas matrizes é:\n");
        MultiplyMatrix(&A,&B,&C,&erro);
        PrintMatrix(&C,&erro);
        break;
    case 5:

        printf("Insira o tamanho da primeira matriz (no formato \"m n\")\n");
        scanf("%d %d",&mA,&nA);
        Create(&A,mA,nA);

        printf("Insira o tamanho da segunda matriz (no formato \"m n\")\n");
        scanf("%d %d",&mB,&nB);
        Create(&B,mB,nB);

        if(nA!=mB || mA!=nB){
            printf("O tamanho das matrizes não é compatível\n");
            break;
        } else{
            Create(&C,mA,nB);
        }

        printf("Agora insira os elementos da primeira matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&A,mA,nA);

        printf("Agora insira os elementos da segunda matriz (no formato que desejar, porém insira apenas a quantidade correta de elementos)\n");
        MatrixInput(&B,mB,nB);

        printf("Insira a potência \"n\"\n");
        scanf("%d",&p);

        printf("O resultado da potência da multiplicação dessas matrizes ((A*B)^%d) é:\n",p);
        PowerMatrix(&A,&B,&C,p,&erro);
        PrintMatrix(&C,&erro);
        break;
    default:
        break;
    };

    return 0;
}

void PrintMatrix(Matrix *M,int *erro){

    int i,j;

    if(M->created!=1){
        *erro=1;
        return;
    }
    for(i=0;i<M->t[0];i++){
        for(j=0;j<M->t[1];j++){
            printf("%f ",GetValue(M,i,j,erro));
        }
        printf("\n");
    }
    return;
}

void PrintError(int erro){
    switch (erro)
    {
    case 1:
        printf("Matrix não encontrada: erro 1\nÉ necessário criar a matrix utilizando 'Create()' antes de utiliza-la\n");
        break;
    case 2:
        printf("Tamanho incorreto: erro 2\nVerifique se as operações estão sendo realizadas corretamente, alguns dos possíveis motivos para esse erro são:\nMultiplicação de matrizes feita com tamanhos incorretos\nTentativa de transformar uma matrix não quadrada na matrix identidade\n");
        break;
    default:
        break;
    }
    return;
}


void MatrixInput(Matrix *M,int m, int n){

    int i,j,erro;
    float val;
    

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%f",&val);
            SetValue(M,val,i,j,&erro);
        }
    }
    return;
}
