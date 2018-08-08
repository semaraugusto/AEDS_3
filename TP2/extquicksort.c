#include "extquicksort.h"

#define TRUE            1
#define FALSE           0

void FAVazia(buffer *buffer, int capacidadeRegistros) {
	buffer->reg = (registro*) malloc(capacidadeRegistros * sizeof(registro));
	buffer->numRegistros = 0;
	buffer->maxRegistros = capacidadeRegistros;
}

void InsereItem(registro Item, buffer *buffer) { 
	int Pos, Disp, IndiceInsercao;

	if (buffer->numRegistros == buffer->maxRegistros) { 
		printf("Tentativa de insercao em lista cheia.\n");
		return;
	}

	Disp = buffer->numRegistros;
	// buffer->numRegistros++;
	buffer->reg[numRegistros] = Item;
	
	if (buffer->numRegistros == 1) { 
		/* Insercao do primeiro item */
	    buffer->Primeiro = Disp;
	    buffer->Ultimo = buffer->Primeiro;
	    buffer->Itens[buffer->Primeiro].Prox = -1;
	    buffer->Itens[buffer->Primeiro].Ant = -1;
	    return;
	}
  
	Pos = buffer->numRegistros;
	// if (strcmp(item.chave, buffer->itens[pos].item.chave) < 0)
	if (Item.Chave < buffer->Itens[Pos].Item.Chave) { 
		/* Insercao realizada na primeira posicao */
		buffer->Itens[Disp].Ant = -1;
		buffer->Itens[Disp].Prox = Pos;
		buffer->Itens[Pos].Ant = Disp;
		buffer->Primeiro = Disp;
		return;
	}

	IndiceInsercao = buffer->Itens[Pos].Prox;
	while (IndiceInsercao != -1 && buffer->Itens[IndiceInsercao].Item.Chave < Item.Chave) { 
		Pos = IndiceInsercao;
		IndiceInsercao = buffer->Itens[Pos].Prox;
	}

	if (IndiceInsercao == -1) { 
		/*Insercao realizada na ultima posicao*/
		buffer->Itens[Disp].Ant = Pos;
		buffer->Itens[Disp].Prox = -1;
		buffer->Itens[Pos].Prox = Disp;
		buffer->Ultimo = Disp;
		return;
	}

	buffer->Itens[Disp].Ant = Pos;
	buffer->Itens[Disp].Prox = buffer->Itens[Pos].Prox;
	buffer->Itens[Pos].Prox = Disp;
	Pos = buffer->Itens[Disp].Prox;
	buffer->Itens[Pos].Ant = Disp;
	/* Insercao realizada no meio de buffer */
}

void LeSup(FILE **ArqLEs, TipoRegistro *UltLido, int *Ls, short *OndeLer) { 
	fseek(*ArqLEs, (*Ls - 1) * sizeof(TipoRegistro),SEEK_SET );
	fread(UltLido, sizeof(TipoRegistro), 1, *ArqLEs);
	(*Ls)--;
	*OndeLer = FALSE;
}

void LeInf(FILE **ArqLi,  TipoRegistro *UltLido, int *Li, short *OndeLer) { 
	fread(UltLido, sizeof(TipoRegistro), 1, *ArqLi);
	(*Li)++;
	*OndeLer = TRUE;
}

void InserirArea(buffer *buffer, registro *UltLido, int *NRArea) { 
	/*Insere UltLido de forma ordenada na Area*/
	InsereItem(*UltLido, Area);
	*NRArea = buffer->numRegistros;
}


void Particao(FILE **ArqLi, FILE **ArqEi,  FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j) { 
	
	int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0, Linf = INT_MIN, Lsup = INT_MAX;
	short OndeLer = TRUE;
	registro UltLido, R;

	fseek (*ArqLi, (Li - 1)* sizeof(registro), SEEK_SET );
	fseek (*ArqEi, (Ei - 1)* sizeof(registro), SEEK_SET );
	*i = Esq - 1;
	*j = Dir + 1;
	while (Ls >= Li) { 
		if (NRArea < TamArea - 1) { 
			if (OndeLer)
				LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
			else
				LeInf(ArqLi, &UltLido, &Li, &OndeLer);

			InserirArea(&Area, &UltLido, &NRArea);
			continue;
		}

		if (Ls == Es)
			LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);

		else
			if (Li == Ei)
				LeInf(ArqLi, &UltLido, &Li, &OndeLer);

		else 
			if (OndeLer)
				LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);

		else
			LeInf(ArqLi, &UltLido, &Li, &OndeLer);

		if (UltLido.Chave > Lsup) { 
			*j = Es;
			EscreveMax(ArqLEs, UltLido, &Es);
			continue;
		}

		if (UltLido.Chave < Linf) { 
			*i = Ei;
			EscreveMin(ArqEi, UltLido, &Ei);
			continue;
		}

		InserirArea(&Area, &UltLido, &NRArea);

		if (Ei - Esq < Dir - Es) { 
			RetiraMin(&Area, &R, &NRArea);
			EscreveMin(ArqEi, R, &Ei);
			Linf = R.Chave;
		}

		else { 
			RetiraMax(&Area, &R, &NRArea);
			EscreveMax(ArqLEs, R, &Es);
			Lsup = R.Chave;
		}
	}

	while (Ei <= Es) { 
		RetiraMin(&Area, &R, &NRArea);
		EscreveMin(ArqEi, R, &Ei);
	}
}

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir) { 
	int i, j;
	TipoArea Area;   /* Area de armazenamento interna*/
	if (Dir - Esq < 1) return;

	Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);

  	if (i - Esq < Dir - j) {  
  	/* ordene primeiro o subarquivo menor */
    	QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
    	QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
	}
  	else { 
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
    }
}
