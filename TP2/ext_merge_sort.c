#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ext_merge_sort.h"


reg cmp (reg reg1, reg reg2) {
	// reg1 < reg2
	if(strcmp(reg1.word, reg2.word) < 0)
		return reg1;
	// reg1 > reg2
	else if (strcmp(reg1.word, reg2.word) > 0)
		return reg2;

	// reg1.word == reg2.word
	else {
		// frequencia é irrelevante já que se ela está no mesmo documento que outra palavra igual a ela, elas vão ter frequencias iguais.
		if(reg1.doc < reg2.doc)
			return reg1;
		else if(reg1.doc > reg2.doc)
			return reg2;
		// se tão no mesmo documento, comparamos as posições.
		else {
			if(reg1.pos < reg2.pos)
				return reg1;
			else if(reg1.pos > reg2.pos)
				return reg2;

			// se chegar nesse else, o programa possui alguma coisa errada pois está comparando uma palavra consigo mesma.
			else {
				printf("Comparando palavra consigo mesma.\n");
				return reg1;
			}
		}
	}

	return reg1;
}



