#include "tad-complex/complex.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    // Creates two complex numbers based on user input
    double a1, b1, a2, b2;
    printf("--- Número complexo n1 ---");
    printf("\nDigite a parte real: ");
    scanf("%lf", &a1);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &b1);

    Complex n1;
    createComplexFromCart(&a1, &b1, &n1);

    printf("\n--- Número complexo n2 ---");
    printf("\nDigite a parte real: ");
    scanf("%lf", &a2);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &b2);

    Complex n2;
    createComplexFromCart(&a2, &b2, &n2);

    printf("\n");
    printf("\n--- Calculadora de complexos ---");
    printf("\n1 - Adição (n1 + n2)");
    printf("\n2 - Subtração (n1 - n2)");
    printf("\n3 - Multiplicação (n1 * n2)");
    printf("\n4 - Divisão (n1 / n2)");
    printf("\n5 - Conjugação de n1");
    printf("\n6 - Conjugação de n2");
    printf("\n7 - Multiplicação de n1 por escalar");
    printf("\n8 - Multiplicação de n2 por escalar");
    printf("\n0 - Sair\n");
    Complex result;
    double scalar = 1.0;
    int op = -1;
    // Waits for user choice, and stop when users chooses option 7 (exit)
    while(op != 0){
        printf("\n> Digite a operação que você deseja realizar: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                add(&n1, &n2, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 2:
                subtract(&n1, &n2, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 3:
                multiply(&n1, &n2, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 4:
                if(divide(&n1, &n2, &result) == -1){
                    printf("Erro: divisão por zero.\n");
                }
                else{
                    printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                }
                break;
            case 5:
                createConjugate(&n1, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 6:
                createConjugate(&n2, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 7:
                printf("Digite o escalar: ");
                scanf("%lf", &scalar);
                multiplyByScalar(&n1, &scalar, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 8:
                printf("Digite o escalar: ");
                scanf("%lf", &scalar);
                multiplyByScalar(&n2, &scalar, &result);
                printf("Resultado: %.4lf + %.4lf i\n", result.real, result.imaginary);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }       
    }
    return 0;
}