#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	int w,x,y;
	int i,j,k=0;

	//Finding the length of string inputs str1 and str2
	x = strlen(str1);
	y = strlen(str2);

	//Adding the string lengths to obtain overall length of concatenated strings
	w = x+y;

	//Assigning memory for holding the concatenated string
	z = malloc(w*sizeof(char));

	/*write your implementation here*/

	//Iterating through str1 and str2 and concatenating the two inputed strings
	for (i=0; i<x;i++)
	{
		z[k++] = str1[i];
	}


	for (j=0; j<=y;j++)
	{
		z[k++] = str2[j];
	}

	/* finally, return the string*/

	return z;
	
}
