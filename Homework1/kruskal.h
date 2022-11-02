#include "graph.h"

GRAPH kruskal(GRAPH graph);
num **createEdgeMatrix(GRAPH graph);
num sortEdgeMatrix(num **edgeMatrix, num numberOfEdges);
num isCycle(GRAPH mst, num start, num end);
num traverse(GRAPH mst, num search, num current);


GRAPH kruskal(GRAPH graph) {
	num i;
	num **edgeMatrix = createEdgeMatrix(graph);
	GRAPH mst = graph_init(graph->size);
	for (i = 0; i < graph_getNumberOfEdges(graph); i++) {
		if (!isCycle(mst, edgeMatrix[i][0], edgeMatrix[i][1])) {
			graph_addEdge(mst, edgeMatrix[i][0], edgeMatrix[i][1], edgeMatrix[i][2]);
		}
	}
	return mst;
}

num **createEdgeMatrix(GRAPH graph) {
	num i, j;
	num numberOfEdges = graph_getNumberOfEdges(graph);
	num **edgeMatrix = (num**)malloc(sizeof(num*) * numberOfEdges);
	for (i = 0; i < numberOfEdges; i++) {
		edgeMatrix[i] = (num*)malloc(sizeof(num) * 3);
	}
	num matrixCounter = 0;
	for (i = 0; i < graph->size; i++) {
		for (j = 0; j < i; j++) {
			num weight = graph->matrix[i][j];
			if (weight > 0) {
				edgeMatrix[matrixCounter][0] = i;
				edgeMatrix[matrixCounter][1] = j;
				edgeMatrix[matrixCounter][2] = weight;
				matrixCounter++;
			}
		}
	}
	sortEdgeMatrix(edgeMatrix, numberOfEdges);
	return edgeMatrix;
}

num sortEdgeMatrix(num **edgeMatrix, num numberOfEdges) {
	num i, j;
	for (i = 0; i < numberOfEdges - 1; i++) {
		for (j = 0; j < numberOfEdges - i - 1; j++) {
			if (edgeMatrix[j][2] > edgeMatrix[j + 1][2]) {
				num *temp = edgeMatrix[j];
				edgeMatrix[j] = edgeMatrix[j + 1];
				edgeMatrix[j + 1] = temp;
			}
		}
	}
}

num isCycle(GRAPH mst, num start, num end) {
	num i;
	GRAPH clone = graph_clone(mst);
	num found = traverse(clone, start, end);
	graph_free(clone);
	return found;
}

num traverse(GRAPH mst, num search, num current) {
	num i;
	num found = 0;
	for (i = 0; i < mst->size; i++) {
		if (mst->matrix[current][i]) {
			graph_removeEdge(mst, current, i);
			found += traverse(mst, search, i);
		}
	}
	return found + (search == current);
}

