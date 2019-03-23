#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ID;
	float salary;
	int age;
} Employee;

Employee **createEmployeeArray(int); // allocates correct amount of memory needed for the array based on maxLength var
int addNewEmployee(Employee *, Employee **); // takes a pointer that points to a stuct and adds that struct to the overall array
Employee* findByAge(Employee**, int);
void * freeEmployeeArray(Employee **); // gets rid of the int vars before 0 index. then frees the array

int main(int argc, char *argv[])
{
	FILE *f;
	f = fopen("employee.csv", "r"); // open file

	//Get # of records from first line of file
	int maxLength;
	fscanf(f, "%d", &maxLength);
	Employee** arr = createEmployeeArray(maxLength); //creates allocated array and stores the size and current index before [0]

	printf("Max length of array from [-2] === %d\n",*((int*)arr-2) ); // debug info
	while(*((int*)arr-1) < *((int*)arr-2))
	{

		Employee employ = {};
		fscanf(f, "%d,%f,%d", &employ.ID, &employ.salary, &employ.age);

		Employee *ptr_emp = &employ;
		if(addNewEmployee(ptr_emp,arr) != 1){

			break;
		}
		*((int*)arr-1) += 1;
	}

	// Additional addNewEmployee to test that we error check correctly
	Employee employ = {0,0,0}; // fake info
	Employee *ptr_emp = &employ; // pointer
	addNewEmployee(ptr_emp,arr); //call

	Employee* ageMatch = findByAge(arr,55);
	Employee ageFinal = {ageMatch->ID,ageMatch->salary,ageMatch->age};
	printf("%d\t%f\t%d\n",ageMatch->ID,ageMatch->salary,ageMatch->age);


	Employee* empArray = freeEmployeeArray(arr); // frees array
}

Employee ** createEmployeeArray(int len)
{
	Employee** arr = (Employee**)malloc(sizeof(Employee)*len+(sizeof(int)*2)); //allocates correct ammount of memory (amount of structs + two int for currentdex and size)
	if(!arr){
		printf("Allocation failed\n"); // Ensure the allocation happened
		exit(1);
	}

	*((int*)arr) = len; // add size to array
	arr = (Employee**)((int*)arr+1);
	*((int*)arr) = 0; // adds the current index to the array
	arr = (Employee**)((int*)arr+1);

	Employee ***p = &arr; // pointre for the array created
	return (*p);
}
int addNewEmployee(Employee* ptr_emp, Employee** arr)
{
	if(*((int*)arr-1) < *((int*)arr-2))
	{
			*((Employee*)arr) = *ptr_emp; //add struct to array
			return 1;
	} else {
		printf("There is no more memory allocated for the array...\n");
		return -1;
	}
	return -1;
}
Employee * findByAge(Employee**arr,int num)
{
	int size = *((int*)arr-2);

	for(int i = 0; i < size; i++)
	{

			if((int)((Employee*)arr[i])->age == num)
			{
				return ((Employee*)arr[i]);
			}
	}




}
void *freeEmployeeArray(Employee **arr)
{
	arr = (Employee**)((int*)arr-1); //eliminate ints
	arr = (Employee**)((int*)arr-2);
	arr = NULL; // eliminate structs
	free(arr); // free mmemory
	return arr;
}
