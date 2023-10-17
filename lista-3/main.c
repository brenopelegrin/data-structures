#include<stdlib.h>
#include<stdio.h>
#include"tad-queue/queue.h"

int main(int argc, char *argv[]){

    int command,flag,ele,n;
    Queue *Q;
    /*Criar uma fila*/
    command=-1;
    Q=create(&flag);

    printf("Manipulador de Fila\u00AE\n");
    printf("---------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Retirar elemento\n");
    printf("3 - Obter elemento\n");
    printf("4 - Imprimir tamanho da fila\n");
    printf("5 - Verificar se fila está vazia\n");
    printf("6 - Verificar se elemento existe na fila\n");
    printf("7 - Imprimir elemento em determinada posição\n");
    printf("0 - Sair\n");

    while(command!=0){

        printf("Insira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)\n");
        scanf("%d",&command);
        printf("\n");

        switch (command)
        {
        case -1:
        printf("1 - Inserir elemento\n");
        printf("2 - Retirar elemento\n");
        printf("3 - Obter elemento\n");
        printf("4 - Imprimir tamanho da fila\n");
        printf("5 - Verificar se fila está vazia\n");
        printf("6 - Verificar se elemento existe na fila\n");
        printf("7 - Imprimir elemento em determinada posição\n");
        printf("0 - Sair\n");
            break;
        case 0:
            printf("Obrigado por utilizar nossos serviços :)\n");
            break;
        case 1:
            printf("Insira o valor que será colocado na fila:\n");
            scanf("%d",&ele);
            insert(Q,ele,&flag);
            if(flag==PROCESS_SUCESS) 
            printf("\nNúmero inserido com sucesso\n");
            break;
        case 2:
            printf("Retirando primeiro elemento\n");
            pop(Q,&flag);
            if(flag==PROCESS_SUCESS)
            printf("Elemento retirado com sucesso\n");
            break;
        case 3:
            int *p;
            printf("Capturando o primeiro elemento\n");
            p=pop(Q,&flag);
            if(flag==PROCESS_SUCESS)
            printf("Elemento capturado com sucesso, seu valor é %d\n",*p);
            //Talvez isso não funcione
            break;
        case 4:
            printf("O tamanho da fila é: %d\n",len(Q,&flag));
            break;
        case 5:
            if(len(Q,&flag)){
                printf("A fila não está vazia\n");
            } else{
                printf("A fila está vazia\n");
            }
            break;
        case 6:
            printf("Insira o elemento que você deseja descobrir se está na lista: ");
            scanf("%d",&ele);
            if((haveElement(Q,ele,&flag)) && (flag==PROCESS_SUCESS)){
                printf("\nO elemento %d está na fila\n",ele);
            } else if(flag==PROCESS_SUCESS){
                printf("\nO elemento %d não está na fila\n",ele);
            } else{
                printf("\nOcorreu um erro inesperado\n");
            }
            break;
        case 7:
            printf("Insira uma posição para encontrar o elemento: ");
            scanf("%d",&n);
            if(n>len(Q,&flag)-1){
                printf("\nVocê inseriu um tamanho inválido burro\n");
                break;
            }
            break;
        default:
            printf("Parece que você inseriu um número inválido :( , insira novamente\n");
            break;
        }

    }

    return 0;
}