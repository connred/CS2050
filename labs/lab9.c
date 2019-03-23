
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int width;
	int height;
}Rect;

typedef struct node {
	Rect* r;
	struct node* next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}Queue;

Queue* createQueue(void);
int enQueue(Queue*);
void* deQueue(Queue*);
int deQueueAll(Queue*);
void printQueue(Queue*);
void freeQueue(Queue*);

int main(void){

	srand(time(NULL));

	Queue* queue = createQueue();
	if (queue == NULL){
		return -1;
	}
	int check = 1;;

	for (int i = 0; i < 10; i++){
		check = enQueue(queue);
		if (check == -1){
			return -1;
		}
	}
	printf("(printQueue)");
	printQueue(queue);

	Rect *r = NULL;
	for (int i = 0; i < 2; i++){
		r = (Rect*)deQueue(queue);
		if (r != NULL){
			printf("(deQueue)");
			printf("Rectangle with area %d has been dequeued\n",r->height*r->width);
		}
	}
	printf("(printQueue)");
	printQueue(queue);

	printf("(deQueueAll)");
	check = deQueueAll(queue);
	printf("(printQueue)");
	printQueue(queue);

	// final test for deQueue
	printf("(deQueue)");
	r = deQueue(queue);

	printf("(freeQueue)");
	freeQueue(queue);
	queue = NULL;

	return 0;
}
Queue* createQueue(void)
{
	Queue *que = malloc(sizeof(Queue)); // allocate memory for queue and init head and tail
	que->head = NULL;
	que ->tail = NULL;
	return que;
}

//insert node on the top of the stack
int enQueue(Queue *que)
{

	Node *newPtr = (Node*)malloc(sizeof(Node)); // create new ptr

	if (newPtr != NULL)
	{
		newPtr->r = (Rect*)malloc(sizeof(Rect)); // allocate memory and assign values
		newPtr->r->width = rand()%10+1;
		newPtr->r->height = rand()%10+1;
		newPtr->next = NULL;

		if(que->head == NULL){
			que->head = newPtr; // if empty add to front
		} else {
			(que->tail)->next = newPtr; //else add to next
		}

		que->tail = newPtr; //
		return 1;
	} else {
		// no memory avaliable
		return -1;
	}
}

//remove nde from the queue head
void *deQueue(Queue *que)
{
	if(que->head != NULL) // if not empty remove a node
	{
		Rect *value = (que->head)->r;
		Node *temp = que->head;
		que->head = (que->head)->next;

		//if queue is empty
		if(que->head == NULL)
		{
			que->tail = NULL;
		}

		free(temp);
		return value;
	}
	return 0;
}


//print the queue
void printQueue(Queue *que)
{
	Node *currentPtr = que->head;
	if (currentPtr == NULL){
		puts("Queue is empty \n");
	} else {
		puts("The queue is:");

		//while not end of queue
		while(currentPtr != NULL)
		{
			int area = currentPtr->r->width * currentPtr->r->height;
			printf(" %d ", area);
			currentPtr = currentPtr->next;
		}
		puts("\n");
	}
}
void freeQueue(Queue *que)
{
	// free the entire queue if needed
	Node* temp = que->head;
	while (que->head)
	{
		temp = (que->head)->next;
		free((que->head)->r);
		free(que->head);
		que->head = temp;
	}
}
int deQueueAll(Queue *que)
{
	// delete all nodes
	Node *temp1 = malloc(sizeof(Node));
	temp1 = (que->head);
	while(temp1!=NULL) //delete all but the first
	{
		(que->head)->next = temp1->next;
		temp1->next = NULL;
		free(temp1);
		temp1 = (que->head)->next;
	}
	que->head = NULL; // remove the first
	free(que->head);
	if(que->head == NULL)
	{
		return 1;
	} else {
		return -1;
	}
	return 0;
}
