#include <stdio.h>
#include <string.h>
#include <limits.h>

#define V 9

//  https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/


void randomDirectedGraphGenerator(int n, int arr[][n])
{

    for (size_t k = 1; k < n; k++)
    {
        int number = RandomIntGenerator() % n + 1;
        for (size_t i = 1; i < n; i++)
        {
            arr[0][i] = i;
            arr[i][0] = arr[0][i];
        }
    }

    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            if (i != j)
            {
                arr[i][j] = RandomIntGenerator() % 10;
            }
        }
    }
}

void printGraph(int n, int arr[][n])
{

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }
}

int min(int x1, int x2)
{
    return x1 < x2 ? x1 : x2;
}
/*
void dijkstraShortestPath(int n, int arr[][n], int sourceIndex, int targetIndex)
{
    int allVerticeSet[n][1];
    int visitedVertices[n];
    int minValue = 0, minIndex, currentIndex = sourceIndex;

    memset(allVerticeSet, 0, sizeof(allVerticeSet));

    while (n >= 0) // All vertice Counter
    {
        // visitedVertices[i] = sourceIndex;
        for (size_t j = 0; j < n; j++)
        {
            if (arr[currentIndex][j] > 0)
            {
                allVerticeSet[j][1] = arr[currentIndex][j] + allVerticeSet[j][1];
                if (minValue != 0 && arr[currentIndex][j] < minValue)
                {
                    minValue = arr[currentIndex][j];
                    minIndex = j;
                }
                else
                {
                    minValue = arr[currentIndex][j];
                    minIndex = j;
                }
            }
        }
        currentIndex = minIndex;
        n--;
    }

    for (size_t i = 0; i < 3; i++)
    {
        printf("%d ", allVerticeSet[i][1]);
    }
}
*/

/* COPIED FROM GFG */
int minDistance(int dist[], int sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int n, int arr[][n], int source)
{
    int dist[n];

    int shortest[n];
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, shortest[i] = 0;

    dist[source] = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        int u = minDistance(dist, shortest);

        shortest[u] = 1;

        for (size_t j = 0; j < n; j++)
        {
            if (shortest[j] != 1 && arr[u][j] && dist[u] != INT_MAX && dist[u] + arr[u][j] < dist[j])
                dist[j] = dist[u] + arr[u][j];
        }
    }

    printSolution(dist);
}

int main()
{
    randomGeneratorInit();

    const int n = 4;
    // const int V = 9;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    // randomDirectedGraphGenerator(n, arr);
    // printGraph(n, arr);
    // dijkstraShortestPath(n, arr, 1, 3);
    dijkstra(V, graph, 0);
}