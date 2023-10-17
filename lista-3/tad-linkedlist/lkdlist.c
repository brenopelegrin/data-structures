#include "lkdlist.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct node {
    double data;
    struct node* next;
} Node;

typedef struct lkdlist {
    Node* first;
    Node* last;
    int size;
} LkdList;

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

void lkdlist_addItem(LkdList* list, double value, int* flag){
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

double* lkdlist_getData(LkdList* list, int idx, int *flag){
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
        printf("%lf\n", currNode->data);
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

int lkdlist_isOnList(LkdList* list, double value){
    return 1;
}
