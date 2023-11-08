#include<stdlib.h>
#include<stdio.h>
#include"tad-double_list/double_list.h"

//Testar mais alguns casos
//Ajustar mensagens de erro e de sucesso
//Talvez colocar mais algumas operações
    //Queria colocar operações pra capitalizar e deixar lower ou uper, mas não sei se é muito trampo
//Tive alguns problemas com a função str_isUpercase com os casos Zé e MANé onde ela retornou TRUE

void recebe_nome(String *S);
/*Recebe do terminal uma string para S*/

void print_tarefas(void);
/*Imprime as operações disponíveis*/

void recebe_op(int *op);
/*Recebe do terminal um número para a operação op*/

void sucess_message(void);
/*Imprime uma mensagem de sucesso*/

int main(){
    int op,running,flag;
    int state,pos;
    char option;

    dList *l=create(&flag);
    String *S=str_create(MAX_SIZE_NAME,&flag);

    running = 1;

    printf("Seja Bem vindo ao manipulador de lista duplamente encadeada de nomes!\n\n");
    print_tarefas();

    while(running){

    recebe_op(&op);
    printf("\n");

    switch (op){
    case -1:
        print_tarefas();
        break;
    case 0:
        running = 0;
        break;
    case 1:
        printf("Digite o nome que deseja inserir:\n");
        recebe_nome(S);
        printf("\nDigite a posição em que deseja inserir: ");
        scanf("%d",&pos);
        getchar();
        insert(l,S,pos,&flag);
        if(flag==PROCESS_SUCESS){
            sucess_message();
        }
        break;
    case 2:
        printf("Digite o nome que deseja inserir:\n");
        recebe_nome(S);
        sorted_insert(l,S,&flag);
        if(flag==PROCESS_SUCESS){
            sucess_message();
        } else if(isSorted(l,&flag)==0){
            printf("Parece que a lista não está ordenada, logo não é possível inserir algo ordenadamente nela\n");
            printf("Deseja ordenar a lista e então inserir o nome? [S,N]\n");
            option=getchar();
            if(option=='S'){
                l=sorted_list(l,&flag);
                sorted_insert(l,S,&flag);
                if(flag==PROCESS_SUCESS){
                    sucess_message();
                }
            } else{
                printf("Encerrando operacação\n");
            }
        }
        break;
    case 3:
        printf("Digite o nome que deseja verificar se está na lista:\n");
        recebe_nome(S);
        state = exist(l,S,&flag);
        if(flag==PROCESS_SUCESS){
            if(state){
                printf("O nome está na lista\n");
            } else{
                printf("O nome não está na lista\n");
            }
        }
        break;
    case 4:
        printf("Insira o nome que deseja remover:\n");
        recebe_nome(S);
        remove_name(l,S,&flag);
        if(flag==PROCESS_SUCESS){
            sucess_message();
        }
        break;
    case 5:
        l = sorted_list(l,&flag);
        if(flag==PROCESS_SUCESS){
            sucess_message();
        }
        break;
    case 6:
        state = isSorted(l,&flag);
        if(state){
            printf("A lista está ordenada\n");
        } else{
            printf("A lista não está ordenada\n");
        }
        break;
    case 7:
        printAll(l,&flag);
        break;
    case 8:
        printAll_inverted(l,&flag);
        break;
    case 9:
        printf("A lista possui %d elementos\n",l->size);
        break;
    default:
        printf("Parece que você inseriu um número inválido, tente novamente!\n");
        break;
    }
    printf("\n");
    }
    printf("Obrigado por utilizar nossos serviços!\n");
    return(0);
}

void print_tarefas(void){
    printf("1 - Inserir nome por índice\n");
    printf("2 - Inserir nome ordenadamente (ordem alfabética)\n");
    printf("3 - Verificar se nome existe\n");
    printf("4 - Remover nome\n");
    printf("5 - Ordenar lista\n");
    printf("6 - Verificar se a lista está ordenada\n");
    printf("7 - Imprimir Elementos\n");
    printf("8 - Imprimir Elementos na ordem invertida\n");
    printf("9 - Imprimir o tamanho da lista\n");
    printf("0 - Sair\n");
    return;
}

void recebe_nome(String *S){
    fgets(S->str,MAX_SIZE_NAME*sizeof(char),stdin);
    return;
}

void recebe_op(int *op){
    printf("Digite o número associado à operação desejada (Digite -1 para ver as operações novamente): ");
    scanf("%d",op);
    getchar();
    return;
}

void sucess_message(void){
    printf("Operação realizada com sucesso\n");
    return;
}