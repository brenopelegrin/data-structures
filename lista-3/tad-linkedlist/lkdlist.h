// Error codes

#define LKDLIST_ERROR_CANT_ALLOCATE_NODE -1
#define LKDLIST_SUCCESS 1

typedef struct doublenode doubleNode;

typedef struct doublelkdlist doubleLkdList;

doubleNode* lkdlist_double_createNode(int* flag);

doubleLkdList* lkdlist_double_createList(int* flag, int initialSize);
