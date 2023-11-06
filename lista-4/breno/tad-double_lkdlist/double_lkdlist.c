#include "double_lkdlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* dlkdlist_createNode(int* flag){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        *flag = DLKDLIST_ERROR_CANT_ALLOCATE_NODE;
        return NULL;
    }
    newNode->prev=NULL;
    newNode->next=NULL;
    *flag = DLKDLIST_SUCCESS;
    return newNode;
}

DoubleLkdlist* dlkdlist_create(int* flag){
    DoubleLkdlist* newList = (DoubleLkdlist*) malloc(sizeof(DoubleLkdlist));
    if(newList == NULL){
        *flag = DLKDLIST_ERROR_CANT_ALLOCATE_LIST;
        return NULL;
    }
    newList->first=NULL;
    newList->last=NULL;
    newList->ordenated=DLKDLIST_BOOL_FALSE;
    newList->length=0;
    *flag = DLKDLIST_SUCCESS;
    return newList;
}

void dlklist_insertByIndex(DoubleLkdlist* list, int idx, int* flag){
    //ps: index starts at 1
    //idx=1 is the first element
    //idx=length is the last element
    if(idx < 1){
        *flag = DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return;
    }
    else if(idx >= 1 && idx <= list->length){
        // insert after the previous node on the idx
    }
    else if(idx > list->length){
        // insert after end of list
    }
    return;
}

void dlkdlist_ordenateAlpha(DoubleLkdlist* list, int* flag){
    return;
}

void dlkdlist_insertOrdenated(DoubleLkdlist* list, char* data, int* flag){
    return;
}

void dlkdlist_removeByIndex(DoubleLkdlist* list, int idx, int* flag){
    return;
}

int dlkdlist_exist(DoubleLkdlist* list, char* data, int* flag){
    return;
}

int dlkdlist_isEmpty(DoubleLkdlist* list, int* flag){
    *flag = DLKDLIST_SUCCESS;
    if(list->length == 0){
        return DLKDLIST_BOOL_TRUE
    } else{
        return DLKDLIST_BOOL_FALSE;
    }
}

void dlkdlist_printAll(DoubleLkdlist* list, int* flag){
    return;
}

void dlkdlist_printError(DoubleLkdlist* list, int* flag){
    return;
}

void dlkdlist_destroyList(DoubleLkdlist* list, int* flag){
    return;
}