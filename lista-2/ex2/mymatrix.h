//Um módulo para trabalhar com matrizes em C
//Eu sei que já existem, só quero implementar

typedef struct {
    int created;//Provavelmente não é a melhor maneira
    int t[2];
    float **elements;
} Matrix;

void Create(Matrix*,int m,int n);
/*Create a matrix with the size of mxn
To use it you need first to create a Matrix struct
*/

void SetValue(Matrix*,float val,int m,int n,int *erro);
/*Sets the value "val" in the position "mn" of the matrix*/

float GetValue(Matrix*,int m,int n,int *erro);
/*Return the value of the position "mn" of the matrix*/

int IsIdentity(Matrix*,int *erro);
/*Return 1 if the matrix is the identity, 0 if not*/

void SetIdentity(Matrix*,int *erro);
/*Transforma a matriz na matriz identidade se ela for quadrada*/

void MultiplyScalar(Matrix *,float,int *erro);
/*Multiplica a matrix por um escalar*/

void MultiplyMatrix(Matrix*,Matrix*,Matrix*,int *erro);
/*Mutiplica duas matrizes, se for possível*/

void PrintError(int erro);
/*Imprime qual o erro recebido e algumas informações sobre ele*/

void PrintMatrix(Matrix*,int *erro);
/*Imprime a matrix*/

//Acho que tá tudo funcionando acima desse comentário