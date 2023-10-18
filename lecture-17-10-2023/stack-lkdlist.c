
void inserir(Lista* list, elem *x, int *erro){
	no* p = (no*) malloc(sizeof(no));
	// adds element to head instead of end
	if(p == NULL){
		*erro = 1;
		return;
	}
	*erro = 0;
	p->info=*x;
	if(list->top == NULL){
		list->top = p;
		p->next = NULL;
		return;
	}
	p->next = lista->top;
	list->top = p;
	return;
}
