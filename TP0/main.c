#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_polish.h"

#define MAX 200

#define debug(s) printf("%s\n", s)
#define breakpoint getch()


int main () {
	char leitura[MAX];
	int *s;
	int r;
	int i = 0, cont = 0;
	int tam, tamString = 0;
	
	scanf("%200[^\n]", leitura);
	scanf("%d", &r);	


	tam = (int)strlen(leitura);

	for(i = 0; i < tam; i++) {
		if(leitura[i] != ' ')
			tamString++;
	}

	s = (int *) malloc(tamString * sizeof(int));

	cont = 0;
	for(i = 0; i < tam; i++) {
		if(leitura[i] == ' ')
			continue;

		else if(leitura[i] == '?') {
			s[cont] = -1;
			cont++;
		}

		else {

			sscanf(&leitura[i], "%d", &s[cont]);
			cont++;
			// andar até encontrar um espaço pois o número pode ter mais de um algarismo.
			while(leitura[i] != ' ') {
				i++;
			}

		}
	}
	
	reverse_polish(s, cont, r);
	

	free(s);

	return 0;
}

