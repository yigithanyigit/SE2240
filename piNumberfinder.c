#include <stdio.h>

float PIfinder(int n)
{
	float PI = 0;
	int i;
	
	for(i = 0; i <= n; i++)
	{
		PI += (1.0f/(4*i + 1)) - (1.0f/(4*i + 3));
	}
	
	
	return PI * 4;
}



int main()
{

	float pi = PIfinder(100000);
	printf("%f", pi);
	return 0;
}
