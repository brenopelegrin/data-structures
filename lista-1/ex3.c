#include<stdio.h>
#include<stdlib.h>

float* readGrades(int* numAlunos){
    /*  This function receives the number N of students
        and then create an array notas with N columns.
        After that, it asks user to input all grades
        and fill the array, returning it.
    */
    float *notas = malloc(sizeof(float)*(*numAlunos));
    for(int i=0; i<(*numAlunos); i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    return notas;
}

float average(float* array, int* len){
    /*  This function calculates the average
        from a given array, returning the
        result.
    */
    float avgResult = 0;
    for(int i=0; i<(*len); i++){
        avgResult += array[i];
    }
    avgResult = avgResult/((float) (*len));
    return avgResult;
}

void printAverage(int* numStudents){
    /*  This function receives the number N of
        students.
        Then it calls the readGrades() function
        that returns a pointer to the array of N
        grades.
        After that, it calculates the average of
        the grades calling the function average()
    */
    float *notas = readGrades(numStudents);
    float avg = average(notas, numStudents);
    printf("Média: %.2f\n", avg);
    return;
}

int main(int argc, char* agrv[]){
    /*  Here we ask user for the number
        of students in the class.
        After that, we call printAverage()
        to create a grades array, fill it
        with user inputs and print the
        average value.
    */
    int numAlunos = 0;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    int *ptrNumStudents = &numAlunos;
    printAverage(ptrNumStudents);
    exit(EXIT_SUCCESS);
}