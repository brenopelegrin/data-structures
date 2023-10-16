#include"./../lkdlist-net.h"

typedef struct {
    List *l;
} Queue;

Queue* create(void);
/*Cria a fila*/

void insert(Queue*,float,int*);
/*Insere um elemento no fim da fila*/

void pop(Queue*,float,int*);
/*Retira o primeiro elemento da fila*/

int len(Queue*,int*);
/*Retorna o tamanho da fila*/

int haveElement(Queue*,float*,int*);
/*Retorna se um elemento existe na fila*/

void invert(Queue*,int*);
/*Inverte os elementos da fila*/

float get(Queue*,int,int*);
/*Retorna o n-ésimo elemento da fila*/
