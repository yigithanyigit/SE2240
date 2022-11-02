#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <string.h>

typedef struct
{
	int source;
	int destination;
	int weight;
} EDGE;

typedef struct
{
	int num_vertices;
	int num_edges;
	EDGE *edges;
} GRAPH;

typedef struct
{
	EDGE *s_edges;
	int s_num_elements;
} EDGEARRAY;

GRAPH *init_graph(int vertices, int edges);
void fill_graph(GRAPH *graph);

void prims_algorithm(GRAPH *graph);

GRAPH *init_graph(int vertices, int edges)
{
	GRAPH *graph = calloc(1, sizeof(*graph));
	if (graph == NULL)
	{
		printf("Error:");
		exit(EXIT_FAILURE);
	}

	graph->num_vertices = vertices;
	graph->num_edges = edges;
	graph->edges = calloc(edges, sizeof(EDGE));

	if (graph->edges == NULL)
	{
		printf("Error:");
		exit(EXIT_FAILURE);
	}
	return graph;
}

void fill_graph(GRAPH *graph)
{
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

EDGEARRAY *arrayInit(int num_vertice)
{
	EDGEARRAY *arr = calloc(num_vertice + 1, sizeof(EDGEARRAY));

	for (size_t i = 1; i < num_vertice + 1; i++)
	{
		arr[i].s_edges = calloc(1, sizeof(EDGE));
		arr[i].s_num_elements = 0;
	}

	return arr;
}

void addElementToArray(EDGEARRAY *arr, EDGE *edge)
{
	// I assumed graph is have not a vertice that name is "0"
	int sourceOfCurrentEdge = edge->source;
	int destinationOfCurrentEdge = edge->destination;

	// I created a data type that contains all edges.

	arr[sourceOfCurrentEdge].s_edges[arr[sourceOfCurrentEdge].s_num_elements] = *edge;
	arr[sourceOfCurrentEdge].s_num_elements++;
	arr[sourceOfCurrentEdge].s_edges = realloc(arr[sourceOfCurrentEdge].s_edges, sizeof(EDGE) * (arr[sourceOfCurrentEdge].s_num_elements + 2));
	
	arr[destinationOfCurrentEdge].s_edges[arr[destinationOfCurrentEdge].s_num_elements].source = edge->destination;
	arr[destinationOfCurrentEdge].s_edges[arr[destinationOfCurrentEdge].s_num_elements].destination = edge->source;
	arr[destinationOfCurrentEdge].s_edges[arr[destinationOfCurrentEdge].s_num_elements].weight = edge->weight;
	arr[destinationOfCurrentEdge].s_num_elements++;
	arr[destinationOfCurrentEdge].s_edges = realloc(arr[destinationOfCurrentEdge].s_edges, sizeof(EDGE) * (arr[destinationOfCurrentEdge].s_num_elements + 2));
}

void fillArrayWithEdges(EDGEARRAY *arr, GRAPH *graph)
{
	for (size_t i = 0; i < graph->num_edges; i++)
	{
		addElementToArray(arr, &graph->edges[i]);
	}
}

void removeVerticeFromArray(EDGEARRAY *arr, EDGE *edge)
{
	for (size_t i = 0; i < arr[edge->source].s_num_elements; i++)
	{
		if (arr[edge->source].s_edges[i].destination == edge->destination)
		{
			memset(&(arr[edge->source].s_edges[i]), 0, sizeof(*edge));
			arr[edge->source].s_num_elements--;
		}
	}
	for (size_t j = 0; j < arr[edge->destination].s_num_elements; j++)
	{
		if (arr[edge->destination].s_edges[j].destination == edge->source && arr[edge->destination].s_edges[j].source == edge->destination)
		{

			memset(&(arr[edge->destination].s_edges[j]), 0, sizeof(*edge));
			arr[edge->destination].s_num_elements--;
		}
	}
}

void printAray(EDGEARRAY *arr, GRAPH *graph)
{
	for (size_t i = 0; i < graph->num_edges; i++)
	{
		// printf("%02d | %d %d %d\n", graph->edges[i].source, arr[graph->edges[i].source].s_edges[0].source, arr[graph->edges[i].source].s_edges[0].destination, arr[graph->edges[i].source].s_edges[0].weight);
		for (size_t j = 0; j < arr[graph->edges[i].source].s_num_elements; j++)
		{
			printf("Source Index %d |%d %d %d\n" ,graph->edges[i].source, arr[graph->edges[i].source].s_edges[j].source, arr[graph->edges[i].source].s_edges[j].destination, arr[graph->edges[i].source].s_edges[j].weight);
		}
	}
}

void prims_algorithm(GRAPH *graph)
{
	EDGEARRAY *arr = arrayInit(graph->num_vertices);
	EDGEARRAY *mst = arrayInit(graph->num_vertices);

	fillArrayWithEdges(arr, graph);
	// printAray(arr, graph);

	// removeVerticeFromArray(arr, &graph->edges[0]);
	// addElementToArray(mst, &graph->edges[0]);
	printAray(arr, graph);

	EDGE arr1[13];
	int arrIndex = 0;
	EDGE currentEdge = graph->edges[graph->num_vertices / 2];
	int currentVertice = currentEdge.source;
	int verticeCount = graph->num_vertices;
	int spanningWeight = 0;

	
	while (verticeCount)
	{
		// printf("%d ", currentVertice);

		// Get Closest Vertex from current position
		int lowest = INT_MAX;
		EDGE newEdge;

		for (size_t i = 0; i < arr[currentVertice].s_num_elements; i++)
		{

			if (arr[currentVertice].s_edges[i].weight < lowest && arr[currentVertice].s_edges[i].weight != 0)
			{
				lowest = arr[currentVertice].s_edges[i].weight;
				newEdge = arr[currentVertice].s_edges[i];
			}
		}
		//printf("x; %d %d ", newVertice.source, newVertice.destination);

		arr1[arrIndex++] = currentEdge;
		removeVerticeFromArray(arr, &newEdge);
		spanningWeight += lowest;
		currentVertice = newEdge.destination;
		printAray(arr, graph);
		printf("\n");
		verticeCount--;
	}

	printf("%d \n", spanningWeight);
	printf("%d \n", arrIndex);
	// printAray(mst, graph);
	while (arrIndex--)
	{
		printf("Index: %d | %d %d %d \n", arrIndex, arr1[arrIndex].source, arr1[arrIndex].destination, arr1[arrIndex].weight);
	}
	// TODO: Implement the algorithm.
	// TODO: Print the solutioın.
}

int main()
{
	GRAPH *graph = init_graph(10, 14);
	fill_graph(graph);
	prims_algorithm(graph);
	return 0;
}
