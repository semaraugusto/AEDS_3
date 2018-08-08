#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


void createEmptyQueue (queueType *queue) {
	queue->first = (queuePointer) malloc (sizeof(queueNode));
	queue->last = queue->first;
	queue->first->next = NULL;
}

int emptyQueueTest(queueType queue) {
	return (queue.first == queue.last);
}

void pushQueue(queueType *queue, queueItem x) {
	queue->last->next = (queuePointer) malloc(sizeof(queueNode));
	queue->last = queue->last->next;
	queue->last->item = x;
	queue->last->next = NULL;
}

void popQueue(queueType *queue, queueItem *item) {
	queuePointer q;
	if(emptyQueueTest(*queue))
		printf("The queue is already empty.\n");

	q = queue->first;
	queue->first = queue->first->next;
	*item = queue->first->item;
	free(q);
}

void printQueue(queueType queue) {
	queuePointer q;
	q = queue.first;
	printf("queue = 	");
	while(q != NULL) {
		printf("%d ", q->item.vertex);
		q = q->next;
	}printf("\n");
}
