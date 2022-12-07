#include <stdio.h>
#include <stdlib.h>

/**
 * LINKED LIST IMPLEMENTATION
*/

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;

typedef struct LINKED_LIST_NODE_s{

	LINKED_LIST_NODE next; /* Do not change order */

	void *data;

} LINKED_LIST_NODE_t[1];


typedef struct LINKED_LIST_s *LINKED_LIST;

typedef struct LINKED_LIST_s{

  	LINKED_LIST_NODE head; /* May overlap with next. */

} LINKED_LIST_t[1], *LINKED_LIST;


// DO BIG OH analysis of algorithm


LINKED_LIST list_init()
{
    LINKED_LIST list = malloc(sizeof(LINKED_LIST_t));
    list->head = NULL;
    return list;
}


LINKED_LIST_NODE list_node_init(void* data)
{
    LINKED_LIST_NODE node = malloc(sizeof(LINKED_LIST_NODE_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void list_prepend(LINKED_LIST list, void* data)
{
    LINKED_LIST_NODE newNode = list_node_init(data);
    newNode->next = list->head;
    list->head = newNode;
}

void list_append_last(LINKED_LIST list, void* data)
{
    /* LIST HEAD NULL ISE ONA CASE YARAT*/
    LINKED_LIST_NODE node = list->head;
    while (node->next != NULL)
        node = node->next;
    
    node->next = list_node_init(data);

}

void list_print(LINKED_LIST list)
{
    LINKED_LIST_NODE node = list->head;
    //printf("%d ", *(int*)(node->data));
    while (node->next != NULL)
    {
        printf("%d ", *(int*)(node->data));
        node = node->next;
    }
}


int main()
{
    LINKED_LIST list = list_init();
    int n1 = 15, n2 = 27 ,n3 = 35, n4 = 41;
    list_prepend(list, &n1);
    list_prepend(list, &n2);
    list_prepend(list, &n3);
    list_prepend(list, &n4);

    list_print(list);


    return 0;

}


