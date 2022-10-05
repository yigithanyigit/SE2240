#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5


int isValid(char * comb)
{
	char pasw[SIZE];
	FILE* fptr;
	if ((fptr = fopen("password.txt","r")) == NULL)
	{
       printf("Error! opening file");
       exit(1);
   	} 
   	
   	fscanf(fptr,"%[^\n]", pasw);

	if(strcmp(comb, pasw) == 0)
	{
		printf("%s", comb);
		fclose(fptr);
		return 1;
	} else
	{
		fclose(fptr);
		return 0;
	}
	
}

int bruteForce()
{
	/*
	char str[ENOUGH];
	sprintf(str, "%d", 42);	
	*/
	
	for(int i = 0; i < 100000; i++)
	{
		char str[SIZE + 1];
		sprintf(str, "%05d", i);
		printf("%s ", str);
		if(isValid(str) == 1)
		{
			
			return 1;
		}
	}

	
	
	return 0;
   	
}

int main()
{
	
	bruteForce();
	return EXIT_SUCCESS;
}
