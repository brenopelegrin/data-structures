#define LKDLIST_ERROR_CANT_ALLOCATE_LIST -1
#define LKDLIST_ERROR_CANT_ALLOCATE_NODE -2
#define LKDLIST_ERROR_INDEX_OUT_OF_BOUNDS -3
#define LKDLIST_SUCCESS 1

typedef struct node Node;

typedef struct lkdlist LkdList;

LkdList* lkdlist_createList(int *flag);

void lkdlist_addItem(LkdList* list, double value, int* flag);

Node* lkdlist_getNode(LkdList* list, int idx, int *flag);

double* lkdlist_getData(LkdList* list, int idx, int *flag);

void lkdlist_removeItem(LkdList* list, int idx, int* flag);

void lkdlist_printList(LkdList* list, int* flag);

void lkdlist_deleteList(LkdList* list);

int lkdlist_isOnList(LkdList* list, double value);
