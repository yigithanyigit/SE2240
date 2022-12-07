#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *build_min_heap(int *arr, int n);
void min_heapify(int *arr, int n, int i);
int left(int index);
int right(int index);
void swap(int *a, int *b);
void test();


int *build_min_heap(int *arr, int n) {
	// TODO: Fill this function.

	int *newArray = malloc(n * (sizeof(arr) * sizeof(arr[0])));

	for (size_t q = 0; q < n; q++)
	{
		newArray[q] = arr[q];
	}
	
	int starterIndex = (n / 2);

	for (int i = starterIndex; i >= 0; i--)
	{
		min_heapify(newArray, n, i);
	}
	
	return newArray;
}

void min_heapify(int *arr, int n, int i) {
	// TODO: Fill this function.
	int l = left(i);
	int r = right(i);
	int largest ;
	if(l < n && arr[l] < arr[i])
	{
		largest = l;
	}
	else {
		largest = i;
	}

	if(r < n && arr[r] < arr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		min_heapify(arr, n, largest);
	}
	
}

int left(int index) {
	// TODO: Fill this function.

	return (2*index) + 1;
}

int right(int index) {
	// TODO: Fill this function.
	return 2*index + 2;
}
void swap(int *a, int *b) {
	// TODO: Fill this function;
	int temp = *a;
	*a = *b; 
	*b = temp;
}

void test() {
	// TODO: Do your tests here.
	int arr[] = {3,2,1,15,5,4,45};

	int n = sizeof(arr) / sizeof(arr[0]);

	int* newArray = build_min_heap(arr, n);

	for (size_t i = 0; i < n; i++)
	{
		printf("oldArray: %d NewArray: %d\n", arr[i], newArray[i]);
	}
	

}

