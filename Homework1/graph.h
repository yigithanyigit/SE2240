#ifndef GRAPH_H_
#define GRAPH_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long num;

typedef struct GRAPH_s *GRAPH;
typedef struct GRAPH_s {
	num size;
	num **matrix;
} GRAPH_t[1];


GRAPH graph_init(num size);
void graph_free(GRAPH graph);
GRAPH graph_clone(GRAPH graph);
void graph_addEdge(GRAPH graph, num start, num end, num weight);
void graph_removeEdge(GRAPH graph, num start, num end);
num graph_getNumberOfEdges(GRAPH graph);
void graph_print(GRAPH graph);


GRAPH graph_init(num size) {
	num i, j;
	GRAPH graph = (GRAPH)malloc(sizeof(GRAPH_t));
	graph->size = size;
	graph->matrix = (num**)malloc(sizeof(num*) * size);
	for (i = 0; i < size; i++) {
		graph->matrix[i] = (num*)malloc(sizeof(num) * size);
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			graph->matrix[i][j] = 0;
		}
	}
	return graph;
}

void graph_free(GRAPH graph) {
	num i;
	for (i = 0; i < graph->size; i++) {
		free(graph->matrix[i]);
	}
	free(graph->matrix);
	free(graph);
}

GRAPH graph_clone(GRAPH graph) {
	num i, j;
	GRAPH clone = graph_init(graph->size);
	for (i = 0; i < graph->size; i++) {
		for (j = 0; j < graph->size; j++) {
			clone->matrix[i][j] = graph->matrix[i][j];
		}
	}
	return clone;
}

void graph_addEdge(GRAPH graph, num start, num end, num weight) {
	if (start >= graph->size || end >= graph->size || start < 0 || end < 0) {
		printf("WARNING: At least one of edge index is out of bound.\n");
		return;
	}
	if (start == end) {
		printf("WARNING: Given edge indices cannot be the same.\n");
		return;
	}
	graph->matrix[start][end] = weight;
	graph->matrix[end][start] = weight;
}

void graph_removeEdge(GRAPH graph, num start, num end) {
	graph_addEdge(graph, start, end, 0);
}

num graph_getNumberOfEdges(GRAPH graph) {
	num i, j;
	num count = 0;
	for (i = 0; i < graph->size; i++) {
		for (j = 0; j < i; j++) {
			if (graph->matrix[i][j] > 0) {
				count++;
			}
		}
	}
	return count;
}

void graph_print(GRAPH graph) {
	num i, j;
	if (graph == NULL) {
		printf("WARNING: The graph is not initialized.\n");
		return;
	}
	printf("Graph size: %lu\n", graph->size);
	for (i = 0; i < graph->size; i++) {
		for (j = 0; j < i; j++) {
			num weight = graph->matrix[i][j];
			if (weight > 0) {
				printf("[ %lu, %lu ] = %lu\n", i, j, weight);
			}
		}
	}
	printf("\n");
}


#endif

