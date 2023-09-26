typedef struct{
    int created;
    int t[2];
    float **elements;
} Matrix;

void Create(Matrix*,int m,int n);
/*Cria uma matriz com o tamanho m por n
Para utilizar é necessário primeiro criar uma variável do tipo Matrix
*/

void SetValue(Matrix*,float val,int m,int n,int *erro);
/*Coloca o valor "val" na posição "mn" da matriz*/

float GetValue(Matrix*,int m,int n,int *erro);
/*Retorna o valor na posição "mn" da matrix*/

int IsIdentity(Matrix*,int *erro);
/*Retorna 1 se a matriz for a identidade e 0 caso contrário*/

void SetIdentity(Matrix*,int *erro);
/*Transforma a matriz na matriz identidade se ela for quadrada*/

void MultiplyScalar(Matrix *,float,int *erro);
/*Multiplica a matrix por um escalar*/

void MultiplyMatrix(Matrix*,Matrix*,Matrix*,int *erro);
/*Mutiplica duas matrizes, se for possível*/

void SumMatrix(Matrix*,Matrix*,Matrix*,int *);
/*Soma duas matrizes*/

void SubMatrix(Matrix*,Matrix*,Matrix*,int *);
/*Subtrai duas matrizes*/

void PowerMatrix(Matrix*A,Matrix*B,Matrix*res,int n,int *erro);
/*Faz a operação de (A*B)^n*/

void MakeEqual(Matrix*,Matrix*,int*);
/*Deixa duas matrizes cria duas matrizes iguais*/

/*
------Guia de Erros-------
Erro = 0:
    O programa não encontrou nenhum erro em sua execução.
Erro = 1:
    O programa encontrou um erro no processo de criação das matrizes, é possível que uma delas não tenha sido criada antes de ser manipulada.
Erro = 2:
    O programa encontrou um erro no tamanho das matrizes, pode ser que duas matrizes incompatíveis tenham sido multiplicadas.
*/