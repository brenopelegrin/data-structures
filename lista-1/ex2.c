#include<stdio.h>
#include<stdlib.h>

float* multiply(float* matriz1, int* rows1, int* cols1, float* matriz2, int* rows2, int* cols2){
    /*  This function takes two matrices A(m,n) and B(p,q) with n=p and
        calculates (A*B)

        Please free the returned array after using it, e.g.
        
        result = multiply(args...);
        free(result);
    */
    float *result = malloc((*rows1)*(*cols2)*sizeof(float));
    if(!result){
        printf("Erro: memória não disponível para malloc.");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<*rows1; i++){
        for(int j=0; j<*cols2; j++){
            float curr = 0.0;
            for (int k = 0; k < *cols1; k++) {
                // This pointer operations mean curr += first[i][k] * second[k][j];
                // Where curr = result[i][j]

                // We need to do this because multidimensional arrays are stored as
                // a sequential list of (cols*rows) items in the memory.
                curr += (*(matriz1 + (i*(*cols1) + k))) * (*(matriz2 + (k*(*cols2) + j)));
            }
            // result[i][j] = curr
            *(result + (i*(*cols2) + j)) = curr;
        }
    }
    return result;    
}

float* multiplyRec(float* matriz1, int* rows1, int* cols1, float* matriz2, int* rows2, int* cols2, int* n){
    /*  This function takes two matrices A(m,n) and B(p,q) with n=p, m=q and
        calculates (A*B)^n.

        Please free the returned array after using it, e.g.

        result = multiplyRec(args...);
        free(result);
    */
    float *result1 = malloc((*rows1)*(*cols2)*sizeof(float));
    
    result1 = multiply(matriz1, rows1, cols1, matriz2, rows2, cols2);

    if(*n==1){
        return result1;
    }
    else{
        float *result2 = malloc((*rows1)*(*cols2)*sizeof(float));
        result2 = multiply(result1, rows1, cols2, result1, rows1, cols2);
        for(int i=0; i< (*n)-2; i++){
            // Does (A*B)*(A*B)*...*(A*B) n times 
            result2 = multiply(result2, rows1, cols2, result1, rows1, cols2);
        }
        free(result1);
        return result2;
    }
}

int main(int agrc, char* argv[]){
    //Create matrices and define sizes
    float matriz1[][3] = {{1.0,2.0,3.0}, {4.0, 5.0, 6.0}};
    float matriz2[][2] = {{2.0,3.0}, {5.0, 6.0}, {8.0, 9.0}};

    int cols1 = (int) (sizeof(matriz1[0])/sizeof(float));
    int rows1 = (int) (sizeof(matriz1)/(sizeof(float)*cols1));

    int cols2 = (int) (sizeof(matriz2[0])/sizeof(float));
    int rows2 = (int) (sizeof(matriz2)/(sizeof(float)*cols2));

    //Create pointers and define n
    float *ptrM1 = &matriz1[0][0];
    float *ptrM2 = &matriz2[0][0];
    int *ptrR1 = &rows1;
    int *ptrC1 = &cols1;
    int *ptrR2 = &rows2;
    int *ptrC2 = &cols2;
    float *result;

    int n = 3;
    int *ptrN = &n;

    printf("Resultado: \n");

    if(cols1 != rows2 || rows1 != cols2){
        printf("Erro: tamanho de m1 e m2 não compatíveis. Se A(m,n) e B(p, q), é necessário que n=p e m=q.");
        exit(EXIT_FAILURE);
    } else{
        result = multiplyRec(ptrM1, ptrR1, ptrC1, ptrM2, ptrR2, ptrC2, ptrN);
    }

    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            printf(" %.2f ", *(result + (i*(cols2) + j)));
        }
        printf("\n");
    }

    return 0;
}