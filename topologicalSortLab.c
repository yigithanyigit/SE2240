#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define NUMBER_OF_VERTICES 8

/**
 * LINKED LIST IMPLEMENTATION
 */

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;

typedef struct LINKED_LIST_NODE_s
{

    LINKED_LIST_NODE next; /* Do not change order */

    void *data;

} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;

typedef struct LINKED_LIST_s
{

    LINKED_LIST_NODE head; /* May overlap with next. */

} LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST list_init()
{
    LINKED_LIST list = malloc(sizeof(LINKED_LIST_t));
    list->head = NULL;
    return list;
}

LINKED_LIST_NODE list_node_init(void *data)
{
    LINKED_LIST_NODE node = malloc(sizeof(LINKED_LIST_NODE_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void list_prepend(LINKED_LIST list, void *data)
{
    LINKED_LIST_NODE newNode = list_node_init(data);
    newNode->next = list->head;
    list->head = newNode;
}

void list_append_last(LINKED_LIST list, void *data)
{
    /* LIST HEAD NULL ISE ONA CASE YARAT*/
    LINKED_LIST_NODE node = list->head;
    if (node == NULL)
    {
        list->head = list_node_init(data);
        return;
    }
    while (node->next != NULL)
        node = node->next;

    node->next = list_node_init(data);
}

void list_print(LINKED_LIST list)
{
    LINKED_LIST_NODE node = list->head;
    while (node != NULL)
    {
        printf("%d ", *(int *)(node->data));
        node = node->next;
    }
}

void dfs(int graph[][SIZE], int visited[SIZE], int node, LINKED_LIST list)
{
    // We do N iteration, N is number of vertices also we do this for E times which E is edge so final Big-O is
    // O(EV) == O(N)
    int counter = 0;
    for (int i = 0; i < NUMBER_OF_VERTICES; i++) // O(N + 1)
    {
        if (graph[node][i] == 1 && visited[i] == 0) // O(1)
        {
            counter += 1;                 // O(1)
            dfs(graph, visited, i, list); // O(1)
        }
    }
    if (visited[node] == 0) // O(1)
    {
        int *key = malloc(sizeof(int)); // O(1)
        *key = node + 1;                // O(1)
        list_prepend(list, key);        // O(1)
        visited[node] = 1;              // O(1)
    }
    return;
}

void topSortDfs(int graph[][SIZE], int visited[SIZE], int node, LINKED_LIST list)
{
    /* GIVE EVERY NODE AS STARTER NODE*/
    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        dfs(graph, visited, i, list);
    }
}

void sourceRemoval(int graph[][SIZE], int visited[SIZE], int indegree[SIZE], LINKED_LIST list)
{
    // We do N iteration, N is number of vertices also we do this for E times which E is edge so final Big-O is
    // O(V + V^2) = O(V^2)
    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        for (int j = 0; j < NUMBER_OF_VERTICES; j++)
        {
            indegree[i] += graph[j][i];
        }
        // printf("%d ", indegree[i]);
    }

    int numVisitedVertices = 0;
    while (numVisitedVertices <= 0) // O(N + 1)
    {
        for (int i = 0; i < NUMBER_OF_VERTICES; i++) // O(N + 1)
        {
            if (indegree[i] == 0 && visited[i] == 0)
            {
                numVisitedVertices++; // O(1)
                int *key = malloc(sizeof(int)); // O(1)
                *key = i + 1;                   // O(1)
                visited[i] = 1; // O(1)
                list_append_last(list, key); // O(1)

                for (int j = 0; j < NUMBER_OF_VERTICES; j++) // O(N + 1)
                {
                    if (graph[i][j] == 1) // O(1)
                    {
                        indegree[j]--; // O(1)
                    }
                }
                /**
                 * Print Degrees
                 *
                 */
                /*
                printf("\n");
                for (int q = 0; q < NUMBER_OF_VERTICES; q++)
                {
                    printf("%d ", indegree[q]);
                }
                */
            }
        }
    }
}

int main()
{
    // int matrix[SIZE][SIZE] = {{0,1,1,0}, {0,0,0,1}, {0,0,0,1}, {0,0,0,0}};
    int matrix[SIZE][SIZE] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    int visited1[SIZE], visited2[SIZE], indegree[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited1[i] = 0;
        visited2[i] = 0;
        indegree[i] = 0;
    }

    LINKED_LIST list = list_init();
    LINKED_LIST list2 = list_init();

    topSortDfs(matrix, visited1, 0, list);
    sourceRemoval(matrix, visited2, indegree, list2);

    printf("\n");
    list_print(list2);
    printf("\n");
    list_print(list);

    return 0;
}
