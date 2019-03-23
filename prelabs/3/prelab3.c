#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int getRecordNum(char* filename);
void load_sructdata(char *filename, int size);
//void print_data(int size);

typedef struct
{
	char name[20];
	int num;
} Record;

Record *arr;

int main(int argc, char *argv[]) {
	if ( argc != 2){
		printf("Insufficient arguments! load the correct number of input arguments");
		exit(1);
	}
	char *filename = argv[1];
	int size = getRecordNum(filename);

	load_sructdata(filename, size);
	//print_data(size);
	//free(arr);
}

int getRecordNum(char* filename)
{
	FILE *f;
	f = fopen(filename, "r");
	int num = 0;
	fscanf(f, "%d", &num);
	printf("%d\n",num);
	return num;
}
void load_sructdata(char *filename, int size)
{
	FILE *f;
	f = fopen(filename, "r");
	fgets(filename,MAX,f);
	arr = malloc(size*sizeof(Record));
	for(int i = 0; i<size; i++)
	{
		fscanf(f, "%s %d", arr[i].name, &arr[i].num);
	}
	free(arr);

}
/*void print_data(int size)
{
	printf("s/no\tName\tId");
	for(int i = 0; i < size; i++)
	{
		printf("\n%d\t%s\t%d", i + 1,arr[i].name,arr[i].num);
	}
}*/