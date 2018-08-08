#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphMatrix.h"
#include "maximumFlow.h"

#define inf 100000000

int main () {
	int i;
	int v, numEdges, f, c, numVertex;
	int u, flow;
	graphType graph;
	int source = 0, sink;
	int maxFlow;

	scanf("%d %d %d %d", &numVertex, &numEdges, &f, &c); // vertices, arestas, franquias, clientes;
	sink = numVertex + 1;

	// usando 2 vertices auxiliares para o uso correto de um grafo de fluxo.
	// Vertices auxiliares = primeiro e último.
	createGraph(&graph, (numVertex + 2));

	// guardando as características das arestas
	for(i = 0; i < numEdges; i++) {
		scanf("%d %d %d", &u, &v, &flow);
		u += 1;
		v += 1;
		insertEdge(&graph, &u, &v, flow);
	}
	for(i = 0; i < f; i++) {
		scanf("%d", &v);
		v += 1;
		insertEdge(&graph, &source, &v, inf);
	}
	for(i = 0; i < c; i++) {
		scanf("%d", &v);
		v += 1;
		insertEdge(&graph, &v, &sink, inf);
	}

	maxFlow = EdmondKarp(&graph, source, sink);
	printf("%d\n",maxFlow);

	destroyGraph(&graph);	
	return 0;
}

