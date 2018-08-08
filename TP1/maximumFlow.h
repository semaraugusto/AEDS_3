#ifndef MAXIMUMFLOW_H
#define MAXIMUMFLOW_H
#include "graphMatrix.h"

//void breadthFirstSearch(graphType *graph);

int visitBFS(graphType *graph, int *dist, int *previous, vertexValue vertex);

int EdmondKarp(graphType *graph, vertexValue source, vertexValue sink);

#endif
