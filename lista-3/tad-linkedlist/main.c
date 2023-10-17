#include "lkdlist.h"
#include<stdio.h>
int main(int argc, char* argv[]){
    int flag = 1;
    LkdList* list = lkdlist_createList(&flag);
    lkdlist_addItem(list, 5, &flag);
    lkdlist_addItem(list, 4, &flag);
    lkdlist_addItem(list, 3, &flag);
    lkdlist_printList(list, &flag);
    printf("\n");
    lkdlist_removeItem(list, 0, &flag);
    lkdlist_addItem(list, 2, &flag);
    lkdlist_printList(list, &flag);
    lkdlist_deleteList(list);
    printf("\n");
    return 0;
}