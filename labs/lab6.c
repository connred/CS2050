# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#define randnum(min, max) \
		((rand() % (int)(((max) + 1) - (min))) + (min))

typedef struct {
	int height;
	int width;
}Rect;

typedef struct list{
	Rect *r;
	struct list *next;
}List;

List *initList();
int insertList(List **);
void printList(List *);
List* freeList(List *);
float averageArea(List *);

int main(){

	srand(time(NULL));

	List* list = initList();
	int check = 0;
	for (int i = 0; i < 10; i++){
		check = insertList(&list);
		if (check == -1){
			printf("Insufficient memory\n");
			return -1;
		}
	}
	printList(list);

	float aveArea = averageArea(list);
	printf("Average area is %.2f\n",aveArea);

	list = freeList(list);

	return 0;
}
List *initList()
{
	List *head = malloc(sizeof(List));
	head = NULL;
	return (head);
}
int insertList(List **listPtr)
{
	int rand1 = randnum(1, 10);
	int rand2 = randnum(1, 10);
	Rect *newPtr = malloc(sizeof(Rect));
	List *newNode = malloc(sizeof(List));
	if(newPtr != NULL && newNode != NULL)
	{
		newPtr->height = rand1;
		newPtr->width = rand2;

		newNode->r = newPtr;
		newNode->next = NULL;

		List *previousPtr = NULL;
		List *currentPtr = *listPtr;
		while (currentPtr != NULL) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
		if(previousPtr == NULL){
			newNode->next= *listPtr;
			*listPtr = newNode;
		} else {
			previousPtr->next = newNode;
			newNode->next = currentPtr;
		}
		return 0;
	} else {
		return -1;
	}
	return 0;
}
void printList(List *list)
{
	if (list == NULL) {
		puts("list is empty\n");
	} else {
		puts("Areas are: ");
		int area;
		for(int i = 0; i<10; i++)
		{
			area = (list->r->height) * (list->r->width);
			printf("%d,", area);
		}
		printf("\n");
	}
}
List* freeList(List *list)
{
	List *start = list;
	List *currentPtr = list;
	while(currentPtr != NULL){
		if(currentPtr->next != NULL){
			currentPtr = currentPtr->next;
			continue;
		} else {
			currentPtr->r->width = (int)NULL;
			currentPtr->r->height = (int)NULL;
			currentPtr->r = NULL;
			currentPtr->next = NULL;
			currentPtr = NULL;
			free(currentPtr);
		}
	}
	return list;
}
float averageArea(List *list)
{
	float total;
	if (list == NULL) {
		} else {
			float area;
			for(int i = 0; i<10; i++)
			{
				area = (list->r->height) * (list->r->width);
				total += area;
			}
		}
	total = (total / 10);
	return total;
}
