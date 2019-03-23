////////////
// Lab 4  //
////////////

#include <stdio.h>
#include <stdlib.h>

//Define the structure to be used in the array
typedef struct
{
	int ID;
	float salary;
	int age;
} Employee;


Employee* createArray(char *filename); // Create array prototype using a structure array as return value
int numOfEmployee(Employee*); // Obtains the number of entries from -1 in the array
void avg(Employee*,float *, float *); // Computes averages

int main(int argc, char *argv[]) {
	// Make sure an input file is stated, otherwise exit the program
	if ( argc != 2){
		printf("Insufficient arguments! load the correct number of input arguments");
		exit(1);
	}

	char *filename = argv[1]; // Obtains file name from argue ments

	Employee* arr = createArray(filename); // Create struc array from the createarray function
	float avgSal;
	float avgAge;
	avg(arr,&avgAge,&avgSal); // get averages by sending pointers and array to functions

	printf("The average age is %.2f\nThe average salary is $%.2f", avgAge,avgSal); // print results

	//free the array
	arr = (Employee*)((int*)arr-1);
	free(arr);
}

Employee* createArray(char *filename)
{
	// Open file with filename
	FILE *f;
	f = fopen(filename, "r");

	//Get # of records from first line of file
	int size;
	fscanf(f, "%d", &size);

	//Allocate memory for the array, # or records + 1 int spot for size
	Employee* arr = (Employee*) malloc(sizeof(Employee)*size+sizeof(int));
	if(!arr){
		printf("Allocation failed\n"); // Ensure the allocation happened
		exit(1);
	}

	//hiding the size at [-1] of the array
	*((int*)arr) = size;
	arr = (Employee*)((int*)arr+1);

	// Fill the array with structures containing employee info
	for(int i = 0; i<size; i++)
	{
		fscanf(f, "%d,%f,%d", &arr[i].ID, &arr[i].salary, &arr[i].age);
	}
	fclose(f); // close file
	return arr; // return the completed array
}

int numOfEmployee(Employee* arr)
{
	return *((int*)arr-1);  // access arr[-1] to get size of arr
}

void avg(Employee* arr, float *age, float *sal)
{
	int n = numOfEmployee(arr); // get size
	float ageTot = 0;
	for (int i = 0; i < n; i++){
		ageTot += arr[i].age; //loop thru array of strucs accessing age and add them up
	}
	*age = (float)(ageTot / n); // final calculation
	float salTot = 0;
	for (int i = 0; i < n; i++){
		salTot += arr[i].salary;  //loop thru array of strucs getting salary and adding up
	}
	*sal = (float)(salTot / n); // final calculation
}
