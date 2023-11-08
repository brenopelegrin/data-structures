#include"./../tad-my_string/my_string.h"

#define PROCESS_SUCESS STR_PROCESS_SUCESS
#define MEMORY_ALLOCATION_ERROR STR_MEMORY_ALLOCATION_ERROR
#define CREATION_ERROR STR_CREATION_ERROR
#define INVALID_SIZE 4
#define PROCESS_ERROR 5

#define MAX_SIZE_NAME 30

typedef struct node{
    String *name;
    struct node* next;
    struct node* last;
} Node;

typedef struct dlist{
    Node* first;
    Node* last;
    int size;
} dList;

dList* create(int *flag);
/*Cria a lista
Parâmetros:
    int *flag: sinal
Retorna:
    Retorna um ponteiro para a lista
*/

void insert(dList *list,String *name,int pos,int *flag);
/*Insere um nome em determinada posição da lista
Parâmetros:
    dList *list: lista onde será inserido o elemento
    String *name: nome que será inserido
    int pos: a posição onde será inserido o nome
    int *flag: sinal
*/

void sorted_insert(dList *list,String *name,int *flag);
/*Insere um nome na lista de forma alfabética
Parâmetros:
    dList *list: lista ondes será inserido o elemento
    String *name: nome que será inserido
    int *flag: sinal
*/

dList* sorted_list(dList *list,int *flag);
/*Ordena a lista em ordem alfabética
Parâmetros:
    dList *list: lista que será ordenada
    int *flag: sinal
Retorna:
    Lista ordenada
*/

void remove_name(dList *list,String *name,int *flag);
/*Retira um determinado elemento da lista
Parâmetros:
    dList *list: lista de onde será tirado o elemento
    String *name: nome que será retirado
    int *flag: sinal
*/

int exist(dList *list,String *name,int *flag);
/*Mostra se um elemento existe ou não na lista
Parâmetros:
    dList *list: lista de onde o elemento será buscado
    String *name: nome que será procurado
    int *flag: sinal
Retorna:
    Retorna 1 se o elemento existir
    Retorna 0 se o elemento não existir
*/

int isEmpty(dList *list,int *flag);
/*Verifica se a lista está vazia
Parâmetros:
    dList *list: lista que será analisada
    int *flag: sinal
Retorna:
    Retorna 1 se a lista estiver vazia
    Retorna 0 se a lista não estiver vazia
*/

int isSorted(dList *list,int *flag);
/*Verifica se a lista está ordenada
Parâmetros:
    dList *list: lista que será analisada
    int *flag: sinal
Retorna:
    Retorna 1 se a lista estiver ordenada
    Retorna 0 se s lista não estiver ordenada
*/

void printAll(dList *list,int *flag);
/*Imprime todos os elementos da lista
Parâmetros:
    dList *list: lista que será utilizada
    int *flag: sinal
*/

void printAll_inverted(dList *list,int *flag);
/*Imprime todos os elementos da lista ao contrário
Parâmetros:
    dList *list: lista que será utilizada
    int *flag: sinal
*/

void free_list(dList *list,int *flag);
/*Libera a memória utilizada pela lista
Parâmetros:
  dList *list: lista que será limpa
  int *flag: sinal
*/