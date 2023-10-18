#include "queuelkdlist.h"
#include<stdlib.h>
#include<stdio.h>

LkdList* lkdlist_createList(int *flag){
    LkdList* list = (LkdList*) malloc(sizeof(LkdList));
    if(list == NULL){
        *flag = LKDLIST_ERROR_CANT_ALLOCATE_LIST;
        return NULL;
    }
    
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

void lkdlist_addItem(LkdList* list, int value, int* flag){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL){
        *flag = LKDLIST_ERROR_CANT_ALLOCATE_NODE;
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    
    if(list->size == 0){
        list->first = newNode;
        list->last = newNode;
    } else{
        list->last->next = newNode;
        list->last = newNode;
    }

    list->size++;
    *flag = LKDLIST_SUCCESS;
    return;
}

Node* lkdlist_getNode(LkdList* list, int idx, int *flag){
    // idx must be in [0, size]
    // if size == 0, throw error

    // this if also comprehends the case where list->size == 0,
    // because when list->size == 0; idx = 0 comprehends idx = list->size,
    // which throws out of bounds error.
    if(idx < 0 || idx >= list->size){
        *flag = LKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return NULL;
    } else{
        Node* currNode = list->first;
        for(int i=0; i<idx; i++){
            //currNode = nextNode
            currNode = currNode->next;
        }
        return currNode;
    }
}

int* lkdlist_getData(LkdList* list, int idx, int *flag){
    Node* currNode = lkdlist_getNode(list, idx, flag);
    if(currNode == NULL){
        return NULL;
    }
    return &currNode->data;
}

void lkdlist_removeItem(LkdList* list, int idx, int* flag){
    // idx must be in [0, size]
    // if size == 0, throw error

    // this if also comprehends the case where list->size == 0,
    // because when list->size == 0; idx = 0 comprehends idx = list->size,
    // which throws out of bounds error.
    if(idx < 0 || idx >= list->size){
        *flag = LKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return;
    }
    if(idx > 0){
        Node* prevNode = lkdlist_getNode(list, idx-1, flag);
        if(prevNode == NULL){
            return;
        }
        Node* toBeFreed = prevNode->next;
        prevNode->next = toBeFreed->next;
        free(toBeFreed);
        list->size--;
        *flag = LKDLIST_SUCCESS;
        return;
    } else{
        // idx == 0
        Node* currNode = lkdlist_getNode(list, idx, flag);
        if(currNode == NULL){
            return;
        }
        list->first = currNode->next;
        free(currNode);
        list->size--;
        *flag = LKDLIST_SUCCESS;
        return;
    }
}

void lkdlist_printList(LkdList* list, int* flag){
    for(int i=0; i<list->size; i++){
        Node* currNode = lkdlist_getNode(list, i, flag);
        printf("%d\n", currNode->data);
    }
}

void lkdlist_deleteList(LkdList* list){
    Node* currNode = list->first;
    for(int i=0; i<list->size; i++){
        if(currNode->next != NULL){
            Node* prevNode = currNode;
            currNode = currNode->next;
            free(prevNode);
        }
    }
    free(currNode);
    free(list);
    return;
}

void lkdlist_reverseList(LkdList* list){
    return;
}

int lkdlist_isOnList(LkdList* list, int value){
    Node* currNode = list->first;
    for(int i=0; i<list->size; i++){
        if(currNode->data == value){
            return 1;
        }
        if(currNode->next == NULL){
            break;
        }
        currNode = currNode->next;
    }
    return 0;
}

int lkdlist_getListSize(LkdList* list){
    return list->size;
}

int lkdlist_isEmpty(LkdList* list){
    if(list->size == 0){
        return 1;
    } else{
        return 0;
    }
}


// Below we have the Queue implementation

Queue* create(int *flag){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    if(Q==NULL){
        *flag=MEMORY_ALLOCATION_ERROR;
        return NULL;
    }
    Q->created = 1;
    Q->l = (LkdList*) lkdlist_createList(flag);
    return Q;
}


void insert(Queue *Q, int ele, int *flag){
    if(Q->created!=1){
        *flag=CREATION_ERROR;
        return;
    }
    lkdlist_addItem(Q->l, ele, flag);
    return;
}


int* pop(Queue *Q,int *flag){
    int *ele=(int*)malloc(sizeof(int));

    ele = lkdlist_getData(Q->l,0,flag);
    lkdlist_removeItem(Q->l,0,flag);
    return ele;
}


int len(Queue *Q,int *flag){
    if(Q->created != 1){
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

