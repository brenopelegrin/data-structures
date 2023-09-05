#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int n_alunos = 0;
	float soma = 0;
	printf("Digite o numero de alunos: ");
	scanf("%d", &n_alunos);

	float notas[n_alunos];
	int i=0;
	for(i=0;i<n_alunos;i++){
		printf("Digite a nota %d: ", i+1);
		scanf("%f", &notas[i]);
		soma+=notas[i];
	}
	printf("Media: %f", soma/n_alunos);
	return 0;
}
