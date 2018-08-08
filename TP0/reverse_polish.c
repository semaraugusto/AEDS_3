#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_polish.h"
#include "stack.h"
 
void solve(int *s, int *op, int nInterrogacoes, int tam, int valorExpressao) {
	stackType stack;
	stackItem operador1, operador2;
	int i = 0, j, k;

	createEmptyStack(&stack);

	while(i >= 0) {

		j = 0;
		for(k = 0; k < tam || j < nInterrogacoes; k++) {
			if(s[k] != -1) {
				operador1.value = s[k];
				pushStack(&stack, operador1);
			}
			else {
				popStack(&stack, &operador1);
				popStack(&stack, &operador2);

				 if(op[j] == 0) {
				 	operador1.value += operador2.value;
				 	pushStack(&stack, operador1);
				 }
				 else {
				 	operador1.value *= operador2.value;
				 	pushStack(&stack, operador1);
				 }
				j++;
			}
		}

		if(operador1.value == valorExpressao) {
			for(k = 0; k < nInterrogacoes; k++) {
				if(op[k] == 0)
					printf("+");
				else
					printf("*");
			}
			printf("\n");
		}
		pushStack(&stack, operador1);


		// aqui faz realmente as permutações. é um contador binário.
		for (i = nInterrogacoes - 1; i >= 0 && ++op[i] == 2; i--) {
			op[i] = 0;
		}
	}
	destroyStack(&stack);

}

void reverse_polish(int  *s, int tam, int valorExpressao) {
	int nInterrogacoes = 0;
	register int *op, i;
	for (i = 0; i < tam; i++) {
		if(s[i] == -1)
			nInterrogacoes++;
	}

	op = (int *) calloc (nInterrogacoes, sizeof(int));      // criei um vetor para organizar as operaçoes
															// 0 = +, 1 = *
	solve(s, op, nInterrogacoes, tam, valorExpressao);	

	free(op);
}
