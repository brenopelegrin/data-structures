#include<stdio.h>

float factorial(int n){
	// n! = n*(n-1)*(n-2)*(n-3)*...*1
	float atual = (float) n;
	int i = 1;
	while(n-i > 1){
		atual = atual*(n-i);
		i = i+1;
	}
	return atual;
}

int main(){
	int n = 0;
	printf("Digite o número inteiro: ");
	scanf("%d", &n);
	float resultado = factorial(n);
	printf("Resultado: %f", resultado);
	return 0;
}
