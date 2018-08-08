#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stackItem {
	int value;
} stackItem;

typedef struct stackNode *stackPointer;

typedef struct stackNode {
	stackItem item;
	stackPointer next;
} stackNode;

typedef struct stackType {
	stackPointer bottom, top;
	int s_size; // size of the strack
} stackType;


void createEmptyStack (stackType *stack);

int stackSize(stackType *stack);

int testEmptyStack (stackType stack);

void pushStack (stackType *stack, stackItem item);

stackPointer encontraMensagem (stackType *stackGlobal, int value);

void popStack (stackType *stack, stackItem *item);

void printStack(stackType *stack);

void destroyStack (stackType *stack);

#endif // STACK_H

