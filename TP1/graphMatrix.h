#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include "queue.h"

typedef int vertexValue;
typedef int flowType;
typedef int capacityType;
typedef int graphPointer;

typedef struct  {
	int flow;
	int capacity;
} nodeType;

typedef struct graphType {
	nodeType **mat;
	int numVertex;
	int numEdges;
} graphType;

void createGraph(graphType *graph, int numVertex);

void insertEdge(graphType *graph, vertexValue *v1, vertexValue *v2, int capacity);

short testEdgesExistence(graphType *graph, vertexValue v1, vertexValue v2);

short testIsolated(graphType *graph, vertexValue *v);

graphPointer firstAdjVertex(graphType *graph, vertexValue *v);

void nextAdjList(graphType *graph, vertexValue *vertex, vertexValue *adj, int *capacity, int *flow, graphPointer *next, short *endAdjList);

void removeEdge(graphType *graph, vertexValue *v1, vertexValue *v2);

void destroyGraph (graphType *graph);

void printGraph(graphType *graph);

#endif
