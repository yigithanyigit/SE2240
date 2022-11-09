// Heapiyf
// Swap max and max in the min subtree
// Repeat until array done
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int index)
{
    return 2 * index + 1;
}

int right(int index)
{
    return 2 * index + 2;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int leftIndex = left(i);
    int rightIndex = right(i);

    if (leftIndex < n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // For max heap
        heapify(arr, n, i);
    }

    // Sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
}