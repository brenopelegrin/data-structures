#define STR_PROCESS_SUCESS 1
#define STR_MEMORY_ALLOCATION_ERROR 2
#define STR_CREATION_ERROR 3


typedef struct string{
    int len;
    char *str;
} String;

String* str_create(int size,int *flag);
/*Cria a string
Parâmetros:
    int size: tamanho da string
    int *flag: sinal
Retorna:
    String*: string já configurada
*/

int str_comp(String *A,String *B,int *flag);
/*Compara duas strings:
Parâmetros:
    String *A: primeira string
    String *B: segunda string
    int *flag: sinal
Retorna:
    -1: B vem antes de A na ordem alfabética
    0: A e B são iguais
    1: A vem antes de B na ordem alfabética
*/

String* str_lowercase(String *A,int *flag);
/*Converte para lowercase*/

String* str_upercase(String *A,int *flag);
/*Converte para upercase*/

int str_isLowercase(String *A,int *flag);

int str_isUpercase(String *A,int *flag);

int str_isCaptizalized(String *A,int *flag);