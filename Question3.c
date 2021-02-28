#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"


char **read_words(const char *input_filename, int *nPtr){
	
    int num;
    int i;

    /*write your implementation here*/

    // Opening file and reading out the number of words stored in file
    FILE *input_file = fopen(input_filename,"r");
    fscanf(input_file,"%d",&num);
    *nPtr = num;

    //Allocating memory for storing the words in the file
    // Storing the words accordingly

    char **word_list = malloc(*nPtr * sizeof(char*));

    for(i=0;i< *nPtr;i++)
    {
    	word_list[i] = malloc(*nPtr * sizeof(word_list[i]));
    	fscanf(input_file,"%s",word_list[i]);

    }

    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/

	int i;

	//Checking which string comes first in the alphabet


	for(i =0; str1[i] != '\0' | str2[i] != '\0';i++){
		if (str1[i] - str2[i] > 0)
		{
			return 1;
		}

		else if (str1[i] - str2[i] < 0){
			return 0;
		}
	}

	return -1;

}

void sort_words(char **words, int size)


{
	int i=0,j=0;
	char *move; //Pointer needed for comparing next words with previous words

	/*write your implementation here*/


	while(i<size) //Iterates through all indices of the array of pointers
	{
		move = words[i]; //Move points to the next word each time
		j= i-1; //This is is need to initiate the value of j for the next while loop


		//Compare_str used to compare the two words just like compared in the dictionary, letter by letter
		while(j>=0 && (compare_str(words[j],move) == 1)) //j is need for iterating through the words before i'th word
		{
			words[j+1] = words[j]; //swaps previous word with next word
			j = j-1; //j updates - keeps checking with the previous words before hitting the i'th word if it is alphabetically sorted correctly
		}
		words[j+1] = move; //This tells us that we can move on the the next index for i
		i++;
	}

}

void swap(char **str1, char **str2){

	char *temp;

	/*this is a helper function that you can implement and use to facilitate your development*/

	//Swapping str1 and str2
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;

}

void sort2_words(char **words, int size){



	int i; //Refers to the number of times we go through the array of pointers -> word
	int j; //Refers to the index in the array of pointers
	/*write your implementation here*/

	//Going through the array of pointers each time and swapping the words to sort alphabetically until all the words are sorted
	for(i=0;i < size -1 ;i++)
	{
		for(j=0; j< (size-1)-i ;j++)
		{
			if(compare_str(words[j],words[j+1]) == 1) //Call compare_str to alphabetically compare the two strings
			{
				swap((&words[j]),(&words[j+1])); //Using swap to alphabetically sort each word of each iteration of i
			}
		}
	}
}

