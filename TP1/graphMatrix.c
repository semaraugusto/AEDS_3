#include <stdio.h>
#include <stdlib.h>

#include "graphMatrix.h"
#include "queue.h"
#define TRUE 1

void createGraph(graphType *graph, int numVertex) {
	int i, j;

	graph->mat = (nodeType**) malloc(numVertex * sizeof(nodeType*));
	for(i = 0; i < numVertex; i++) {
		graph->mat[i] = (nodeType*) malloc(numVertex * sizeof(nodeType));
	}
	graph->numVertex = numVertex;
	graph->numEdges = 0;

	for(i = 0; i < numVertex; i++) {
		for(j = 0; j < numVertex; j++) {
			graph->mat[i][j].capacity = 0;
			graph->mat[i][j].flow = 0;
		}
	}

}

void insertEdge(graphType *graph, vertexValue *v1, vertexValue *v2, int capacity) {
	graph->mat[*v1][*v2].capacity = capacity;
}

short testEdgesExistence(graphType *graph, vertexValue v1, vertexValue v2) {
	return (graph->mat[v1][v2].capacity > 0);
}

short testIsolated(graphType *graph, vertexValue *v) {
	int aux = 0;
	short emptyList = 1;

	for(aux = 0; aux < graph->numVertex; aux++) {
		if(graph->mat[*v][aux].capacity > 0) {
			emptyList = 0;
			break;
		}
	}
	// while((aux < graph->numVertex) && emptyList) {
	// 	if(graph->mat[*v][aux].capacity > 0) {
	// 		emptyList = 0;
	// 	}
	// 	else
	// 		aux++;
	// }	
	return emptyList;
}

graphPointer firstAdjVertex(graphType *graph, vertexValue *v) {
	graphPointer first = -1, aux = 0;
	short emptyList = 1;

	while(aux < graph->numVertex && emptyList) {
		if(graph->mat[*v][aux].capacity > 0) {
			first = aux;
			emptyList = 0;
		}
		else 
			aux++;
	}
	if(aux == graph->numVertex)
		printf("Erro: nao ha nenhum vertice adjacente ao vertice desejado.\n");

	return first;
}

void nextAdjList(graphType *graph, vertexValue *vertex, vertexValue *adj, int *capacity, int *flow, graphPointer *next, short *endAdjList) {
	*adj = *next;
	*capacity = graph->mat[*vertex][*next].capacity;
	*flow = graph->mat[*vertex][*next].flow;
	(*next)++;
	
	while((*next < graph->numVertex) && (graph->mat[*vertex][*next].capacity == 0))
		(*next)++;
	if(*next == graph->numVertex)
		*endAdjList = TRUE;
}

void removeEdge(graphType *graph, vertexValue *v1, vertexValue *v2) {
	if(graph->mat[*v1][*v2].capacity == 0)
		printf("Nao existe aresta entre %d e %d\n", (*v1), (*v2));
	else 
		graph->mat[*v1][*v2].capacity = 0;
}

void destroyGraph (graphType *graph) {
	int i;
	for(i = 0; i < graph->numVertex; i++)
		free(graph->mat[i]);

	free(graph->mat);
}

void printGraph(graphType *graph) {
	int i, j;
	printf("capacity\n");
	for(i = 0; i < graph->numVertex; i++) {
		for(j = 0; j < graph->numVertex; j++) {
			printf("%d ", graph->mat[i][j].capacity);
		} printf("\n");
	}

	printf("flow\n");
	for(i = 0; i < graph->numVertex; i++) {
		for(j = 0; j < graph->numVertex; j++) {
			printf("%d ", graph->mat[i][j].flow);
		} printf("\n");
	}
}
















