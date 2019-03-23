#include <stdio.h>
#include <stdlib.h>
double * createArray(int, size_t);
void freeArray(double **);
int getArraySize(double *);

int main(void) {
	double *array = NULL;
	//free(array);
	int n = 100;
	
	array = createArray(n, sizeof(double));
	int size = 0;
	//array[-1] = 9;
	size = (int)getArraySize(array);

	
	printf("%d\n", size);

	//freeArray(&array);
}

double * createArray(int n, size_t a)
{
	int i;
	double *array = NULL;
	array = (double*)malloc((n+1)*sizeof(double));
	if (array == NULL)
	{
		exit(0);
	}
	array[0] = n;
	array = array + 1;
	for(i=0;i<n;i++) array[i] = 0;
	return array;
}
int getArraySize(double *array)
{
	return array[-1];
}
void freeArray(double **array){
	free(*array);
	//array = NULL;
}