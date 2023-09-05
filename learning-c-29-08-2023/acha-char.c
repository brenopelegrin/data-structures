#include <stdio.h>

char *achachar(char *str, char c){
	char *pc = str;
	while (*pc != c && *pc != '\0') pc++;
	return *pc ? pc : NULL;
}

int main(){
	char m[] = "testando";
	char c[1] = "a";
	char *ptr = m;
	char *ptr2;

	ptr2 = achachar(ptr, c[0]);
	putchar(*ptr2);
	return 0;
}
