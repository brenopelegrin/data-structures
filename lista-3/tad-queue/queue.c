#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

Queue* create(int *flag){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    if(Q==NULL){
        *flag=MEMORY_ALLOCATION_ERROR;
        return NULL;
    }
    Q->created=1;
    Q->l=(LkdList*)malloc(sizeof(LkdList));
    /*Tá dando um tipo incompleto no malloc, quando eu defino o struct no header ele some, isso é uma boa prática?*/
    Q->l = (LkdList*) lkdlist_createList(flag);
    return Q;
}


void insert(Queue *Q,int ele,int *flag){
    if(Q->created!=1){
        *flag=CREATION_ERROR;
        return;
    }
    lkdlist_addItem(Q->l,ele,flag);
    return;
}


int* pop(Queue *Q,int *flag){

    int *ele=(int*)malloc(sizeof(int));

    ele=lkdlist_getData(Q->l,0,flag);
    lkdlist_removeItem(Q->l,0,flag);
    return ele;
}


int len(Queue *Q,int *flag){
    if(Q->created!=1){
        *flag=CREATION_ERROR;
        return -1;
    } else{
        *flag=PROCESS_SUCESS;
        return Q->l->size;
    }
}


int haveElement(Queue *Q,int ele,int *flag){

    Node *p;

    if(Q->created!=1){
        *flag=CREATION_ERROR;
        return -1;
    }
    if(len(Q,flag)==0){
        *flag=PROCESS_SUCESS;
        return 0;
    }
    p=lkdlist_getNode(Q->l,0,flag);
    //Com a lista vazia ele não consegue pegar nem o primeiro node
    if(*flag!=LKDLIST_SUCCESS)
    return -1;
    *flag=PROCESS_SUCESS;
    while (p!=NULL){
        if(p->data==ele){
            return 1;
        }
        p=p->next;
    }
    return 0;
}


void invert(Queue*,int*){

}


int* getElement(Queue *Q,int n,int *flag){

    return lkdlist_getData(Q->l,n,flag);

}
