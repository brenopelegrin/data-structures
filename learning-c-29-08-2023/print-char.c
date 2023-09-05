#include <stdio.h>

int main(){
	char str[] = "oitudobem";
	char *ptr;
	for (ptr=str; *ptr != '\0'; ptr++){
		putchar(*ptr);
	};
	return 0;
}
