#include <stdio.h>
#include <stdlib.h>


//Structure definition
typedef struct {
  int width;
  int height;
} Rect;

typedef struct node
{
  int data;
  struct node *nextPtr;
} Node;
typedef Node *NodePtr;


//Functions prototype
int insertNodeBasedOnIndex(NodePtr *stPtr, int value);
int delete(NodePtr *stPtr, int value);
int deleteAll(NodePtr *stPtr, int value);
Node* freeList(NodePtr *stPtr);
void printList(NodePtr);


int main(int argc, char *argv[])
{
  srand(time(NULL));
  NodePtr head = NULL;
  printList(head);
  insertInteger(&head, 10);
  printList(head);
  insertInteger(&head, 50);
  printList(head);
  insertInteger(&head, 60);
  printList(head);
  insertInteger(&head, 20);

  insertInteger(&head, 1);
  insertInteger(&head, 5);
  insertInteger(&head, 2);
  insertInteger(&head, 6);
  insertInteger(&head, 7);
  insertInteger(&head, 8);
  insertInteger(&head, 9);
  insertInteger(&head, 10);
  insertInteger(&head, 10);
  printList(head);
  delete(&head,10);
  printList(head);
  insertInteger(&head, 40);
  printList(head);
  delete(&head,50);
  printList(head);
  delete(&head, 2);
  deleteAll(&head, 10);
  printList(head);
  freeList(&head); //free memory
}
Node * initIntegerList()
{
  return NULL;
}

int insertNodeBasedOnIndex(NodePtr *stPtr, int value)
{
  NodePtr newPtr = malloc(sizeof(Node));
  if (newPtr != NULL)
  {
    newPtr->data = value;
    newPtr->nextPtr = NULL;

    NodePtr previousPtr = NULL;
    NodePtr currentPtr = *stPtr;
    while (currentPtr != NULL && value > currentPtr->data) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }
    if(previousPtr == NULL){
      newPtr->nextPtr = *stPtr;
      *stPtr = newPtr;
    } else {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
    return 1;
  } else {
    printf("%d not inserted. No Memory available.\n", value);
    return 0;
  }
}
int delete(NodePtr *stPtr, int value)
{
  if(value == (*stPtr)->data)
  {
    NodePtr tempPtr = *stPtr;
    *stPtr = (*stPtr)->nextPtr;
    free(tempPtr);
    return value;
  } else {
    NodePtr previousPtr = *stPtr;
    NodePtr currentPtr = (*stPtr)->nextPtr;

    while(currentPtr != NULL && currentPtr->data != value)
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (currentPtr != NULL) {
      NodePtr tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }
  }
  return -1;
}
int deleteAll(NodePtr *stPtr, int value)
{
  while(1)
  {
     if(value == (*stPtr)->data)
      {
        NodePtr tempPtr = *stPtr;
        *stPtr = (*stPtr)->nextPtr;
        free(tempPtr);
      } else {
        NodePtr previousPtr = *stPtr;
        NodePtr currentPtr = (*stPtr)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != value)
        {
          previousPtr = currentPtr;
          currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL) {
          NodePtr tempPtr = currentPtr;
          previousPtr->nextPtr = currentPtr->nextPtr;
          free(tempPtr);
        }
        if (currentPtr == NULL){
          return value;
        }
      } 
  }
 
}

Node* freeList(NodePtr *stPtr)
{
  NodePtr start = *stPtr;
  NodePtr currentPtr = *stPtr;
  while(currentPtr != NULL){
    if(currentPtr->nextPtr != NULL){
      currentPtr = currentPtr->nextPtr;
      continue;
    } else {
      currentPtr->data = (int)NULL;
      currentPtr = NULL;
      free(currentPtr);
    }
    free(start);
  }
  return NULL;
}
void printList(NodePtr currentPtr)
{
  //if empty
  if(currentPtr == NULL) {
    puts("list is empty\n");
  } else {
    puts("The list is: ");

    while(currentPtr != NULL){
      printf("%d --> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    puts("NULL\n");
  }
}
