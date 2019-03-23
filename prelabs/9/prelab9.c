#include <stdio.h>
#include <stdlib.h>

struct queueNode{
	char data;
	struct queueNode *next;
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void printQueue(QueueNodePtr);
int isEmpty(QueueNodePtr);
char dequeue(QueueNodePtr *,QueueNodePtr *);
void enqueue(QueueNodePtr *,QueueNodePtr *, char);


int main(int argc, char *argv[]) {
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	int value;
}


//insert node on the top of the stack
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));
	
	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->next = NULL;
		
		if(isEmpty(*headPtr)){
			*headPtr = newPtr;
		} else {
			(*tailPtr)->next = newPtr;
		}
		
		*tailPtr = newPtr;
	} else {
		// no memory avaliable
	}
}

//remove nde from the queue head
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	char value = (*headPtr)->data;
	QueueNodePtr temp = *headPtr;
	*headPtr = (*headPtr)->next;
	
	//if queue is empty
	if(*headPtr == NULL)
	{
		*tailPtr = NULL;
	}
	
	free(temp);
	return value;
}

//return 1 if empt 0 otherwise
int isEmpty(QueueNodePtr headPtr)
{
	return (headPtr == NULL);
}

//print the queue
void printQueue(QueueNodePtr currentPtr)
{
	if (currentPtr == NULL){
		puts("Queue is empty \n");
	} else {
		puts("The queue is:");
		
		//while not end of queue
		while(currentPtr != NULL)
		{
			printf(" %c ", currentPtr->data);
			currentPtr = currentPtr->next;
		}
		puts("\n");
	}
}