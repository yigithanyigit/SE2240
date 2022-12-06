#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define NUMBER_OF_VERTICES 4

// 
// https://www.thecrazyprogrammer.com/2017/05/topological-sort.html


int main()
{
    int indegree[SIZE], visited[SIZE];


    int matrix[4][4] = {{0,1,1,0}, {0,0,0,1}, {0,0,0,1}, {0,0,0,0}};

    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        indegree[i]=0;
        visited[i]=0;
    }

    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        for (int j = 0; j < NUMBER_OF_VERTICES; j++)
        {
            indegree[i] += matrix[j][i];
        }
        
    }

    int counter = 0;
    while (counter < NUMBER_OF_VERTICES)
    {
        for (int i = 0; i < NUMBER_OF_VERTICES; i++)
        {
            if(indegree[i] == 0 && visited[i] == 0)
            {
                printf("%d ", i + 1);
                visited[i] = 1;
            }

            for (int j = 0; j < NUMBER_OF_VERTICES; j++)
            {
                if(matrix[j][i] == 1)
                    indegree[i]--;
            }
            
        }
        counter++;
    }
    
           

    return 0;
}