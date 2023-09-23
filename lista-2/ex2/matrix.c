#include<stdlib.h>
#include<stdio.h>
#include "mymatrix.h"

void Create(Matrix *M,int m,int n){

    int i;
    
    //Coloca o tamanho da matrix
    M->t[0]=m;
    M->t[1]=n;

    M->elements=malloc(m*sizeof(float *));
    for(i=0;i<m;i++){
        M->elements[i] = malloc(n*sizeof(float));
    }

    M->created=1;

    return;
}

void SetValue(Matrix* M,float val,int m,int n,int *erro){
    if(M->created==1){
        M->elements[m][n]=val;
        *erro=0;
        return;
    } else{
        *erro=1;
        return;
    }
}

float GetValue(Matrix* M,int m,int n,int *erro){
    if(M->created==1){
        *erro=0;
        return M->elements[m][n];
    } else{
        *erro=1;
        return(-1.); /*A mesma coisa que o professor tinha comentado na aula,
        retornar alguma coisa aqui não é muito legal*/
    }
}   

int IsIdentity(Matrix* M,int *erro){

    int i;

    if(M->created==1){

        if(M->t[0]==M->t[1]){

            for(i=0;i<M->t[0];i++){
                if(GetValue(M,i,i,erro)!=1){
                    return 0;
                }
            }
            return 1;

        } else return 0;

    } else{
        *erro=1;
        return -1;
    }
}

void SetIdentity(Matrix* M,int *erro){

    int i,j;

    if(M->created==0){
        *erro=1;
        return;
    } else if(M->t[0]!=M->t[1]){
        *erro=2;
        return;
    }
    for(i=0;i<M->t[0];i++){
        for(j=0;j<M->t[0];j++){
            if(i==j){
                SetValue(M,1,i,j,erro);
            } else{
                SetValue(M,0,i,j,erro);
            }
        }
    }
    return;
}

void MultiplyScalar(Matrix *M,float val,int *erro){

    int i,j;

    if(M->created!=1){
        *erro=1;
        return;
    }
    for(i=0;i<M->t[0];i++){
        for(j=0;j<M->t[1];j++){
            SetValue(M,GetValue(M,i,j,erro)*val,i,j,erro);
        }
    }
    return;
}

void MultiplyMatrix(Matrix* M1,Matrix* M2,Matrix* Mres,int *erro){

    int i,j,k;
    float res;
    
    //Verifica se as matrizes foram criadas e podem ser multiplicadas
    if(M1->created!=1 || M2->created!=1){
        *erro=1;
        return;
    
    } else if(M1->t[1]!=M2->t[0]){ //Verifica se o tamanho está correto
        *erro=2;
        return;
    }
    if(Mres->created!=1){
        Create(Mres,M1->t[0],M2->t[1]);
    } else if(Mres->t[0]!=M1->t[0] || Mres->t[1]!=M2->t[1]){
        *erro=2;
        return;
    }
    //Se chegou até aqui tá tudo certo com as matrizes
    for(i=0;i<M1->t[0];i++){
        for(j=0;j<M2->t[1];j++){
            res = 0;
            for(k=0;k<M1->t[1];k++){
                res += GetValue(M1,i,k,erro)*GetValue(M2,k,j,erro);
            }
            SetValue(Mres,res,i,j,erro);
        }
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
        printf("Tamanho incorreto: erro 2\nVerifique se as operações estão sendo realizadas corretamente, alguns dos possíveis motivos para esse erro são:\nMultiplicação de matrizes feita com tamanhos incorretos\nTentativa de transformar uma matrix não quadrada na matrix identidade");
        break;
    default:
        printf("Não foi detectado nenhum erro\n");
        break;
    }
    return;
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