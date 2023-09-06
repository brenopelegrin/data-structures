#include<stdio.h>
#include<stdlib.h>

float* readGrades(int* numAlunos){
    float *notas = malloc(sizeof(float)*(*numAlunos));
    for(int i=0; i<(*numAlunos); i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    return notas;
}

float average(float* array, int* len){
    float avgResult = 0;
    for(int i=0; i<(*len); i++){
        avgResult += array[i];
    }
    avgResult = avgResult/((float) (*len));
    return avgResult;
}

void printAverage(int* numStudents){
    float *notas = readGrades(numStudents);
    float avg = average(notas, numStudents);
    printf("Média: %.2f\n", avg);
    return;
}

int main(int argc, char* agrv[]){
    int numAlunos = 0;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    int *ptrNumStudents = &numAlunos;
    printAverage(ptrNumStudents);
    exit(EXIT_SUCCESS);
}