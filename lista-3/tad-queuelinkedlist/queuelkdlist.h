// Definições da lista encadeada
#define LKDLIST_ERROR_CANT_ALLOCATE_LIST -1
#define LKDLIST_ERROR_CANT_ALLOCATE_NODE -2

#define LKDLIST_ERROR_INDEX_OUT_OF_BOUNDS -3
/*  Nota: os índices da lista encadeada começam em 0
    e vão até size-1, seguindo a convenção do C.
*/

#define LKDLIST_ERROR_NOT_IMPLEMENTED 0
#define LKDLIST_SUCCESS 1

// Definições da fila
#define PROCESS_SUCESS LKDLIST_SUCCESS 
#define CREATION_ERROR 2
#define MEMORY_ALLOCATION_ERROR 3

// Structs da lista encadeada
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct lkdlist {
    Node* first;
    Node* last;
    int size;
} LkdList;

// Structs da fila
typedef struct {
    int created;
    LkdList *l;
} Queue;

// Declaração das funções da lista

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
/*  Verifica se a lista está vazia.
    Se vazia, retorna 1.
    Se não vazia, retorna 0.
*/

LkdList* lkdlist_createReversedList(LkdList* old, int* flag);
/*  Cria uma outra lista, que será a inversa da lista antiga.
    Recomenda-se que, após retornada a nova lista, o usuário
    delete a lista antiga e utilize a nova.
    
    Exemplo:
        int flag;
        LkdList* old = lkdlist_createList(flag);
        lkdlist_addItem(old, 1, flag);
        lkdlist_addItem(old, 2, flag);
        lkdlist_addItem(old, 3, flag);
        LkdList* reversed = lkdlist_createReversedList(old, flag);
        lkdlist_deleteList(old);
        old = reversed;
*/

void lkdlist_setData(LkdList* list, int idx, int value, int *flag);
/*  Altera valor de um Node da lista para value buscando por índice.
    Se sucesso, flag = 1.
    Caso falhe, a flag será um erro.
*/

// Declaração das funções da fila
Queue* create(int *flag);
/* Cria a fila utilizando lista encadeada.
    Se sucesso, flag = 1.
*/

void insert(Queue*, int, int*);
/* Insere um elemento no fim da fila.
    Se sucesso, flag = 1.
*/

int pop(Queue*, int*);
/* Retira o primeiro elemento da fila.
    Se sucesso, flag = 1.
*/

int len(Queue*,int*);
/* Retorna o tamanho da fila.
    Se sucesso, flag = 1.
*/

int haveElement(Queue*,int,int*);
/* Retorna se um elemento existe na fila.
    Se sucesso, flag = 1.
*/

void invert(Queue*,int*);
/* Inverte os elementos da fila.
    Se sucesso, flag = 1.
*/

int* getElement(Queue*,int,int*);
/* Retorna o n-ésimo elemento da fila.
    Se sucesso, flag = 1.
*/

void printFila(Queue*, int*);
/* Imprime todos os elementos da fila.
    Se sucesso, flag = 1.
*/


