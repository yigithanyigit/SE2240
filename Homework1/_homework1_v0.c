#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
	int source;
	int destination;
	int weight;
} EDGE;

typedef struct{
	int num_vertices;
	int num_edges;
	EDGE *edges;
} GRAPH;

GRAPH *init_graph(int vertices, int edges);
void fill_graph(GRAPH *graph);

void prims_algorithm(GRAPH *graph);

GRAPH *init_graph(int vertices, int edges) {
	GRAPH *graph = calloc(1, sizeof(*graph));
	if(graph == NULL) {
		printf("Error:");
		exit(EXIT_FAILURE);
	}
	
	graph->num_vertices = vertices;
	graph->num_edges = edges;
	graph->edges = calloc(edges, sizeof(EDGE));
	
	if(graph->edges == NULL){
		printf("Error:");
		exit(EXIT_FAILURE);
	}
	return graph;
}

void fill_graph(GRAPH *graph){
	graph->edges[0].source = 1;
	graph->edges[0].destination = 3;
	graph->edges[0].weight = 12;

	graph->edges[1].source = 1;
	graph->edges[1].destination = 2;
	graph->edges[1].weight = 4;

	graph->edges[2].source = 2;
	graph->edges[2].destination = 5;
	graph->edges[2].weight = 10;

	graph->edges[3].source = 3;
	graph->edges[3].destination = 5;
	graph->edges[3].weight = 2;

	graph->edges[4].source = 3;
	graph->edges[4].destination = 4;
	graph->edges[4].weight = 7;

	graph->edges[5].source = 4;
	graph->edges[5].destination = 5;
	graph->edges[5].weight = 3;

	graph->edges[6].source = 4;
	graph->edges[6].destination = 6;
	graph->edges[6].weight = 8;

	graph->edges[7].source = 5;
	graph->edges[7].destination = 6;
	graph->edges[7].weight = 9;

	graph->edges[8].source = 6;
	graph->edges[8].destination = 7;
	graph->edges[8].weight = 11;

	graph->edges[9].source = 6;
	graph->edges[9].destination = 8;
	graph->edges[9].weight = 1;

	graph->edges[10].source = 7;
	graph->edges[10].destination = 8;
	graph->edges[10].weight = 13;

	graph->edges[11].source = 7;
	graph->edges[11].destination = 10;
	graph->edges[11].weight = 6;

	graph->edges[12].source = 8;
	graph->edges[12].destination = 9;
	graph->edges[12].weight = 5;

	graph->edges[13].source = 9;
	graph->edges[13].destination = 10;
	graph->edges[13].weight = 14;
}

void prims_algorithm(GRAPH *graph){
	// TODO: Implement the algorithm.
	// TODO: Print the solutio??n.
}

int main() {
	GRAPH *graph = init_graph(10, 14);
	fill_graph(graph);
	prims_algorithm(graph);
	return 0;
}
