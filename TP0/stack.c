#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void createEmptyStack (stackType *stack) {
	stack->top = (stackPointer) malloc(sizeof(stackNode));
	stack->bottom = stack->top;
	stack->top->next = NULL;
	stack->s_size = 0;
}

int testEmptyStack (stackType stack) {
	return(stack.top == stack.bottom);
}

void pushStack (stackType *stack, stackItem item) {
	stackPointer aux;

	aux = (stackPointer) malloc(sizeof(stackNode));

	stack->top->item = item;
	aux->next = stack->top;
	stack->top = aux;
	stack->s_size++;
}

void popStack (stackType *stack, stackItem *item) {
    stackPointer q;

    if (testEmptyStack(*stack)) {
    	printf("The stack is empty.\n");
    }

    q = stack->top;
    *item = q->next->item;
    stack->top = q->next;

    free(q);

    stack->s_size--;
}

void destroyStack (stackType *stack) {
	stackPointer q;
	while(!testEmptyStack(*stack)) {
		q = stack->top;
		stack->top = q->next;
		free(q);
	}
	free(stack->bottom);
}

