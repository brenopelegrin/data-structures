#include<stdlib.h>
#include<stdio.h>
#include"double_list.h"

dList* create(int *flag){
    dList *list = (dList*)malloc(sizeof(dList));
    if(list==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return NULL;
    }
    *flag = PROCESS_SUCESS;
    list -> first = NULL;
    list -> last = NULL;
    list -> size = 0;
    return list;
}

void insert(dList *list,char *name[],int pos,int *flag){
    return;
}

int isEmpty(dList *list,int *flag){

    if(list==NULL){
        *flag=MEMORY_ALLOCATION_ERROR; //Criar um erro CREATION_ERROR ?
        return -1;
    }

    if(list -> size == 0){
        *flag=PROCESS_SUCESS;
        return 1;
    } else{
        *flag=PROCESS_SUCESS;
        return 0;
    }
}