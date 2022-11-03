#include "graph.h"

#include <time.h> // For random start

#define INT_MAX 2147483647

GRAPH prims(GRAPH graph);
num *createVerticeArray(GRAPH graph);
int isUnique(num *arr, int len, num key);
void setZero(num* arr, int len);
// TODO: Define your helper functions.

num *createVerticeArray(GRAPH graph)
{
	num *verticeArray = malloc(sizeof(num) * graph->size);

	for (size_t i = 0; i < graph->size; i++)
	{
		verticeArray[i] = i;
	}

	return verticeArray;
}

int isUnique(num *arr, int len, num key)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == key)
		{
			return 1;
		}
	}

	return 0;
}

void setZero(num* arr, int len)
{
	

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = 0;
	}

}
/*
GRAPH prims(GRAPH graph) {
	// TODO: Fill this function.
	srand(time(NULL));

	GRAPH mst = graph_init(graph->size);
	int startingVertice = rand() % graph->size;
	int verticeCount = 0;
	for (size_t i = 0; verticeCount <= 3; i++)
	{
		int low = INT_MAX;
		int lowIndex = -1;
		int q;
		for (q = 0; q < graph->size; q++)
		{
			if((graph->matrix[startingVertice][q] < low && graph->matrix[startingVertice][q] > 0) || (graph->matrix[q][startingVertice] < low && graph->matrix[q][startingVertice] > 0))
			{
				low = graph->matrix[startingVertice][q];
				lowIndex = q;
			}
		}
		if(lowIndex != -1)
		{

			graph_removeEdge(graph, startingVertice, lowIndex);
			graph_addEdge(mst, startingVertice, lowIndex, graph->matrix[startingVertice][lowIndex]);
			startingVertice = lowIndex;
			verticeCount++;
		}
	}




	return mst;
}
*/

GRAPH prims(GRAPH graph)
{

	srand(time(NULL));

	int startingVertice = rand() % graph->size;
	int verticeCount = graph->size;

	int numberOfEdge;

	GRAPH mst = graph_init(graph->size);

	num visited[verticeCount]; // First array for numbers and second one is for is visited or is not visited

	setZero(visited, verticeCount);

	numberOfEdge = 0;

	visited[startingVertice] = 1;

	int source;
	int destination;

	while (numberOfEdge < verticeCount - 1)
	{

		int min = INT_MAX;
		source = 0;
		destination = 0;

		for (int i = 0; i < verticeCount; i++)
		{
			if (visited[i])
			{
				for (int j = 0; j < verticeCount; j++)
				{
					if (!visited[j] && graph->matrix[i][j] && min > graph->matrix[i][j])
					{
						min = graph->matrix[i][j];
						source = i;
						destination = j;
					}
				}
			}
		}
		graph_addEdge(mst, source, destination, graph->matrix[source][destination]);
		visited[destination] = 1;
		numberOfEdge++;
	}
	return mst;
}
