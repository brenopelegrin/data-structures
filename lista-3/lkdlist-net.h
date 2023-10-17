//Implementação que eu peguei da internet só pra ver qual é, pode apagar depois

typedef struct node {
    void* data;
    struct node* next;
} Node;
 
typedef struct list {
    int size;
    Node* head;
} List;

List* create_list();
void add_to_list(List* list, void* data);
void* remove_from_list(List* list);
void free_list(List* list);