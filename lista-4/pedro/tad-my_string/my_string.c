#include<stdlib.h>
#include<stdio.h>
#include"my_string.h"

String* str_create(int size,int *flag){
    String *str=(String*)malloc(sizeof(String));
    if(str==NULL){
        *flag=STR_MEMORY_ALLOCATION_ERROR;
        return NULL;
    }

    str->len=size;
    str->str=(char*)malloc(size*sizeof(char));
    *flag=STR_PROCESS_SUCESS;
    return str;
}

int str_comp(String *A,String *B,int *flag){
    int i,state;

    if(A==NULL || B==NULL){
        *flag = STR_CREATION_ERROR;
        return -2;
    }

    if(A->len<B->len){
        state = 1;
        for(i=0;i<A->len;i++){
            if(A->str[i]>B->str[i]){
                state = -1;
                break;
            } else if(A->str[i]<B->str[i]){
                break;
            }
        }
    } else if(A->len>B->len){
        state = -1;
        for(i=0;i<B->len;i++){
            if(A->str[i]>B->str[i]){
                break;
            } else if(A->str[i]<B->str[i]){
                state = 1;
                break;
            }
        }
    } else{
        state = 0;
        for(i=0;i<B->len;i++){
            if(A->str[i]>B->str[i]){
                state = -1;
                break;
            } else if(A->str[i]<B->str[i]){
                state = 1;
                break;
            }
        }
    }
    *flag = STR_PROCESS_SUCESS;
    return state;
}

String* str_lowercase(String *A,int *flag){
    int i;
    String *B=str_create(A->len,flag);

    if(B==NULL){
        *flag = STR_MEMORY_ALLOCATION_ERROR;
        return NULL;
    }

    char *b=(char*)malloc(B->len*sizeof(char));


    for(i=0;i<A->len;i++){
        if(A->str[i] <= 'Z'){
            b[i] = A->str[i] | 0x20;
        }
    }
    B->str=b;
    *flag = STR_PROCESS_SUCESS;
    return B;
}

String* str_upercase(String *A,int *flag){
    int i;
    String *B=str_create(A->len,flag);

    if(B==NULL){
        *flag = STR_MEMORY_ALLOCATION_ERROR;
        return NULL;
    }

    char *b=(char*)malloc(B->len*sizeof(char));
    for(i=0;i<A->len;i++){
        if(A->str[i] >= 'a' && A->str[i] <= 'z'){
            b[i] = A->str[i] & 0xDF;
        } else if(A->str[i]=='\n'){
            b[i] = '\n';
        /*} else if(A->str[i]=="é"){
            b[i] = "É";
        } else if(A->str[i]=='ã'){
            b[i] = 'Ã';
        } else if(A->str[i]=='á'){
            b[i] = 'Á';*/
        } else{
            b[i] = A->str[i];
        }
    }
    //b[i-2]='\n';
    B->str=b;
    *flag = STR_PROCESS_SUCESS;
    return B;
}

int str_isLowercase(String *A,int *flag){
    int i;

    for(i=0;i<A->len-1;i++){
        if(A->str[i]>='A' && A->str[i]<='Z'){
            *flag = STR_PROCESS_SUCESS;
            return 0;
        }
    }
    *flag = STR_PROCESS_SUCESS;
    return 1;
}

int str_isUpercase(String *A,int *flag){
    int i;

    for(i=0;i<A->len-1;i++){
        if(A->str[i]>='a' && A->str[i]<='z'){
            *flag = STR_PROCESS_SUCESS;
            return 0;
        }
    }
    *flag = STR_PROCESS_SUCESS;
    return 1;
}

int str_isCaptizalized(String *A,int *flag){
    int i;

    if(A->str[0]>='a' && A->str[0]<='z'){
        *flag = STR_PROCESS_SUCESS;
        return 0;
    }
    for(i=1;i<A->len-1;i++){
        if(A->str[i]>='A' && A->str[i]<='Z'){
            *flag = STR_PROCESS_SUCESS;
            return 0;
        }
    }
    *flag = STR_PROCESS_SUCESS;
    return 1;
}