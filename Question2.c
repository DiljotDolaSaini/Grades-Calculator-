#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	int i;
	int total_students;

	/*write your implementation here*/
	
	FILE *input_file = fopen(filename,"r");
	fscanf(input_file,"%d",&total_students); // To store the number of students in class from the first line of the file

	*sizePtr = total_students;
	
	student **class_list = calloc(*sizePtr,sizeof(student*)); //Allocating memory for array of pointers class_list

	//Updating indices in array of pointers and members of structures accordingly
	
	for(i=0;i< *sizePtr;i++){
		class_list[i] = malloc(sizeof(student));
		fscanf(input_file,"%d",&(class_list[i]->student_id));
		fscanf(input_file,"%s",class_list[i]->first_name);
		fscanf(input_file,"%s",class_list[i]->last_name);
	}

	fclose(input_file);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	/*write your implementation here and update the return accordingly*/
	int i;

	for(i=0;i<=size-1;i++){

		//Checking if each student's id matches the inputed idNo.

		if (list[i] -> student_id == idNo)
		{
			return i;
		}
	}
	return -1;
}

void input_grades(char *filename, student **list, int size)
{
	int i,j;
	int n;
	int index;


	/*write your implementation here*/

	FILE *input_file = fopen(filename,"r");


	for(i=0;i<size;i++){
		fscanf(input_file,"%d",&index); //Scans the student_id

		// Using the function find() to gain index in array of pointers list of the id that is read from the file
		n = find(index,list,size);

		//Updating the projects grades using the index gained above

		for(j=0;j<size;j++){
			if (n == j){
				fscanf(input_file,"%d",&(list[j]->project1_grade));
				fscanf(input_file,"%d",&(list[j]->project2_grade));
			}
		}
	}

	fclose(input_file);
}


void compute_final_course_grades(student **list, int size)
{
	int i;

	/*write your implementation here*/

	//Calculating average of the two projects for final grade and updating final grades accordingly

	for(i=0;i<size;i++){
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade)/2.0;
	}



}

void output_final_course_grades(char *filename, student **list, int size)
{
	int i;

	/*write your implementation here*/

	FILE *output_file = fopen(filename,"w");
	fprintf(output_file,"%d\n",size); // Updates first line of the file with the number of students

	//The next lines are updated with respective student_ids and final_grades
	for(i=0;i<size;i++)
	{
		fprintf(output_file,"%d ",list[i]->student_id);
		fprintf(output_file,"%f\n",list[i]->final_grade);
	}

	fclose(output_file);
}

void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int i;
	int stop;

	for(i=0;i< *sizePtr;i++){
		if(list[i]->student_id == idNo){
			free(list[i]); //Free's the id that is withdrawn
			stop =i; //Gains index where the id was withdrawn from the array of pointers
			(*sizePtr)--; //Each time an id is withdrawn the size should go down by one
		}
	}

	for(i=stop; i< *sizePtr;i++){
		list[i] = list[i+1]; //Shifting the contents to the left after freeing the id that was withdrawn
	}

}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	int i;

	//This frees each index of the array of pointers
	for(i=0;i<*sizePtr;i++){
		free(list[i]);
	}

	free(list);
	*sizePtr = 0;

}
