
/*
#include <time.h>
#include <stdio.h>
#include <limits.h>
#define ARR_SIZE 142

void sort(long long arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t k = 0; k < size - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                long long int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

void solution(long long int arr[], int n)
{
    arr[1] = 3;
    arr[2] = 5;
    int finalIndex = 3, size = finalIndex;
    int flag = 0;
    for (size_t i = 1; finalIndex <= n; i++)
    {
        flag = 0;
        for (size_t j = 1; j <= i; j++)
        {
            flag = 0;
            long long int s = arr[i] * arr[j];
            //printf("%lld %lld %lld %d\n", arr[i], arr[j], s,  size);

            //
            for (size_t k = 1; k < finalIndex; k++)
            {
                if (arr[k] == s)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                arr[size] = s;
                size++;
                if(size == n)
                    break;
            }
        }
        finalIndex = size;
    }
   sort(arr, finalIndex);
}

int main()
{
    long long int arr[300];
    solution(arr, 170);
    for (size_t i = 1; i <= 170; i++)
    {
       printf("%lld %d\n", arr[i], i);
    }
    printf("%lld\n", arr[50]);
}


#include "stdio.h"
#include "string.h"

void sort(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t k = 1; k < size - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

// Implement your solution in this function
int izmirNumber(int n)
{
    int arr[ARR_SIZE];
    arr[0] = 0;
    arr[1] = 3;
    arr[2] = 5;
    int finalIndex = 3, size = finalIndex;
    int flag = 0;
    for (size_t i = 1; finalIndex <= ARR_SIZE; i++)
    {

        flag = 0;
        for (size_t j = 1; j <= i; j++)
        {
            flag = 0;
            int s = arr[i] * arr[j];

            // printf("%d %d %d %d\n", arr[i], arr[j], s,  size);
            if (s > 0)
            {
                for (size_t k = 1; k < finalIndex; k++)
                {
                    if (arr[k] == s)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    arr[size] = s;
                    size++;
                    if (size == ARR_SIZE)
                        break;
                }
            }
            else
                break;
        }
        finalIndex = size;
        sort(arr, finalIndex);
    }
    sort(arr, finalIndex);
    for (size_t i = 1; i <= ARR_SIZE; i++)
    {
        printf("%d %d\n", arr[i], i);
    }

    return arr[n + 1]; // return the answer
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", izmirNumber(n));
}
*/

#include "stdio.h"
#include "math.h"
#include "limits.h"
#define SIZE 40

void sort(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t k = 0; k < size - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

int lookDuplicates(int *arr, int size, int key)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }

    return 0;
}

// Implement your solution in this function
int izmirNumber(int n)
{
    int arr[600];
    int size = 0;
    for (size_t i = 0; i <= SIZE; i++)
    {
        for (size_t j = 0; j <= SIZE; j++)
        {
            long long int res = (long long int)(pow(3, j) + 1e-9) * (long long int)(pow(5, i) + 1e-9);
            if (res <= INT_MAX && res > 1)
            {
                
                if (lookDuplicates(arr, size, (int)res) == 0)
                {
                    
                    arr[size] = (int)res;
                    size++;
                    //printf("%d %d\n", res, size);
                    sort(arr, size);
                }
            }
        }
        
    }
    sort(arr, size);

    for (size_t i = 0; i <= size; i++)
    {
        //printf("%d %d\n", arr[i], i);
    }

    return arr[n - 1]; // return the answer
}

// !!! DO NOT CHANGE main function! It will test your solution.
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", izmirNumber(n));
}