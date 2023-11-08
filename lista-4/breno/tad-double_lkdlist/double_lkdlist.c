#include "double_lkdlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Node* dlkdlist_createNode(char* data, int* flag){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        *flag = DLKDLIST_ERROR_CANT_ALLOCATE_NODE;
        return NULL;
    }
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->data=data;
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

void dlklist_insertByIndex(DoubleLkdlist* list, int idx, char* data, int* flag){
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
    else if(list->length == 0){
        Node* newNode = dlkdlist_createNode(data, flag);
        if(newNode == NULL){
            return;
        }
        list->first = newNode;
        list->last = newNode;
        list->length++;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    else if(idx >= 1 && idx <= list->length){
        // insert after the previous node on the idx
        // TODO: implement
        Node* newNode = dlkdlist_createNode(data, flag);
        if(newNode == NULL){
            return;
        }
        Node* currNode = dlkdlist_getNodeByIndex(list, idx, flag);
        if(currNode == NULL){
            return;
        }
        if(idx == 1){
            newNode->next = list->first;
            list->first = newNode;
            newNode->next->prev = newNode;
            list->length++;
            *flag = DLKDLIST_SUCCESS;
            return;
        }
        newNode->next = currNode;
        newNode->prev = currNode->prev;
        currNode->prev->next = newNode;
        currNode->prev = newNode;
        list->length++;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    else if(idx > list->length){
        Node* newNode = dlkdlist_createNode(data, flag);
        if(newNode == NULL){
            return;
        }
        list->last->next = newNode;
        newNode->prev = list->last;
        list->last = newNode;
        list->length++;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    return;
}

char* toLower(char* s) {
  for(char * p= s; *p; p++){
    *p=tolower(*p);
  }
  return s;
}

int str_comp(char *A, char *B){
    int i, state, lenA, lenB;
    lenA = strlen(A);
    lenB = strlen(B);

    if(A == NULL || B == NULL){
        return;
    }

    if(lenA < lenB){
        state = 1;
        for(i=0;i<lenA;i++){
            if(A[i] > B[i]){
                state = -1;
                break;
            } else if(A[i] < B[i]){
                break;
            }
        }
    } else if(lenA>lenB){
        state = -1;
        for(i=0;i<lenB;i++){
            if(A[i]>B[i]){
                break;
            } else if(A[i]<B[i]){
                state = 1;
                break;
            }
        }
    } else{
        state = 0;
        for(i=0;i<lenB;i++){
            if(A[i]>B[i]){
                state = -1;
                break;
            } else if(A[i]<B[i]){
                state = 1;
                break;
            }
        }
    }
    return state;
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
    
    Node* newNode = dlkdlist_createNode(data, flag);
    if(newNode == NULL){
        return;
    }
    if(list->length == 0){
        newNode->data = toLower(newNode->data);
        list->first = newNode;
        list->last = newNode;
        list->length++;
        *flag = DLKDLIST_SUCCESS;
        return;
    }

    for(int i=0; i<list->length; i++){
        Node* currNode = list->first;
        int state = str_comp(toLower(data), toLower(currNode->data));
        if(state == 0){
            dlkdlist_insertByIndex(list, i, flag);
        }
        else if (state == 1){
            dlkdlist_insertByIndex(list, i, flag);
        }
        else if (state == -1){
            // TODO implement if current string is alphabetically inferior to currNode
            return;
        }
        currNode = currNode->next;
    }
    return;
}

void dlkdlist_removeByIndex(DoubleLkdlist* list, int idx, int* flag){
    if(idx < 1 || idx > list->length){
        *flag = DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return;
    }

    Node* currentNode = dlkdlist_getNodeByIndex(list, idx, flag);
    if(currentNode == NULL){
        return;
    }

    if(idx == 1){
        currentNode->next->prev = NULL;
        list->first = currentNode->next;
        free(currentNode);
        list->length--;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    else if(idx == list->length){
        currentNode->prev->next = NULL;
        list->last = currentNode->prev;
        free(currentNode);
        list->length--;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    else if(idx > 1 && idx < list->length){
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        free(currentNode);
        list->length--;
        *flag = DLKDLIST_SUCCESS;
        return;
    }
}

int dlkdlist_exist(DoubleLkdlist* list, char* data, int* flag){
    Node* currNode = list->first;
    *flag = DLKDLIST_SUCCESS;
    for(int i=0; i<list->length; i++){
        if(strcmp(currNode->data, data) == 0){
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
        if(currNode->next == NULL){
            break;
        }
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
            break;
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