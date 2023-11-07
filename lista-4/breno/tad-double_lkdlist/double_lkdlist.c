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
    newList->length=0;
    *flag = DLKDLIST_SUCCESS;
    return newList;
}

void dlklist_insertByIndex(DoubleLkdlist* list, int idx, int* flag){
    //ps: index starts at 1
    //idx = 1 is the first element
    //idx = length is the last element
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
    return;
}

void dlkdlist_removeByIndex(DoubleLkdlist* list, int idx, int* flag){
    int mean = (int) (list->length/2);
    if(idx < 1 || idx > list->length){
        *flag = DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS;
        return;
    }
    else if(idx == mean || idx < mean){
        // here, it will cost the same by iterating through left or right in case idx==mean
        // so i'll choose left-side.
        // if idx < mean, it will cost less if we iterate through left-side
        Node* currNode = list->first;
        for(int i=1; i<idx; i++){
            currNode = currNode->next;
        }
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        free(currNode);
        *flag = DLKDLIST_SUCCESS;
        return;
    }
    else if (idx > mean){
        // here, it will cost less if we iterate through right
        Node* currNode = list->last;
        for(int i=list->length; i>idx; i--){
            currNode = currNode->next;
        }
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        free(currNode);
        *flag = DLKDLIST_SUCCESS;
        return;
    }
}

int dlkdlist_exist(DoubleLkdlist* list, char* data, int* flag){
    Node* currNode = list->first;
    *flag = DLKDLIST_SUCCESS;
    for(int i=0; i<list->length; i++){
        if(strcmp((const) currNode->data, (const) data)){
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

void dlkdlist_printFlag(DoubleLkdlist* list, int flag){
    switch(flag){
        case DLKDLIST_SUCCESS:
            printf("SUCCESS: operation successful.");
            break;
        case DLKDLIST_ERROR_CANT_ALLOCATE_NODE:
            printf("ERROR: can't allocate memory for Node creation.");
            break;
        case DLKDLIST_ERROR_CANT_ALLOCATE_LIST:
            printf("ERROR: can't allocate memory for DoubleLkdlist creation.");
            break;
        case DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS:
            printf("ERROR: index is out of bounds, that is, less than 1 or greater than length.");
            break;
        default:
            printf("UNKNOWN: unknown flag.");
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