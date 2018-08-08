#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void createEmptyList (listType *list) {
	list->first = (listPointer) malloc(sizeof(listNode));
	list->last = list->first;
	list->first->next = NULL;
}

int testEmptyList (listType list) {
	return (list.first == list.last);
}

// void insertOnList (listType *list, listItem data) {
// 	list->last->next = (listPointer) malloc(sizeof(listNode));
// 	list->last = list->last->next;
// 	list->last->item = data;
// 	list->last->next = NULL;
// }

void insertOnList (listType *list, int value) {
	listItem data;
	data.value = value;
	list->last->next = (listPointer) malloc(sizeof(listNode));
	list->last = list->last->next;
	list->last->item = data;
	list->last->next = NULL;
}

void removeFromList (listType *list, listPointer previous) {
// o item a ser retirado será o seguinte ao dado por p
	listPointer q;
	if (testEmptyList(*list) || previous == NULL || previous->next == NULL) {
		printf("Erro: Lista vazia ou posição inválida.");
		return;
	}
	q = previous->next;
	previous->next = q->next;

	if (previous->next == NULL) {
		list->last = previous;
	}
	free(q);
}

void freeList (listType *list) {
	listPointer p;

	while(!testEmptyList(*list)) {
		p = list->last;
		list->last = p->next;
		free(p);
	}
}

void printList(listType list) {
	listPointer q;
	q = list.first;
	while(q->next != NULL) {
		printf("%d ", q->item.value);
		q = q->next;
	}
}
