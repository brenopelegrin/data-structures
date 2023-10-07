#include<lkdlist.h>

typedef struct node{
    unsigned int size;
    void* data;
    struct node* next;
} Node;

Node* createNode();
