#include "graph.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

GRAPH prims(GRAPH graph);
int getVerticeCount(GRAPH graph);
// TODO: Define your helper functions.



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

