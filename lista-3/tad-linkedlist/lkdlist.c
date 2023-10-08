#include<lkdlist.h>
#include<stdlib.h>

// Implements double Linked List and Nodes
// Should have functions to add nodes and edit node values.
// Can have functions to index/manipulate linked list by integer indices using ptr array.
typedef struct doublenode{
    double data;
    struct doublenode* next;
} doubleNode;

typedef struct charnode{
    char data;
    struct charnode* next;
} charNode;

typedef struct intnode{
    double data;
    struct intnode* next;
} intNode;

typedef struct doublelkdlist{
    unsigned int size;
    struct doublenode* first;
} doubleLkdList;

doubleNode* lkdlist_double_createNode(int* flag){
    doubleNode* node = (doubleNode*)malloc(sizeof(doubleNode));
    if(node == NULL){
        *flag = LKDLIST_ERROR_CANT_ALLOCATE_NODE;
        return NULL;
    }
    *flag = LKDLIST_SUCCESS;

    return node;
}

doubleLkdList* lkdlist_double_createList(int* flag, int initialSize){
    doubleLkdList* list = (doubleLkdList*)malloc(sizeof(doubleLkdList));
    if(list == NULL){
        *flag = LKDLIST_ERROR_CANT_ALLOCATE_NODE;
        return NULL;
    }

    *flag = LKDLIST_SUCCESS;
    list->size = initialSize;
    
    doubleNode* last_ptr = lkdlist_double_createNode(flag);
    for(int i=0; i<list->size; i++){
        if(i==0){
            list->first = last_ptr;
        } else{
            doubleNode* new_ptr = lkdlist_double_createNode(flag);
            last_ptr->next = new_ptr;
            last_ptr = new_ptr;
        }
    }
    return list;
}
