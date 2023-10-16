#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

Queue* create(void){
    Queue *q;
    q->l=create_list();
    return q;
}

void insert(Queue *Q,float x,int *erro){
    
}
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
