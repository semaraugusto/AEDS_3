#include <stdio.h>
#include <string.h>

int main (void) {
	
	char ch[10], ca[10];
	strcpy(ch, "olar");
	strcpy(ca, "aaaa");
	printf("strcmp = %d", strcmp(ca,ch));
}