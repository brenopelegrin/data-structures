/*
    Double Linked List Header File
*/

// Error codes definitions
#define DLKDLIST_SUCCESS 1
#define DLKDLIST_ERROR_CANT_ALLOCATE_NODE -2
#define DLKDLIST_ERROR_CANT_ALLOCATE_LIST -3
#define DLKDLIST_ERROR_INDEX_OUT_OF_BOUNDS -4
#define DLKDLIST_ERROR_INSERTION_TYPE_NOT_ALLOWED -5

// Boolean definitions
#define DLKDLIST_BOOL_TRUE 1
#define DLKDLIST_BOOL_FALSE 0

// Miscelaneous definitions
#define DLKDLIST_UNDEFINED -1

/*
    Double Linked List Node Struct
    The node stores a string as data.
*/
typedef struct node{
    struct node* next;
    struct node* prev;
    char* data;
} Node;

/*
    Double Linked List Struct
    Here, the 'ordenated' flag and the 'length' counterallows to 
    optimize insertions and deletions.

    indexInsertion flag selects between index insertion or ordenated
    insertion. If true, insert by index, if false, by ordenated.
    Defaults to DLKDLIST_UNDEFINED.
*/
typedef struct double_lkdlist{
    Node* first;
    Node* last;
    int ordenated;
    int indexInsertion;
    int length;
} DoubleLkdlist;

Node* dlkdlist_createNode(char* data, int* flag);
DoubleLkdlist* dlkdlist_create(int* flag);
void dlklist_insertByIndex(DoubleLkdlist* list, int idx, char* data, int* flag);
void dlkdlist_ordenateAlpha(DoubleLkdlist* list, int* flag);
void dlkdlist_insertOrdenated(DoubleLkdlist* list, char* data, int* flag);
void dlkdlist_removeByIndex(DoubleLkdlist* list, int idx, int* flag);
int dlkdlist_exist(DoubleLkdlist* list, char* data, int* flag);
int dlkdlist_isEmpty(DoubleLkdlist* list, int* flag);
void dlkdlist_printAll(DoubleLkdlist* list, int* flag);
void dlkdlist_printError(DoubleLkdlist* list, int* flag);
void dlkdlist_destroyList(DoubleLkdlist* list, int* flag);
void dlkdlist_printFlag(int* flag);