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

void lkdlist_addItem(LkdList* list, int value, int* flag);

Node* lkdlist_getNode(LkdList* list, int idx, int *flag);

int* lkdlist_getData(LkdList* list, int idx, int *flag);

void lkdlist_removeItem(LkdList* list, int idx, int* flag);

void lkdlist_printList(LkdList* list, int* flag);

void lkdlist_deleteList(LkdList* list);

int lkdlist_isOnList(LkdList* list, int value);

Queue* create(int *flag);
/*Cria a fila*/
//Ok

void insert(Queue*,int,int*);
/*Insere um elemento no fim da fila*/
//Ok

int* pop(Queue*,int*);
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

