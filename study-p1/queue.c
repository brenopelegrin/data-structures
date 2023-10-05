#include<stdio.h>
#include<stdlib.h>
#define ERROR_CODE -999

typedef struct queue {
    unsigned int size;
    int *array;
    int start;
    int end;
} Queue;

void emptyQueue(Queue* q){
    for(int i=0;i<q->size;i++){
        q->array[i] = NULL;
    }
    q->start = 0;
    q->end = 0;
    return;
}

Queue* createQueue(int size){
    Queue* q = (Queue *) malloc(sizeof(Queue));
    q->start = 0;
    q->end = 0;
    q->size = size;
    q->array = (int *) malloc(sizeof(int)*q->size);
    emptyQueue(q);
    return q;
}

int isFull(Queue *q){
    /*  isFull method.
        Returns 1 if full, 0 if not full.
    */
    if(q->end == q->size){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Queue *q){
    /*  isEmpty method.
        Returns 1 if queue is empty, 0 if not empty.
    */
    if(q->end == q->start){
        return 1;
    }
    else{
        return 0;
    }
}

int enqueue(Queue* q, int value){
    /*  enqueue method.
        Returns -999 if queue is full, return 1 if successful.
    */
    if(isFull(q)){
        return ERROR_CODE;
    }
    else{
        q->array[q->end] = value;
        q->end += 1;
        return 1;
    }
}

int dequeue(Queue* q){
    /*  dequeue method.
        Returns -999 if queue is empty, return dequeued value if successful.
    */
    if(isEmpty(q)){
        return ERROR_CODE;
    }
    else{
        int aux = q->array[q->start];
        q->array[q->start] = NULL;
        q->start += 1;
        return aux;
    }
}

void printQueue(Queue *q){
    for(int i=0;i<q->size;i++){
        printf("%d ", q->array[i]);
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[]){
    Queue* q = createQueue(4);
    dequeue(q);
    for(int i=1; i<6; i++){
        printf("enq: %d\n", enqueue(q, i));
    }
    printQueue(q);
    for(int i=1; i<6; i++){
        printf("deq: %d\n", dequeue(q));
    }
    printQueue(q);
    return 0;
}