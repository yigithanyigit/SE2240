#include "graph.h"

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

GRAPH prims(GRAPH graph)
{

	srand(time(NULL));

	int startingVertice = rand() % graph->size;
	int verticeCount = graph->size;

	int numberOfEdge;

	GRAPH mst = graph_init(graph->size);

	num visited[verticeCount]; // it is legal after c11

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
