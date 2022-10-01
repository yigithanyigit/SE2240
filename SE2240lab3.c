#include <stdio.h>
#include <stdlib.h>

#define N 100

int lineer_search(int *arr, int n, int key)
{
	int i;						// c1
	int iteration = 0;			//c2
	for(i = 0; i < n; i++)		//c3
	{
		if( key == arr[i])		//c4
		{
			return i;			//c5
		}
	}
	return -1;
}

// Big-O -> SUM( c1 + c2 + (n+1)c3 + (n)c4 + (n)c5) = c1 + c2 + c3 + nc3 + nc4 + nc5 = O(n)

int binary_search(int *arr, int n, int key)
{
	int i;					// c1
	int start = 0;			// c2
	int end = n - 1;		// c3

	int location;			// c4
	int iteration = 0;		// c5
	
	while( start < end )	// c6
	{
		int mid = (start + end) / 2;  // c7 
		
		if(arr[mid] < key)			  // c8
		{
			start = mid + 1;		  // c9
		} else 
		
		{
			end = mid;	              // c9
		}
		if (arr[mid] == key)		  //c10
		{
			
			location = mid;			  //c11
			
			
			start = end + 2; // Break the loop aka. break;
		}
		else
		{
			location = -1;           //c11
		}
		++iteration;
	}
	printf("Binary Search Iteration : %d\n",iteration);
	
	return location; 				//c12
	
}
// k for iterations 
//Big-O -> SUM(c1 + c2 + c3 + c4 + c5 + c6+(n/2^k(c6 + c7 + c8 + c9 + c10 + c11) + c12) = 1
/*
* firstly we have n elements and after every iteration we going to divide our number of elements
* i.e(n/2, (n/2)/2, ((n/2)/2) / 2) so at the end we have n/2^k = 1 and if we apply both sides log then
* logn = log2^k, in final Big-O(logN)
*
*/

int main()
{
	
	int arr[N];
	
	int i;
	for(i = 0; i < N; i++)
	{
		arr[i] = i;
	}
	
	
	int result = binary_search(arr, i, 35);
	
	printf("%d\n", result);
	
	result = lineer_search(arr, i, 35);
	
	printf("%d\n", result);
	
	return 0;	
}
