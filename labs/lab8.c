// BONUS ATTEMPTED //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Structure definition
typedef struct {
	int width;
	int height;
} Rect;

typedef struct node
{
	Rect *r;
	struct node *next;
} Node;
typedef Node *NodePtr;


//Functions prototype
int insertNodeBasedOnIndex(Node **, int );
int removeNodeBasedOnValue(Node **, int );
Node* freeList(Node *);
void printList(Node *);
void printReverseList(Node *);


int main(int argc, char *argv[])
{
	srand(time(NULL));
	Node *head = NULL;
	int check;
	for(int i = 0; i < 10; i++){
		check = insertNodeBasedOnIndex(&head, i);
		if (check == -1){
			return -1;
		}
	}
	printList(head);
	
	check = insertNodeBasedOnIndex(&head, 7);
	printList(head);
	
	check = removeNodeBasedOnValue(&head, rand()%10+1);
	printList(head);
	
	printReverseList(head);
	
	freeList(head);
	return 0;
}


int insertNodeBasedOnIndex(NodePtr *stPtr, int value)
{
	NodePtr newPtr = malloc(sizeof(Node)); // allocate new node and its rect vv
	newPtr->r = malloc(sizeof(Rect));
	if (newPtr != NULL)
	{
		newPtr->next = NULL; // new node next to null
		
		newPtr->r->height = rand()%10+1; // assign values
		newPtr->r->width = rand()%10+1;

		NodePtr previousPtr = NULL;  // prepare to loop
		NodePtr currentPtr = *stPtr;
		
		for( int i = 0; i < value; i++){ // loop to the index
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
		if(previousPtr == NULL){  // insert node
			newPtr->next = *stPtr;
			*stPtr = newPtr;
		} else { // insert node
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
		}
		return 1; // successful insert
	} else {
		return -1; // insert failed
	}
}
int removeNodeBasedOnValue(NodePtr *stPtr, int value)
{
	if(value == (*stPtr)->r->width) // if its in the first node it will find it
	{
		NodePtr tempPtr = *stPtr; // remove node
		*stPtr = (*stPtr)->next;
		free(tempPtr); // free node
		return 1; // success
	} else {
		NodePtr previousPtr = *stPtr; // prepare to loop
		NodePtr currentPtr = (*stPtr)->next;

		while(currentPtr != NULL && currentPtr->r->width != value) // looping untill width is found
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		if (currentPtr != NULL) {
			NodePtr tempPtr = currentPtr; // remove node if it is found
			previousPtr->next = currentPtr->next;
			free(tempPtr);
			return 1;// success
		}
	}
	return -1; // failed to remove
}

Node* freeList(Node *head) // instructor written
{
	Node* temp = head;
	while(head){
		temp = head->next;
		free(head->r);
		free(head);
		head = temp;
	}
	return NULL;
}
void printList(Node* head) // instructor written
{
	printf("Width values are:");
	Node *temp = head;
	while(temp){
		printf(" %d ", temp->r->width);
		temp = temp->next;
	}	
	printf("\n");
}
void printReverseList(Node * head)  // resvers list funciton
{
	if(head == NULL) // base
		return;
		
	printReverseList(head->next); // recursion / print the list after head node
	
	printf(" %d ", head->r->width); // print head
}