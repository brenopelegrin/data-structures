#include"../tad-linkedlist/lkdlist.h"

#define PROCESS_SUCESS LKDLIST_SUCCESS 
#define CREATION_ERROR 2
#define MEMORY_ALLOCATION_ERROR 3

typedef struct {
    int created;
    LkdList *l;
} Queue;

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
