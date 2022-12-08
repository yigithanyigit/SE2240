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
            counter += 1;   // O(1) 
            dfs(graph, visited, i, list);  // O(1)
        }
    }
    if (visited[node] == 0) // O(1)
    {
        int *key = malloc(sizeof(int)); // O(1)
        *key = node + 1; // O(1)
        list_prepend(list, key); // O(1)
        visited[node] = 1; // O(1)
    }
    return;
}
int main()
{

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
    int visited[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = 0;
    }

    LINKED_LIST list = list_init();

    /* GIVE EVERY NODE AS STARTER NODE*/
    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        dfs(matrix, visited, i, list);
    }
    

    list_print(list);

    return 0;
}
