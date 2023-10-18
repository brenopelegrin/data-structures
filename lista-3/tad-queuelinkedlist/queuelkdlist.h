#define LKDLIST_ERROR_CANT_ALLOCATE_LIST -1
#define LKDLIST_ERROR_CANT_ALLOCATE_NODE -2
#define LKDLIST_ERROR_INDEX_OUT_OF_BOUNDS -3
#define LKDLIST_ERROR_NOT_IMPLEMENTED 0
#define LKDLIST_SUCCESS 1

// queue.c definitions
#define PROCESS_SUCESS LKDLIST_SUCCESS 
#define CREATION_ERROR 2
#define MEMORY_ALLOCATION_ERROR 3

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct lkdlist {
    Node* first;
    Node* last;
    int size;
} LkdList;

typedef struct {
    int created;
    LkdList *l;
} Queue;

LkdList* lkdlist_createList(int *flag);
/*  Cria uma lista encadeada.
    Se sucesso, flag = 1 e retorna o ponteiro para LkdList.
    Caso falhe, a flag será um erro e retorna ponteiro NULL.
*/

void lkdlist_addItem(LkdList* list, int value, int* flag);
/*  Adiciona item à lista encadeada com o valor value.
    Se sucesso, flag = 1.
*/

Node* lkdlist_getNode(LkdList* list, int idx, int *flag);
/*  Retorna um node da lista encadeada buscando por índice.
    Se sucesso, flag = 1 e retorna o ponteiro para Node.
    Caso falhe, a flag será um erro e retorna ponteiro NULL.
*/

int* lkdlist_getData(LkdList* list, int idx, int *flag);
/*  Retorna valor de um Node da lista buscando por índice.
    Se sucesso, flag = 1 e retorna o ponteiro para o valor.
    Caso falhe, a flag será um erro e retorna ponteiro NULL.
*/

void lkdlist_removeItem(LkdList* list, int idx, int* flag);
/*  Remove um Node da lista buscando por índice.
    Se sucesso, flag = 1.
    Caso falhe, a flag será um erro.
*/

void lkdlist_printList(LkdList* list, int* flag);
/*  Imprime os valores dos Node da lista.
    Se sucesso, flag = 1.
    Caso falhe, a flag será um erro.
*/

void lkdlist_deleteList(LkdList* list);
/*  Libera a memória dos Node e da LkdList. */

int lkdlist_isOnList(LkdList* list, int value);
/*  Verifica se existe um Node com o mesmo valor value na lista.
    Se existe, retorna 1.
    Se não existe, retorna 0.
*/

int lkdlist_getListSize(LkdList* list);
/*  Retorna o tamanho da lista */

int lkdlist_isEmpty(LkdList* list);

Queue* create(int *flag);
/*Cria a fila*/
//Ok

void insert(Queue*, int, int*);
/*Insere um elemento no fim da fila*/
//Ok

int pop(Queue*, int*);
/*Retira o primeiro elemento da fila*/
//Ok

int len(Queue*,int*);
/*Retorna o tamanho da fila*/
//Ok

int haveElement(Queue*,int,int*);
/*Retorna se um elemento existe na fila*/
//Ok

void invert(Queue*,int*);
/*Inverte os elementos da fila*/

int* getElement(Queue*,int,int*);
/*Retorna o n-ésimo elemento da fila*/
//Ok

void printFila(Queue*, int*);


