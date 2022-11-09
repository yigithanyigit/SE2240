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