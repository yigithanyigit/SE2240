#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX / 2

int min(int a, int b)
{
    // Return 1 if a smaller than b else return 0
    return (a < b) ? 1 : 0;
}

void printSolution(int y, int dist[][y])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (dist[i][j] == INF)
                printf("%10s", "INF");
            else
                printf("%10d", dist[i][j]);
        }
        printf("\n");
    }
}
void floyWarshall(int y, int adjMatrix[][y])
{
    int distances[y][y];


    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            distances[i][j] = adjMatrix[i][j];
        }
    }

    for (int k = 0; k < y; k++)
    {
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (min(distances[i][k] + distances[k][j], distances[i][j]))
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    printSolution(y, distances);
}

int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    int distances[V][V];

    floyWarshall(V, graph);
    return 0;
}