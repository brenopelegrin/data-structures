#include<stdio.h>

int main(){
	int m[10];
	int *ptr = m;
	int i=0;
	for(i=0; i<10; i++){
		*(ptr+i) = i;
	}
	int j=0;
	for(j=0; j<10; j++){
		printf("%d ", *(ptr+j));
	}
	return 0;
}
