#include "tad-complex/complex.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    double a1, b1, a2, b2;
    int op;
    printf("--- Número complexo n1 ---");
    printf("\nDigite a parte real: ");
    scanf("%lf", &a1);
    printf("\nDigite a parte imaginária: ");
    scanf("%lf", &b1);

    Complex n1 = createComplex(&a1, &b1);

    printf("\n--- Número complexo n2 ---");
    printf("\nDigite a parte real: ");
    scanf("%lf", &a2);
    printf("\nDigite a parte imaginária: ");
    scanf("%lf", &b2);

    Complex n2 = createComplex(&a2, &b2);

    printf("\n");
    printf("\n--- Calculadora de complexos ---");
    printf("\n1 - Adição (n1 + n2)");
    printf("\n2 - Subtração (n1 - n2)");
    printf("\n3 - Multiplicação (n1 * n2)");
    printf("\n4 - Divisão (n1 / n2)");
    printf("\n5 - Conjugação de n1");
    printf("\n6 - Conjugação de n2");
    printf("\n7 - Sair\n");
    Complex result;

    while(op != 7){
        printf("\n> Digite a operação que você deseja realizar: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                add(&n1, &n2, &result);
                printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                break;
            case 2:
                subtract(&n1, &n2, &result);
                printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                break;
            case 3:
                multiply(&n1, &n2, &result);
                printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                break;
            case 4:
                if(divide(&n1, &n2, &result)){
                    printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                }
                else{
                    printf("\nErro: divisão por zero.\n");
                }
                break;
            case 5:
                result = getConjugate(&n1);
                printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                break;
            case 6:
                result = getConjugate(&n2);
                printf("\nResultado: %.2lf + %.2lf i\n", result.real, result.imaginary);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }       
    }
    return 0;
}