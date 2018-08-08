#include <stdio.h>
#include <stdlib.h>
#include "graphMatrix.h"
#include "queue.h"

#define inf 100000000
#define white 0
#define gray 1
#define black 2
#define FALSE 0
#define TRUE 1

int minimumValue(int x, int y) {
	if(x < y)
		return x;

	return y;
}

int visitBFS(graphType *graph, int *parent, vertexValue u, vertexValue sink) {
	short endAdjList;
	int *color;
	queueType queue;
	queueItem item;
	graphPointer aux;
	vertexValue v;
	int capAux, flowAux;

	color = (int*)calloc(graph->numVertex, sizeof(int));

	color[u] = gray;
	createEmptyQueue(&queue);
	item.vertex = u;
	item.capacity = 0;
	item.flow = 0;

	pushQueue(&queue, item);

	while(!emptyQueueTest(queue)) {
		popQueue(&queue, &item);
		u = item.vertex;

		if(!testIsolated(graph, &u)) {
			// achando os vértices adjacentes
			aux = firstAdjVertex(graph, &u);
			endAdjList = FALSE;

			while(endAdjList == FALSE) {
				nextAdjList(graph, &u, &v, &capAux, &flowAux, &aux, &endAdjList);
				if(color[v] != white)
					continue;
				if((graph->mat[u][v].capacity - graph->mat[u][v].flow > 0)) {
					color[v] = gray;
					parent[v] = u;
					item.vertex = v;
					item.capacity = capAux;
					item.flow = flowAux;
					pushQueue(&queue, item);
					continue;
				}

			}
		}
		color[u] = black;
	}
	return(color[sink] == black);
}


int EdmondKarp(graphType *graph, vertexValue source, vertexValue sink) {
	int i;
	int maxFlow = 0;
	int *parent;
	int flowIncrease;
	parent = (vertexValue*) malloc(graph->numVertex * sizeof(vertexValue));

	for(i = 0; i < graph->numVertex; i++)
		parent[i] = -1;


	// enquanto existir um caminho aumentador, aumente o fluxo seguindo o caminho especificado.
	while(visitBFS(graph, parent, source, sink)) {
	// escolhendo o valor pelo qual é possível aumentar o fluxo sem overflow

		flowIncrease = inf;

		// encontrando o menor valor pelo qual é possível encontrar o caminho aumentador
		for(i = sink; parent[i] >= 0; i = parent[i]) {
			flowIncrease = minimumValue(flowIncrease, (graph->mat[parent[i]][i].capacity - graph->mat[parent[i]][i].flow));
		}
		// atualizando o grafo residual
		for(i = sink; parent[i] >= 0; i = parent[i]) {
			graph->mat[parent[i]][i].capacity -= flowIncrease;
			graph->mat[i][parent[i]].capacity += flowIncrease; 
		}
		// aumentando o fluxo máximo pelo valor encontrado
		maxFlow += flowIncrease;
	}
	free(parent);
	return maxFlow;
}




























