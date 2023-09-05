#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[5] = {1,2,3,4,5};
	int size = 5;
	int *pm = &m[0];
	int i;
	int* pi;
	printf("pm = m[0] = %d\n", *pm);

	printf("starting for\n");
	for(i=0, pi=m; i<size; i++, pi++){
		printf("pi[%d] = m[%d] = %d\n", i, i, *pi);
	};
	return 0;
}
