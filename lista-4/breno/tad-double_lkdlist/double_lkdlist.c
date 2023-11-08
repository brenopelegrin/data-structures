#include "double_lkdlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    newList->indexInsertion=DLKDLIST_UNDEFINED;
    newList->length=0;
    *flag = DLKDLIST_SUCCESS;
    return newList;
}

Node* dlkdlist_getNodeByIndex(DoubleLkdlist* list, int idx, int* flag){
    int mean = (int) (list->length/2);
    if(idx < 1 || idx > list->length){
        *flag = DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    else if(idx == mean || idx < mean){
        // here, it will cost the same by iterating through left or right in case idx==mean
        // so i'll choose left-side.
        // if idx < mean, it will cost less if we iterate through left-side
        Node* currNode = list->first;
        for(int i=1; i<idx; i++){
            currNode = currNode->next;
        }
        *flag = DLKDLIST_SUCCESS;
        return currNode;
    }
    else if (idx > mean){
        // here, it will cost less if we iterate through right
        Node* currNode = list->last;
        for(int i=list->length; i>idx; i--){
            currNode = currNode->next;
        }
        *flag = DLKDLIST_SUCCESS;
        return currNode;
    }
    return NULL;
}

void dlklist_insertByIndex(DoubleLkdlist* list, int idx, int* flag){
    //ps: index starts at 1
    //idx = 1 is the first element
    //idx = length is the last element
    if(list->indexInsertion == DLKDLIST_BOOL_FALSE){
        // list is already set for ordenated insertion.
        *flag = DLKDLIST_ERROR_INSERTION_TYPE_NOT_ALLOWED;
        return;
    }
    else if(list->indexInsertion == DLKDLIST_UNDEFINED){
        list->indexInsertion = DLKDLIST_BOOL_TRUE;
    }

    if(idx < 1){
        *flag = DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return;
    }
    else if(idx >= 1 && idx <= list->length){
        // insert after the previous node on the idx
        // TODO: implement
    }
    else if(idx > list->length){
        // insert after end of list
        // TODO: implement
    }
    return;
}

void dlkdlist_ordenateAlpha(DoubleLkdlist* list, int* flag){
    // TODO: implement
    return;
}

void dlkdlist_insertOrdenated(DoubleLkdlist* list, char* data, int* flag){
    // TODO: implement
    if(list->indexInsertion == DLKDLIST_BOOL_TRUE){
        // list is already set for index insertion.
        *flag = DLKDLIST_ERROR_INSERTION_TYPE_NOT_ALLOWED;
        return;
    }
    else if(list->indexInsertion == DLKDLIST_UNDEFINED){
        list->indexInsertion = DLKDLIST_BOOL_FALSE;
    }
    return;
}

void dlkdlist_removeByIndex(DoubleLkdlist* list, int idx, int* flag){
    Node* currentNode = dlkdlist_getNodeByIndex(list, idx, flag);
    if(currentNode == NULL){
        return;
    }
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    free(currentNode);
    *flag = DLKDLIST_SUCCESS;
    return;
}

int dlkdlist_exist(DoubleLkdlist* list, char* data, int* flag){
    Node* currNode = list->first;
    *flag = DLKDLIST_SUCCESS;
    for(int i=0; i<list->length; i++){
        if(strcmp((const char*) currNode->data, (const char*) data)){
            return DLKDLIST_BOOL_TRUE;
        }
        currNode = currNode->next;
    }
    return DLKDLIST_BOOL_FALSE;
}

int dlkdlist_isEmpty(DoubleLkdlist* list, int* flag){
    *flag = DLKDLIST_SUCCESS;
    if(list->length == 0){
        return DLKDLIST_BOOL_TRUE;
    } else{
        return DLKDLIST_BOOL_FALSE;
    }
}

void dlkdlist_printAll(DoubleLkdlist* list, int* flag){
    Node* currNode = list->first;
    for(int i=0; i<list->length; i++){
        printf("%s\n", currNode->data);
        currNode = currNode->next;
    }
    *flag = DLKDLIST_SUCCESS;
    return;
}

void dlkdlist_printFlag(int* flag){
    switch(*flag){
        case DLKDLIST_SUCCESS:
            printf("[OK] operação realizada com sucesso.");
            break;
        case DLKDLIST_ERROR_CANT_ALLOCATE_NODE:
            printf("[!] ERRO: não foi possível alocar memória para criar o Node.");
            break;
        case DLKDLIST_ERROR_CANT_ALLOCATE_LIST:
            printf("[!] ERRO: não foi possível alocar memória para criar a DoubleLkdlist.");
            break;
        case DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS:
            printf("[!] ERRO: o índice está fora dos limites, ou seja, menor que 1 ou maior que o comprimento da lista.");
            break;
        case DLKDLIST_ERROR_INSERTION_TYPE_NOT_ALLOWED:
            printf("[!] ERRO: outro método de inserção para a lista já foi definido, não é possível utilizar esse método.");
        default:
            printf("[?] DESCONHECIDO: código de flag desconhecido.");
            break;
    }
    return;
}

void dlkdlist_destroyList(DoubleLkdlist* list, int* flag){
    Node* currNode = list->first;
    Node* temp = currNode;
    for(int i=0; i<list->length; i++){
        temp = currNode->next;
        free(currNode);
        currNode = temp;
    }
    free(list);
    *flag = DLKDLIST_SUCCESS;
    return;
}