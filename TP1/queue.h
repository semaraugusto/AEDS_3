#ifndef QUEUE_H
#define QUEUE_H

// #include "graphMatrix.h"

typedef struct queueNode *queuePointer;

typedef struct queueItem{
	int vertex;
	int capacity;
	int flow;
} queueItem;

typedef struct queueNode {
	queueItem item;
	queuePointer next;
} queueNode;

typedef struct queueType {
	queuePointer first;
	queuePointer last;
} queueType;

void createEmptyQueue (queueType *queue);

int emptyQueueTest(queueType queue);

void pushQueue(queueType *queue, queueItem x);

void popQueue(queueType *queue, queueItem *item);

void printQueue(queueType queue);


#endif
