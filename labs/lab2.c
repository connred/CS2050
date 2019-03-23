#include <stdio.h>
#include <stdlib.h>
float * createArray(int, size_t);
void freeArray(float **);
int getArraySize(float *);

int main(void) {
	float *array = NULL;
	//free(array);
	int n = 100;

	array = createArray(n, sizeof(float));
	int size = 0;
	//array[-1] = 9;
	size = (int)getArraySize(array);


	printf("%d\n", size);

	//freeArray(&array);
}

float * createArray(int n, size_t a)
{
	int i;
	float *array = NULL;
	array = (float*)malloc((n+1)*sizeof(float));
	if (array == NULL)
	{
		exit(0);
	}
	array[0] = n;
	array = array + 1;
	for(i=0;i<n;i++) array[i] = 0;
	return array;
}
int getArraySize(float *array)
{
	return array[-1];
}
void freeArray(float **array){
	free(*array);
	//array = NULL;
}
