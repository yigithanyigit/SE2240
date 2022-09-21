#include <stdio.h>

int insideFunction(int j)
{
	return 2*j - 1;
}

int summation(int a, int b, int (*insideFunc)(int))
{
	int sum = 0;
	int i;
	for(i = a; i <=b; i++)
	{
		sum += (*insideFunc)(i);
	}
	
	return sum;
}

int insideFunction2(int j)
{
	return 2*j + 1;
}

int multiplication(int a, int b, int (*insideFunc)(int))
{
	int mul = 1;
	int i;
	for(i = a; i <= b; i++)
	{
		mul *= (*insideFunc)(i);
	}
	
	return mul;
}


int factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n-1);
}

int iter(int a)
{
	int sum = 1;
	while(a>=1)
	{
		sum *= a;
		a--;
	}
	return sum;
	
}

int fibSeq(int starter)
{
	if(starter == 0) return 0;
	if(starter == 1) return 1;
	
	return fibSeq(starter - 1) + fibSeq(starter - 2);
}

int fibSeqIter(int starter)
{
	int first, second;
	first = 0;
	second = 1;
	
	int newElem, elem, prevElem, i;
	elem = 0;
	
	
	for(i = 0; i <= starter - 1; i++){
		if (!elem) {
			elem = first;
			prevElem = second;
		}
		newElem = prevElem + elem;
		prevElem = elem;
		elem = newElem;
	}
	
	return newElem;
	
}


int main()
{
	//printf("%d ", summation(3,6,insideFunction));
	//printf("%d ", multiplication(3,6,insideFunction2));
	//printf("%d ", factorial(5));
	//printf("%d ", iter(6));
	//printf("%d ", fibSeq(6));
	printf("%d ", fibSeqIter(6));
	
	
	return 0;
}
