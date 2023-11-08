#include "tad-double_lkdlist/double_lkdlist.h"
#include <stdio.h>
#include <stdlib.h>

#define STRING_START_SIZE 10

void printChoices(){
    printf("\nEscolha uma das opções:\n");
    printf("\nOpção\tDescrição\n");
    printf("-----\t---------\n");
    printf("-1\tSair\n");
    printf("0\tRepetir as opções\n");
    printf("1\tImprimir a lista\n");
    printf("2\tInserir elemento por índice\n");
    printf("3\tInserir elemento por ordem alfabética\n");
    printf("4\tRemover elemento por índice\n");
    printf("5\tVerificar se a lista está vazia\n");
    printf("6\tVerificar se um elemento está na lista\n");
    return;
}

char* readString(){
    char* string = NULL;
    int i = 0;
    unsigned int size = 0;
    unsigned int charBuffer = 0;
    getchar(); // this avoids past \n from choice
    printf("> Digite a string a ser inserida: ");
    while ((charBuffer=getchar()) != EOF && charBuffer != '\n') {
        if (i + 1 >= size)
        {
            size = size * 2 + 1;
            //Reallocates to fit string in memory
            string = realloc(string, sizeof(char)*size);
            if(!string){
                //Realloc failed
                printf("Erro: memória indisponível para realloc");
                exit(EXIT_FAILURE);
            }
        }
        string[i] = charBuffer;
        i++;
    }
    return string;
}

void checkError(int* flag){
    if(*flag != DLKDLIST_SUCCESS){
        printf("\n");
        dlkdlist_printFlag(flag);
        printf("\n");
    }
    return;
}

int main(int argc, char* argv[]){
    int flag = 0;
    int choice = 0;
    char* string;
    DoubleLkdlist* list = dlkdlist_create(&flag);

    printf("Bem-vindo(a) ao TAD de lista duplamente encadeada.\n");
    printf("\nOBSERVAÇÔES:\n");
    printf("- Os tipos de dado são strings.\n");
    printf("- Na ordenação, maíusculas são ignoradas.\n");
    printf("- Após selecionar um tipo de ordenção, você\n  deverá usá-la até o final.\n");
    printf("- Os índices começam em 1.\n");
    printf("---------------------------------------------------\n");
    printChoices();
    while(choice != -1){
        printf("\n> Escolha uma opção: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case -1:
                dlkdlist_destroyList(list, &flag);
                checkError(&flag);
                break;
            case 0:
                printChoices();
                break;
            case 1:
                printf("Lista impressa:\n");
                dlkdlist_printAll(list, &flag);
                checkError(&flag);
                break;
            case 2:
                int index = -1;
                printf("> Digite o índice: ");
                scanf("%d", &index);

                string = readString();
                printf("String lida: %s\n", string);

                dlklist_insertByIndex(list, index, string, &flag);
                checkError(&flag);
                break;
            case 3:
                string = readString();
                printf("String lida: %s\n", string);
                dlkdlist_insertOrdenated(list, string, &flag);
                checkError(&flag);
                break;
            default:
                printf("\n[!] ERRO: opção inválida!");
                printChoices();
                break;
        }
    }
    return 0;
}