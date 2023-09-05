#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    float lado=0;
    printf("Informe o lado do quadrado: ");
    scanf("%f", &lado);
    printf("Área do quadrado: ");
    printf("%.2f", lado*lado);
    return 0;
}