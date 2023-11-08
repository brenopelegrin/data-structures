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

void insert(dList *list,String *name,int pos,int *flag){
    //O índice começa no 0, como deve ser
    String *S=str_create(MAX_SIZE_NAME,flag);
    for(int i=0;i<name->len;i++){ //Copia 
        S->str[i]=name->str[i];
    }

    if(pos < -1){ //Posição inválida
        *flag=INVALID_SIZE;
        return;
    }
    
    Node *p=(Node*)malloc(sizeof(Node));
    p->name=S;
    p->last=NULL;p->next=NULL;
    
    if(p==NULL){
        *flag=MEMORY_ALLOCATION_ERROR;
        return;
    }

    if(list->size==0){
        list->first=p;
        list->last=p;
    } else if(pos==0){
        p->next=list->first;
        list->first->last=p;
        list->first=p;
    }else if((pos==-1) || (pos>=list->size)){
        p->last=list->last;
        list->last->next=p;
        list->last=p;
    }else{
        Node *aux1=(Node*)malloc(sizeof(Node));
        Node *aux2=(Node*)malloc(sizeof(Node));
        int i;
        aux1=list->first;
        for(i=0;i<pos;i++){
            aux1=aux1->next;
        }
        aux2=aux1->last;
        aux2->next=p;
        p->last=aux2;
        p->next=aux1;
        aux1->last=p;
    }
    list->size += 1;
    *flag=PROCESS_SUCESS;
    return;
}

void sorted_insert(dList *list,String *name,int *flag){
    int i;
    Node *p=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return;
    }

    if(isSorted(list,flag)==0){
        *flag = PROCESS_ERROR;
        return;
    }

    p=list->first;
    for(i=0;i<list->size;i++){
        if(str_comp(p->name,name,flag)<=0){
            break;
        }
        p=p->next;
    }
    insert(list,name,i,flag);
    *flag = PROCESS_SUCESS;
    return;
}

dList* sorted_list(dList *list,int *flag){
    int i,j,aux;
    dList *ordened_list=create(flag);
    //dList *uper_list=create(flag);
    Node *p=(Node*)malloc(sizeof(Node));
    String *min=str_create(MAX_SIZE_NAME,flag);

    aux=list->size;
    //uper_list=upercase_list(list,flag);

    for(j=0;j<aux;j++){
        p=list->first;
        min=list->first->name;
        for(i=0;i<list->size;i++){
            if(str_comp(str_upercase(p->name,flag),str_upercase(min,flag),flag)==1){
                min = p->name;
            }
            p=p->next;
        }
        remove_name(list,min,flag);
        insert(ordened_list,min,-1,flag);
    }
    *flag = PROCESS_SUCESS;
    return ordened_list;
}

void remove_name(dList *list,String *name,int *flag){
    int i;
    Node *p=(Node*)malloc(sizeof(Node));
    Node *aux=(Node*)malloc(sizeof(Node));
    
    if(p==NULL || aux==NULL){
        *flag=MEMORY_ALLOCATION_ERROR;
        return;
    }

    p=list->first;
    for(i=0;i<list->size;i++){ //Não sei porque não funciona com while
        if(str_comp(p->name,name,flag)==0){
            break;
        }
        p=p->next;
    }

    if(i==list->size){
        *flag=PROCESS_ERROR;
        return;
    } else if(list->size==1){
        list->first=NULL;
        list->last=NULL;
        free(p);
    } else if(i==0){
        aux=p->next;
        aux->last=NULL;
        list->first=aux;
        free(p);
    } else if(i==list->size-1){
        aux=p->last;
        aux->next=NULL;
        list->last=aux;
        free(p);
    } else{
        aux=p->last;
        aux->next=p->next;
        aux=p->next;
        aux->last=p->last;
        free(p);
    }
    list->size -= 1;
    *flag=PROCESS_SUCESS;
    return;
}

int exist(dList *list,String *name,int *flag){
    int i,exist;
    Node *p=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return -1;
    }

    exist=0;

    p=list->first;
    for(i=0;i<list->size;i++){
        if(str_comp(p->name,name,flag)==0){
            exist=1;
            break;
        }
        p=p->next;
    }
    *flag = PROCESS_SUCESS;
    return exist;
}

int isEmpty(dList *list,int *flag){

    if(list==NULL){
        *flag=CREATION_ERROR;
        return -1;
    }

    *flag=PROCESS_SUCESS;
    if(list -> size == 0){
        return 1;
    } else{
        return 0;
    }
}

int isSorted(dList *list,int *flag){
    int i,state;
    Node *p=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return -1;
    }

    String *val=str_create(MAX_SIZE_NAME,flag);

    state=1;
    p=list->first;
    val=p->name;
    for(i=0;i<list->size-1;i++){
        if(str_comp(val,p->next->name,flag)==-1){
            state=0;
            break;
        }
        p=p->next;
        val=p->name;
    }
    *flag = PROCESS_SUCESS;
    return state;
}

void printAll(dList *list,int *flag){
    int i;
    Node *p=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return;
    }

    p=list->first;

    for(i=0;i<list->size;i++){
        printf("%s",p->name->str);
        p=p->next;
    }
    *flag = PROCESS_SUCESS;
    return;
}

void printAll_inverted(dList *list,int *flag){
    int i;
    Node *p=(Node*)malloc(sizeof(Node));

    if(p==NULL){
        *flag = MEMORY_ALLOCATION_ERROR;
        return;
    }

    p=list->last;

    for(i=0;i<list->size;i++){
        printf("%s",p->name->str);
        p=p->last;
    }
    *flag = PROCESS_SUCESS;
    return;
}