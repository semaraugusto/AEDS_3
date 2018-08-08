#ifndef LIST_H
#define LIST_H

typedef struct listItem {
	int value;
} listItem;

typedef struct listNode *listPointer;

typedef struct listNode {
	listItem item;
	listPointer next;
} listNode;

typedef struct listType {
	listPointer first, last;
} listType;

void createEmptyList (listType *list);

int testEmptyList (listType list);

// void insertOnList (listType *list, listItem item);

void insertOnList (listType *list, int value);

void removeFromList (listType *list, listPointer p);

void printList (listType list);

#endif // LIST_H
