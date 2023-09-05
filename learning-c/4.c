#include<stdio.h>

void troca(int *ptrx, int *ptry){
	int temp = 0;
	temp = *ptry;
	*ptry = *ptrx;
	*ptrx = temp;
}

int main(){
	int x = 1;
	int y = 2;
	troca(&x, &y);
	printf("%d %d", x, y);
	return 0;
}
