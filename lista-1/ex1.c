#include<stdio.h>
#include<stdlib.h>

char* concat(char** c1, char** c2, char** join){
    /*  This function concatenates two strings c1 and c2, joining
        them using the join string.
        It will dinamically allocate the result string.
        Please use free(x) where x = concat(c1, c2, join) after
        calling the function to avoid memory leaks.
    */
    size_t size = 0, i = 0;
    char *result = NULL;
    for(char *ptr = *c1; *ptr != '\0'; ptr++){
        if (i + 1 >= size)
        {
            size = size * 2 + 1;
            //Realoca para caber na memória
            result = realloc(result, sizeof(char)*size);
            if(!result){
                printf("Erro: memória indisponível para realloc");
                exit(EXIT_FAILURE);
            }
        }
        result[i] = *ptr;
        i++;
    }
    result[i] = **join;
    i+=1;
    for(char *ptr = *c2; *ptr != '\0'; ptr++){
        if (i + 1 >= size)
        {
            size = size * 2 + 1;
            //Realoca para caber na memória
            result = realloc(result, sizeof(char)*size);
            if(!result){
                printf("Erro: memória indisponível para realloc");
                exit(EXIT_FAILURE);
            }
        }
        result[i] = *ptr;
        i++;
    }
    return result;
}

int main() {
    char *string1 = NULL;
    char *string2 = NULL;
    char *stringConcat = NULL;
    char join[1];
    char *ptrJoin = &join[0];
    int charBuffer = 0;
    size_t size = 0, i = 0;

    //O código abaixo recebe duas strings de tamanho desconhecido usando malloc
    printf("Digite a string 1: ");
    while ((charBuffer=getchar()) != EOF && charBuffer != '\n') {
        if (i + 1 >= size)
        {
            size = size * 2 + 1;
            //Realoca para caber na memória
            string1 = realloc(string1, sizeof(char)*size);
            if(!string1){
                printf("Erro: memória indisponível para realloc");
                exit(EXIT_FAILURE);
            }
        }
        string1[i] = charBuffer;
        i++;
    }

    if (string1 != NULL) {
        //Termina a string1
        string1[i] = '\0';
    } else {
        printf("Erro: string 1 não pode ser vaiza.\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    size = 0;
    charBuffer = 0;
    printf("Digite a string 2: ");
    while ((charBuffer=getchar()) != EOF && charBuffer != '\n') {
        if (i + 1 >= size)
        {
            size = size * 2 + 1;
            //Realoca para caber na memória
            string2 = realloc(string2, sizeof(char)*size);
            if(!string2){
                printf("Erro: memória indisponível para realloc");
                exit(EXIT_FAILURE);
            }
        }
        string2[i] = charBuffer;
        i++;
    }

    if (string2 != NULL) {
        //Termina a string2
        string2[i] = '\0';
    } else {
        printf("Erro: string 2 não pode ser vaiza.\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o caractere de concatenação: ");
    join[0] = getchar();

    stringConcat = concat(&string1, &string2, &ptrJoin);
    printf("Resultado: %s\n", stringConcat);

    free(stringConcat);
    free(string1);
    free(string2);

    exit(EXIT_SUCCESS);
}