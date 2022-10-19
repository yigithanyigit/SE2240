#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*DO NOT CHANGE ANY PARAMETER, INCLUDES, STRUCTURES
  DO NOT ADD EXTRA FUNCTIONS, DO NOT CHANGE main and createGraph
  DO NOT ADD EXTRA INCLUDES
  SEND ONLY "graph.txt" and "kruskalLabwork.c
  FILL createUniques, unionFind, kruskalMST and sortEdges FUNCTIONS"
  */

// Edge inside the graph
typedef struct Edge
{
    unsigned int weight;
    unsigned char begin;
    unsigned char end;
} Edge;

// Graph structure
typedef struct Graph
{
    unsigned int size;
    Edge *edges;
} Graph;

// create Graph from file
Graph *createGraph(char *filename)
{
    // open file in read mode
    FILE *fp = fopen(filename, "r");

    // check if file is there
    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        // calculate size of the graph by line number
        // initialize begin end, weight

        // create graph
        Graph *graph = malloc(sizeof(Graph));

        // calculate size of the graph by line number. BE CAREFUL with the last line
        int size = 0;
        char c;
        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '\n')
                size++;
        }
        graph->size = ++size;

        // create empty edges by size
        graph->edges = malloc(sizeof(Edge) * size);

        // initialize edges BE CAREFUL about file pointer
        rewind(fp);
        for (int i = 0; i < size; i++)
        {
            fscanf(fp, "%c%c %d\n", &graph->edges[i].begin, &graph->edges[i].end, &graph->edges[i].weight);
        }

        fclose(fp);
        return graph;
    }
}

char *createUniques(Graph *graph)
{

    // create empty letters list 2 times plus 1 (for '\0 last char') the size of the graph
    /* NOTE: Allocate double size for space begin and end of the edges */
    const int letterSize = sizeof(char) * graph->size * 2 + 1;
    char *letter = malloc(letterSize);

    // Combine letters from edge begin char and edge end char
    for (size_t i = 0; i < graph->size; i++)
    {
        letter[i] = graph->edges[i].begin;
        letter[i + graph->size] = graph->edges[i].end;
    }

    // sort letters by bubble sort
    for (size_t step = 0; step < letterSize; step++)
    {
        for (size_t i = 0; i < letterSize - 1; i++)
        {
            if (strcmp(&letter[i], &letter[i + 1]) > 1)
            {
                int temp = letter[i];
                letter[i] = letter[i + 1];
                letter[i + 1] = temp;
            }
        }
    }

    // initialize empty unique

    char *uniques = malloc(sizeof(char));

    // remove duplicates from letters
    int q = 0;
    for (size_t i = 0; i < letterSize - 1; i++)
    {
        if (letter[i] == letter[i + 1])
        {
            uniques[q] = letter[i];
            uniques = realloc(uniques, sizeof(uniques) + sizeof(char));
            q++;
        }
    }

    uniques[++q] = '\0'; 
    // DONT FORGET reallocate unique each time

    // Add '\0' at the end of the string

    // free unused variables
    free(letter);

    return uniques;
}

// Union find function
/* unionFind is for checking if the edge is a cycle.
If it is a cycle, do not add it to the minimum spanning tree */
char *unionFind(char *uniques, char cno1, char cno2, unsigned int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if(uniques[i] == cno2)
            uniques[i] = cno1;
    }
    

    return uniques;
}

// kruskal mst algorithm
Graph *kruskalMST(Graph *graph)
{
    // allocate empty graph and empty cno1, cno2, indexCno1 and indexCno2
    Graph *mst = malloc(sizeof(Graph));
    mst->edges = malloc(sizeof(Edge));
    mst->size = 0;

    char cno1, cno2;
    int indexCno1, indexCno2;

    // create uniques use createUniques function

    char* uniques = createUniques(graph);
    
    // find length of uniques string

    int len = 0;
    for (size_t i = 0; uniques[i] != '\0'; i++, ++len)
    {
        
    }

    // iterate graph edges
    int size = 0;
    for (size_t i = 0; i < len; i++)
    {
        // assign cno1, cno2 and their indexCno's BE CAREFUL with index of uniques
        indexCno1 = graph->edges[i].begin - 'A';
        indexCno2 = graph->edges[i].end - 'A';
        cno1 = uniques[indexCno1];
        cno2 = uniques[indexCno2];

        if(cno1 != cno2)
        {
            mst->edges[size].begin = graph->edges[i].begin;
            mst->edges[size].end = graph->edges[i].end;
            mst->edges[size].weight = graph->edges[i].weight;
            mst->size++;
            ++size;
            mst->edges = realloc(mst->edges, sizeof(Edge) * (size + 1));
        }
        unionFind(uniques, cno1, cno2, len);
    }
    

    // check if begin and end are in the same set
    


    // add to mst if they are not in the same set,  DONT FORGET reallocte mst edges

    // update uniques use unionFind function

    return mst;
}

// sort edges by weight use bubble sort
Graph *sortEdges(Graph *graph)
{
    for (size_t step = 0; step < graph->size; step++)
    {
        for (size_t i = 0; i < graph->size - 1; i++)
        {
            if (graph->edges[i].weight > graph->edges[i + 1].weight)
            {
                Edge temp = graph->edges[i];
                graph->edges[i] = graph->edges[i + 1];
                graph->edges[i + 1] = temp;
            }
        }
    }

    return graph;
}

int main()
{
    // create graph;
    Graph *graph = createGraph("graph.txt");

    // sort graph for kruskal algorithm when getting minimum weight
    graph = sortEdges(graph);

    // kruskal minimum spanning tree
    Graph *mst = kruskalMST(graph);

    // print minimum spanning tree
    for (int i = 0; i < mst->size; i++)
    {
        printf("%d.) %c%c %d\n", (i + 1), mst->edges[i].begin, mst->edges[i].end, mst->edges[i].weight);
    }

    // calculate total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < mst->size; i++)
    {
        totalWeight += mst->edges[i].weight;
    }
    printf("Total weight of the minimum spanning tree: %d\n", totalWeight);

    // dont forget to free memory otherwise you will get memory leak
    free(graph);
    free(mst);

    return 0;
}