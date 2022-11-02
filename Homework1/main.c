#include "kruskal.h"
#include "prims.h"

GRAPH createGraph() {
	GRAPH graph = graph_init(16);
	graph_addEdge(graph, 0, 1, 5);
	graph_addEdge(graph, 0, 5, 9);
	graph_addEdge(graph, 1, 2, 1);
	graph_addEdge(graph, 2, 3, 3);
	graph_addEdge(graph, 2, 5, 4);
	graph_addEdge(graph, 2, 6, 8);
	graph_addEdge(graph, 2, 7, 1);
	graph_addEdge(graph, 3, 4, 8);
	graph_addEdge(graph, 3, 7, 16);
	graph_addEdge(graph, 3, 8, 15);
	graph_addEdge(graph, 4, 9, 11);
	graph_addEdge(graph, 5, 6, 5);
	graph_addEdge(graph, 5, 10, 10);
	graph_addEdge(graph, 6, 7, 7);
	graph_addEdge(graph, 6, 11, 4);
	graph_addEdge(graph, 6, 12, 1);
	graph_addEdge(graph, 7, 13, 15);
	graph_addEdge(graph, 8, 9, 9);
	graph_addEdge(graph, 8, 14, 10);
	graph_addEdge(graph, 9, 15, 3);
	graph_addEdge(graph, 11, 12, 5);
	graph_addEdge(graph, 12, 13, 2);
	graph_addEdge(graph, 13, 14, 3);
	return graph;
}

void testKruskal() {
	printf("--------------------------------\n");
	printf("   .:: START KRUSKAL TEST ::.\n\n\n");
	
	printf("Graph:\n");
	GRAPH graph = createGraph();
	graph_print(graph);
	
	GRAPH mst = kruskal(graph);
	printf("MST:\n");
	graph_print(mst);
	
	printf("\n    .:: END KRUSKAL TEST ::.\n");
	printf("--------------------------------\n\n\n");
}

void testPrims() {
	printf("--------------------------------\n");
	printf("   .:: START PRIMS TEST ::.\n\n\n");
	
	printf("Graph:\n");
	GRAPH graph = createGraph();
	graph_print(graph);
	
	GRAPH mst = prims(graph);
	printf("MST:\n");
	graph_print(mst);
	
	printf("\n    .:: END PRIMS TEST ::.\n");
	printf("--------------------------------\n\n\n");
}

void comparison() {
	printf("--------------------------------\n");
	printf("   .:: START COMPARISON ::.\n\n");
	
	// TODO: You can do your comparison here.
	
	
	printf("\n\n    .:: END COMPARISON ::.\n");
	printf("--------------------------------\n");
}
 
int main() {
	testKruskal();
	testPrims();
	comparison();
	return 0;
}

