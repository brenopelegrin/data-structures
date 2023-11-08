#include"./../tad-my_string/my_string.h"

#define PROCESS_SUCESS STR_PROCESS_SUCESS
#define MEMORY_ALLOCATION_ERROR STR_MEMORY_ALLOCATION_ERROR
#define CREATION_ERROR STR_CREATION_ERROR
#define INVALID_SIZE 4
#define PROCESS_ERROR 5

#define MAX_SIZE_NAME 30

typedef struct node{
    String *name;
    struct node* next;
    struct node* last;
} Node;

typedef struct dlist{
    Node* first;
    Node* last;
    int size;
} dList;

dList* create(int *flag);
/*Cria a lista*/

void insert(dList *list,String *name,int pos,int *flag);
/*Insere um nome em determinada posição da lista*/

void sorted_insert(dList *list,String *name,int *flag);
/*Insere um nome na lista de forma alfabética*/

dList* sorted_list(dList *list,int *flag);
/*Ordena a lista em ordem alfabética*/

void remove_name(dList *list,String *name,int *flag);
/*Retira um determinado elemento da lista*/

int exist(dList *list,String *name,int *flag);
/*Retorna 1 se o elemento existir na lista
  Retorna 0 caso contrário 
*/

int isEmpty(dList *list,int *flag);
/*Retorna 1 se a lista estiver vazia
  Retorna 0 caso contrário
*/

int isSorted(dList *list,int *flag);
/*Retorna 1 caso a lista esteja em ordem alfabética
  Retorna 0 caso contrário
*/

void printAll(dList *list,int *flag);
/*Imprime todos os elementos da lista*/

void printAll_inverted(dList *list,int *flag);
/*Imprime todos os elementos da lista ao contrário*/