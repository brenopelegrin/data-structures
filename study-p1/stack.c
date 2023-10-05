#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    unsigned int size;
    int top;
    int* array;
} Stack;

Stack* createStack(int size){
    Stack* s = (Stack *) malloc(sizeof(Stack));
    s->size = size;
    s->top = -1;
    s->array = (int *) malloc(sizeof(int)*s->size);
    return s;
}

int isFull(Stack* s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Stack* s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(Stack* s, int value){
    if(isFull(s)){
        return -999;
    }
    else{
        s->top++;
        s->array[s->top] = value;
        return 1;
    }
}

int pop(Stack* s){
    if(isEmpty(s)){
        return -999;
    }
    else{
        int aux = s->array[s->top];
        s->top--;
        return aux;
    }
}

int top(Stack *s){
    if(isEmpty(s)){
        return -999;
    }
    else{
        return s->array[s->top];
    }
}

void printStack(Stack *s){
    for(int i=0;i<s->size;i++){
        printf("%d ", s->array[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    Stack* s = createStack(5);
    printf("top: %d\n", top(s));
    printf("pop: %d\n", pop(s));
    printf("push: %d\n", push(s, 1));
    printf("push: %d\n", push(s, 2));
    printf("push: %d\n", push(s, 3));
    printStack(s);
    printf("top: %d\n", top(s));
    printf("pop: %d\n", pop(s));
    printf("pop: %d\n", pop(s));
    printf("pop: %d\n", pop(s));
    printf("pop: %d\n", pop(s));
    printStack(s);
    printf("push: %d\n", push(s, 4));
    printf("push: %d\n", push(s, 5));
    printf("push: %d\n", push(s, 6));
    printf("push: %d\n", push(s, 7));
    printf("push: %d\n", push(s, 8));
    printf("push: %d\n", push(s, 9));
    printStack(s);
    return 0;
}

