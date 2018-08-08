#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extquicksort.h"
#include "extquicksort.c"


int main() {
	int i;
	int numDoc, sizeMem;
	char dirConv[50], dirOutput[50];
	char fileaux[50];
	buffer buffer;
	registro reg1;
	FILE *fileIn;
	FILE *arqLEs, *arqLi, *arqEi;
	fpos_t pos = 0;
	arqLi = fopen("tmp", "wb");

	scanf("%d %d %s %s", &numDoc, &sizeMem, dirConv, dirOutput);
	printf("%d %d %s %s\n", numDoc, sizeMem, dirConv, dirOutput);

	i = sizeMem/32;
	FAVazia(&buffer, i);


	for(i = 1; i <= numDoc; i++) {
		strcpy(fileaux, dirConv);
		sprintf(fileaux, "%s%d", dirConv, i);

		//printf("%s\n", fileaux);
		fileIn = fopen(fileaux, "r");

		if(fileIn == NULL) {
			printf("Não foi possível abrir o arquivo.\n");
			return -1;
		}

		while(fscanf(fileIn, "%s", reg1.word) != EOF) {
			reg1.freq = 0;
			reg1.doc = i;
			//fgetpos(fileIn, &pos);
			reg1.pos = pos;
			fwrite(&reg1, sizeof(registro), 1, arqLi);
			pos = pos + strlen(reg1.word) + 1;
		}
		fclose(fileIn);
	}

	fclose(arqLi);
	arqLi = fopen("tmp", "r+b");
	if(arqLi == NULL) {
		printf("Não foi possível abrir o arquivo.\n");
		return -1;
	}

	arqLEs = fopen("tmp", "r+b");
	if(arqLEs == NULL) {
		printf("Não foi possível abrir o arquivo.\n");
		return -1;
	}

	arqEi = fopen("tmp", "r+b");
	if(arqEi == NULL) {
		printf("Não foi possível abrir o arquivo.\n");
		return -1;
	}

	// quicksortExterno(&arqLi, &arqEi, &areLEs);

	// while(fread(&reg1, sizeof(registro), 1, arqLi) == 1)
	// 	printf("%s %d %d %d\n", reg1.word, reg1.freq, reg1.doc, reg1.pos);

	return 0;
}
