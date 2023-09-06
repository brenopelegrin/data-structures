#include<stdio.h>
#include<stdlib.h>

int main(){
    char *test = NULL;
    test = realloc(test, 5);
    char *pt2 = &test[0];

    for(int i=0; i<=4; i++){
        test[i] = i+'0';
    }

    printf("%p\n", &test[0]);
    printf("%p\n", (void *)pt2);
    printf("%lu\n", sizeof(*test)/sizeof(char));

    return 0;
}