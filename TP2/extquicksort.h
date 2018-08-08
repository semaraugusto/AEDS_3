#ifndef EXTQUICKSORT_H
#define EXTQUICKSORT_H

#define TRUE 1
#define FALSE 0

typedef struct registro {
	char word[20];
	int freq;
	int doc;
	int pos;
} registro;

typedef struct buffer {
	registro *reg;
	int numRegistros;
	int maxRegistros;
} buffer;

void FAVazia(buffer *buffer, int maxRegistros);


// int ObterNumCelOcupadas(buffer *buffer);

// void InsereItem(TipoItem Item, buffer *buffer);

// void RetiraPrimeiro(buffer *buffer, TipoItem *Item);

// void RetiraUltimo(buffer *buffer, TipoItem *Item);

// void ImprimeArea(buffer *buffer);

// void LeSup(FILE **ArqLEs, registro *UltLido, int *Ls, short *OndeLer);

// void LeInf(FILE **ArqLi,  registro *UltLido, int *Li, short *OndeLer);

// void InserirArea(buffer *buffer, registro *UltLido, int *NRArea);

// void EscreveMax(FILE **ArqLEs, registro R, int *Es);

// void EscreveMin(FILE **ArqEi, registro R, int *Ei);

// void RetiraMax(buffer *buffer, registro *R, int *NRArea);

// void RetiraMin(buffer *buffer, registro *R, int *NRArea);

// void Particao(FILE **ArqLi, FILE **ArqEi,  FILE **ArqLEs, buffer buffer, int Esq, int Dir, int *i, int *j);

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir);

#endif
