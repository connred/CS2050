#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ID;
	float salary;
	int age;
} Employee;

Employee **createEmployeeArray(int maxLength);
int addNewEmployee(Employee *p, Employee **arr);
void * freeEmployeeArray(Employee **arr);
void printArray(Employee **arr);

int main(int argc, char *argv[])
{
	int maxLength = 10;
	int currentIndex = 0;
	Employee** arr = createEmployeeArray(maxLength);
	*((int*)arr) = currentIndex;
	arr = (Employee**)((int*)arr+1);
	printf("Max length of array from [-2] === %d\n",*((int*)arr-2) );
	while(*((int*)arr-1) < *((int*)arr-2)){
		Employee emp1 = {17,98323.12,27};
		Employee *ptr_emp;
		ptr_emp = &emp1;
		currentIndex = addNewEmployee(ptr_emp,arr);
		*((int*)arr-1) = currentIndex;
		printf("%d\n",*((int*)arr-1));
	}
	//printArray(arr);
	Employee* empArray = freeEmployeeArray(arr);
}

Employee ** createEmployeeArray(int len)
{
	Employee** arr = (Employee**)malloc(sizeof(Employee)*len+(sizeof(int)*2));
	if(!arr){
		printf("Allocation failed\n"); // Ensure the allocation happened
		exit(1);
	}
	*((int*)arr) = len;
	arr = (Employee**)((int*)arr+1);
	Employee ***p = &arr;
	return (*p);
}
int addNewEmployee(Employee* ptr_emp, Employee** arr)
{

	*((Employee*)arr) = *ptr_emp;
	return (*((int*)arr-1)+1);
}
void *freeEmployeeArray(Employee **arr)
{
	arr = (Employee**)((int*)arr-1);
	arr = (Employee**)((int*)arr-2);
	arr = NULL;
	free(arr);
	return arr;
}
/*void printArray(Employee **arr)
{
	int size = *((int*)arr-2);
	printf("%d\n",size );
	for(int i = 0; i < size; i++)
	{
		printf("ID\tSAL\tAGE");
		for(int i = 0; i < size; i++)
		{
			printf("\n%d\t%.2f\t%d", *(arr)[i].ID,*(arr)[i].salary,*(arr)[i].age);
	}
}*/
