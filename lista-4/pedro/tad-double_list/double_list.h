#define PROCESS_SUCESS 1
#define MEMORY_ALLOCATION_ERROR 2

typedef struct node{
    char *name; //Com certeza vai ter que mudar isso
    struct node* next;
    struct node* last;
} Node;

typedef struct dlist{
    Node *first;
    Node *last;
    int size;
} dList;

dList* create(int *flag);
/*Cria a lista*/

void insert(dList *list,char *name[],int pos,int *flag);
/*Insere um nome em determinada posição da lista*/

void sorted_insert(dList *list,char *name[],int *flag);
/*Insere um nome na lista de forma alfabética*/

void remove(dList *list,char *name[],int *flag);
/*Retira um determinado elemento da lista*/

int exist(dList *list,char *name[],int *flag);
/*Retorna 1 se o elemento existir na lista
  Retorna 0 caso contrário 
*/

int isEmpty(dList *list,int *flag);
/*Retorna 1 se a lista estiver vazia
  Retorna 0 caso contrário
*/

void printAll(dList *list,int *flag);