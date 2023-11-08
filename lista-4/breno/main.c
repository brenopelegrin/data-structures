#include "tad-double_lkdlist/double_lkdlist.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("\n> Opção escolhida: ");
    return;
}

int main(int argc, char* argv[]){
    int flag = 0;
    int choice = 0;
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
        scanf("%d", &choice);
        switch(choice){
            case -1:
                dlkdlist_destroyList(list, &flag);
                break;
            case 0:
                printChoices();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                printf("ERRO: opção inválida!\n");
                break;
        }
    }
    return 0;
}