#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Do not forget to do big oh analyses for each function.

void max_selection_sort(int *arr, int n);
void max_heap_sort(int *arr, int n);
void build_max_heap(int *arr, int n);
void max_heapify(int *arr, int n, int i);
int left(int index);
int right(int index);
void swap(int *a, int *b);
void max_insertion_sort_accuracy_test();
void max_heap_sort_accuracy_test();
void comparison_test();
void printArray(int *arr, int n);
void printArrayReverse(int *arr, int n);

void max_selection_sort(int *arr, int n) // O(n²)
{
	// TODO: Fill this function.
	for (int step = 0; step < n - 1; step++)
	{
		int min_idx = step;
		for (int i = step + 1; i < n; i++)
		{

			if (arr[i] > arr[min_idx])
				min_idx = i;
		}

		swap(&arr[min_idx], &arr[step]);
	}
}

void max_heap_sort(int *arr, int n) // O(n)
{
	// TODO: Fill this function.
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);

		max_heapify(arr, i, 0);
	}
}

void build_max_heap(int *arr, int n) // O(n)
{
	// TODO: Fill this function.
	for (int i = n / 2 - 1; i >= 0; i--)
	{

		max_heapify(arr, n, i);
	}
}

void max_heapify(int *arr, int n, int i) // O(logN)
{
	// TODO: Fill this function.
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
		max_heapify(arr, n, largest);
	}
}

int left(int index) // O(1)
{
	// TODO: Fill this function.
	return 2 * index + 1;
}

int right(int index) // O(1)
{
	// TODO: Fill this function.
	return 2 * index + 2;
}

void swap(int *a, int *b) // O(1)
{
	// TODO: Fill this function;
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArrayReverse(int arr[], int n) // O(n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n");
}

void printArray(int arr[], int n) // O(n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void max_selection_sort_accuracy_test() // O(n²)
{
	printf("STARTING MAX SELECTION SORT ACCURACY TEST\n");
	// TODO: Do your tests here.
	int arr[] = {1, 12, 9, 5, 6, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	build_max_heap(arr, n);
	max_selection_sort(arr, n);
	printArray(arr, n);
	printf("ENDING MIN SELECTION SORT ACCURACY TEST\n\n");
}

void max_heap_sort_accuracy_test() // O(nlogn)
{
	printf("STARTING MAX HEAP SORT ACCURACY TEST\n");
	// TODO: Do your tests here.
	int arr[] = {1, 12, 9, 5, 6, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	build_max_heap(arr, n);
	max_heap_sort(arr, n);
	printArrayReverse(arr, n);
	printf("ENDING MAX HEAP SORT ACCURACY TEST\n\n");
}

void comparison_test() // O(n²)
{
	int arr[] = {1, 12, 9, 5, 6, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("STARTING COMPARISON TEST\n");
	clock_t t;
	t = clock();
	max_heap_sort(arr, n);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("Max Heap Sort Taken %f time \n\n\n", time_taken);

	t = clock();
	max_selection_sort(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("Max Selection Sort Taken %f time \n\n\n", time_taken);

	printf("ENDING COMPARISON TEST\n\n");

	// Write your conclusion here:
	// HeapSort is more faster and stable as like selectionSort
	// A lot of Pros, but only on Con that is hard to implement rather than others.
	// Also my time functions says HeapSort is taking long than the selectionSort becuse my array is small if we take this array as
	// infinite then heapSort is more better than this.
}
