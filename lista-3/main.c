/* Alunos participantes:
 * Breno Henrique Pelegrin da Silva - 13687303
 * Pedro Martins Oliveira - 13696213
 */

#include<stdlib.h>
#include<stdio.h>
#include"tad-queuelinkedlist/queuelkdlist.h"

void printOperacoes(){
    printf("Manipulador de Fila de inteiros\u00AE\n");
    printf("------------------------\n");
    printf("1   - Inserir elemento no final (push)\n");
    printf("2   - Inserir multiplos elementos no final\n");
    printf("3   - Deletar elemento no topo\n");
    printf("4   - Obter elemento no topo (pop)\n");
    printf("5   - Imprimir tamanho atual da fila\n");
    printf("6   - Verificar se fila está vazia\n");
    printf("7   - Verificar se elemento existe na fila\n");
    printf("8   - Imprimir elemento em determinado índice\n");
    printf("9   - Imprimir fila do primeiro ao último elemento\n");
    printf("10  - Inverter fila\n");
    printf("11  - Esvaziar fila\n");
    printf("0   - Sair\n");
    return;
}

int main(int argc, char *argv[]){
    int command, flag;
    int ele, n, *pi;

    int valor;
    pi = NULL;
    
    command=-1;

    /*Criar uma fila*/
    Queue* Q = create(&flag);
    if(Q == NULL){
        printf("Erro: Não foi possível criar a fila.");
        return 0;
    }

    printOperacoes();
    while(command != 0){
        printf("\nInsira o número da operação que deseja realizar: (Insira -1 para imprimir as instruções novamente)\n> ");
        scanf("%d", &command);
        printf("\n");
        switch (command){
            case -1:
                printOperacoes();
                break;
            case 0:
                deleteQueue(Q);
                printf("Obrigado por utilizar nossos serviços!\n");
                break;
            case 1:
                printf("Insira o valor que será colocado na fila:\n");
                scanf("%d", &ele);
                insert(Q, ele, &flag);
                if(flag == PROCESS_SUCESS){
                    printf("\nNúmero inserido com sucesso!\n");
                }
                else{
                    printf("Ocorreu um problema inesperado\n");
                }
                break;
            case 2:
                printf("Quantos números você deseja inserir? ");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    scanf("%d",&ele);
                    insert(Q,ele,&flag);
                }
                if(flag==PROCESS_SUCESS){
                    printf("\nNúmeros inseridos com sucesso!\n");
                }else{
                    printf("\nOcorreu um erro inesperado\n");
                }
                break;
            case 3:
                if(len(Q,&flag)==0){
                    printf("Não é possível tirar um elemento de uma fila vazia\n");
                    break;
                }
                pop(Q, &flag);
                if(flag == PROCESS_SUCESS){
                    printf("Elemento retirado com sucesso!\n");
                    break;
                }
                else{
                    printf("Ocorreu um problema inesperado\n");
                    break;
                }
            case 4:
                if(len(Q, &flag)==0){
                    printf("Não é possível obter um elemento de uma fila vazia\n");
                    break;
                }
                valor = pop(Q, &flag);
                if(flag == PROCESS_SUCESS){
                    printf("Elemento capturado com sucesso, seu valor é %d\n",valor);
                    break;
                }
                else{
                    printf("Ocorreu um problema inesperado\n");
                    break;
                }
            case 5:
                ele=len(Q,&flag);
                if(flag==PROCESS_SUCESS){
                    printf("O tamanho da fila é: %d\n",ele);
                }
                else{
                    printf("Ocorreu um problema inesperado\n");
                }
                break;
            case 6:
                if((len(Q,&flag)) && flag==PROCESS_SUCESS){
                    printf("A fila não está vazia\n");
                } else if(flag==PROCESS_SUCESS){
                    printf("A fila está vazia\n");
                } else{
                    printf("%d",flag);
                    printf("Ocorreu um problema inesperado\n");
                }
                break;
            case 7:
                printf("Insira o elemento que você deseja descobrir se está na fila: ");
                scanf("%d",&ele);
                if((haveElement(Q,ele,&flag)) && (flag == PROCESS_SUCESS)){
                    printf("\nO elemento %d está na fila\n",ele);
                } else if(flag==PROCESS_SUCESS){
                    printf("\nO elemento %d não está na fila\n",ele);
                } else{
                    printf("%d",flag);
                    printf("\nOcorreu um erro inesperado\n");
                }
                break;
            case 8:
                printf("Insira uma posição para encontrar o elemento: ");
                scanf("%d",&n);
                if(n > len(Q, &flag)-1){
                    printf("\nA fila não possui nenhum elemento na posição %d\n",n);
                } else{
                    pi = getElement(Q,n,&flag);
                    if(flag==PROCESS_SUCESS){
                        printf("\nO elemento na posição %d é %d\n",n,*pi);
                    }
                    else if(n<0){
                        printf("\nNão existem elementos em posição negativa\n");
                    }
                    else{
                        printf("\nOcorreu um erro inesperado\n");
                    }
                }
                break;
            case 9:
                if((len(Q, &flag) == 0) && (flag == PROCESS_SUCESS)){
                    printf("Fila vazia!\n");
                } else if(flag == PROCESS_SUCESS){
                    printf("Fila:\n");
                    printQueue(Q, &flag);
                } else{
                    printf("Ocorreu um erro inesperado\n");
                }
                break;
            case 10:
                invert(Q,&flag);
                if(flag == PROCESS_SUCESS){
                    printf("Fila invertida com sucesso!\n");
                } else{
                    printf("Ocorreu um erro inesperado");
                }
                break;
            case 11:
                cleanQueue(Q,&flag);
                if(flag==PROCESS_SUCESS){
                    printf("Fila limpa\n");
                }else{
                    printf("Ocorreu um erro inesperado\n");
                }
                break;
            default:
                printf("Parece que você inseriu um número inválido.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
