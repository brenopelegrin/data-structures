#include "lkdlist.h"
#include<stdio.h>
int main(int argc, char* argv[]){
    int flag = 1;
    LkdList* list = lkdlist_createList(&flag);
    lkdlist_addItem(list, 0.05, &flag);
    lkdlist_addItem(list, 0.04, &flag);
    lkdlist_addItem(list, 0.03, &flag);
    lkdlist_printList(list, &flag);
    printf("\n");
    lkdlist_removeItem(list, 0, &flag);
    lkdlist_addItem(list, 0.02, &flag);
    lkdlist_printList(list, &flag);
    lkdlist_deleteList(list);
    printf("\n");
    return 0;
}