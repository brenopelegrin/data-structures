#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	node* next;
	node* prev;
} Node;

typedef struct {
	int size;
	Node* first;
	Node* last;
} LkdList;

LkdList* createList(){
	list = malloc(sizeof(LkdList));
	if(list == NULL){
		return NULL;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

void addNodeToEnd(LkdList* list, int data){
	newNode = malloc(sizeof(Node));
	if(newNode == NULL){
		return;
	}
	if(list->size == 0){
		// empty list
		list->first = newNode;
		list->last = newNode;
	} else{
		newNode->last = lista->last;
		newNode->next = NULL;
		list->last->next = newNode;
	}
	list->size += 1;
	return;
}

Node* getNodeByIdx(LkdList* list, int idx){
	if(idx < 0 || idx >= list->size){
		// out of bounds
		return NULL;
	}

	Node* currNode = list->first;
	for(int i=0; i<=idx; i++){
		currNode = currNode->next;
	}
	return currNode;
}

void addNodeAfterIdx(LkdList* list, int idx){
	if(idx > list->size){
		idx = list->size - 1;
	}
	Node* currNode = getNodeByIdx(list, idx);
        newNode = malloc(sizeof(Node));
        if(newNode == NULL || currNode == NULL){
                return NULL;
        }
	newNode->next = currNode->next;
	newNode->prev = currNode;
	currNode->next->prev = newNode;
	currNode->next = newNode;
	list->size+=1;
	if(idx == list->size-1){
		list->last = newNode;
	}
	return;
}

void addNodeBeforeIdx(LkdList* list, int idx){
        Node* currNode = getNodeByIdx(list, idx);
        newNode = malloc(sizeof(Node));
        if(newNode == NULL || currNode == NULL){
                return NULL;
        }
        currNode->prev->next = newNode;
	newNode->prev = currNode->prev;
	newNode->next = currNode;
	currNode->prev = newNode;
	list->size+=1;
	if(idx == 1){
		list->first = newNode;
	}
        return;
}

int main(int argc, char* argv[]){
	return 0;
}
