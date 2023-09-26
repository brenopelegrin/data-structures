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
        return(-1.);
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
    Matrix A,B;
    
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

    MakeEqual(M1,&A,erro);MakeEqual(M2,&B,erro);
    for(i=0;i<M1->t[0];i++){
        for(j=0;j<M2->t[1];j++){
            res = 0;
            for(k=0;k<M1->t[1];k++){
                res += GetValue(&A,i,k,erro)*GetValue(&B,k,j,erro);
            }
            SetValue(Mres,res,i,j,erro);
        }
    }
    return;
}

void SumMatrix(Matrix* M1,Matrix* M2,Matrix* Mres,int *erro){

    int i,j;

    if(M1->created!=1 || M2->created!=1){
        *erro=1;
        return;
    } else if(M1->t[0]!=M2->t[0] || M1->t[1]!=M2->t[1]){
        *erro=2;
        return;
    }

    if(Mres->created==1){
        if(Mres->t[0]!=M1->t[0] || Mres->t[1]!=M1->t[1]){
            *erro=2;
            return;
        }
    } else{
        Create(Mres,M1->t[0],M1->t[1]);
    }
    //Se chegar até aqui tá tudo certo
    for(i=0;i<M1->t[0];i++){
        for(j=0;j<M1->t[1];j++){
            SetValue(Mres,GetValue(M1,i,j,erro)+GetValue(M2,i,j,erro),i,j,erro);
        }
    }
    return;
}

void SubMatrix(Matrix* M1,Matrix* M2,Matrix* Mres,int *erro){

    int i,j;

    if(M1->created!=1 || M2->created!=1){
        *erro=1;
        return;
    } else if(M1->t[0]!=M2->t[0] || M1->t[1]!=M2->t[1]){
        *erro=2;
        return;
    }

    if(Mres->created==1){
        if(Mres->t[0]!=M1->t[0] || Mres->t[1]!=M1->t[1]){
            *erro=2;
            return;
        }
    } else{
        Create(Mres,M1->t[0],M1->t[1]);
    }
    //Se chegar até aqui tá tudo certo
    for(i=0;i<M1->t[0];i++){
        for(j=0;j<M1->t[1];j++){
            SetValue(Mres,GetValue(M1,i,j,erro)-GetValue(M2,i,j,erro),i,j,erro);
        }
    }
    return;
}

void PowerMatrix(Matrix*A,Matrix*B,Matrix*res,int n,int *erro){

    int i;
    Matrix aux;
    
    //Verifica se as matrizes foram criadas e podem ser multiplicadas
    if(A->created!=1 || B->created!=1){
        *erro=1;
        return;
    
    } else if(A->t[1]!=B->t[0] || A->t[0]!=B->t[1]){ //Verifica se o tamanho está correto
        *erro=2;
        return;
    }
    if(res->created!=1){
        Create(res,A->t[0],B->t[1]);
    } else if(res->t[0]!=A->t[0] || res->t[1]!=B->t[1]){
        *erro=2;
        return;
    }
    //Se chegou até aqui tá tudo certo
    MultiplyMatrix(A,B,&aux,erro);
    MultiplyMatrix(A,B,res,erro);
    for(i=1;i<n;i++){
        IsIdentity(res,erro);
        MultiplyMatrix(res,&aux,res,erro);
    }
    return;
}

void MakeEqual(Matrix *M1,Matrix *M2,int *erro){

    int i,j;

    if(M1->created!=1){
        *erro=1;
        return;
    } if(M2->created==1){
        if(M1->t[0]!=M2->t[0] || M1->t[1]!=M2->t[1]){
            *erro = 2;
            return;
        }
    } else{
        Create(M2,M1->t[0],M1->t[1]);
    }
    //Verifica tudo antes
    for(i=0;i<M1->t[0];i++){
        for(j=0;j<M1->t[1];j++){
            SetValue(M2,GetValue(M1,i,j,erro),i,j,erro);
        }
    }
    
    return;
}