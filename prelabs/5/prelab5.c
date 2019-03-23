#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
  int data;
  struct listNode *nextPtr;
} ListNode;
typedef ListNode *ListNodePtr;

ListNode* initIntegerList();
int insertInteger(ListNodePtr *stPtr, int value);
int delete(ListNodePtr *stPtr, int value);
ListNode* freeList(ListNodePtr *stPtr);
void printList(ListNodePtr);

int main(int argc, char *argv[])
{
  ListNodePtr head;
  head = initIntegerList();
  printList(head);
  insertInteger(&head, 10);
  printList(head);
  insertInteger(&head, 50);
  printList(head);
  insertInteger(&head, 60);
  printList(head);
  insertInteger(&head, 20);
  printList(head);
  delete(&head,10);
  printList(head);
  insertInteger(&head, 40);
  printList(head);
  delete(&head,50);
  printList(head);
  delete(&head, 2);
  printList(head);
  freeList(&head);
}
ListNode * initIntegerList()
{
  return NULL;
}

int insertInteger(ListNodePtr *stPtr, int value)
{
  ListNodePtr newPtr = malloc(sizeof(ListNode));
  if (newPtr != NULL)
  {
    newPtr->data = value;
    newPtr->nextPtr = NULL;

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *stPtr;
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
int delete(ListNodePtr *stPtr, int value)
{
  if(value == (*stPtr)->data)
  {
    ListNodePtr tempPtr = *stPtr;
    *stPtr = (*stPtr)->nextPtr;
    free(tempPtr);
    return value;
  } else {
    ListNodePtr previousPtr = *stPtr;
    ListNodePtr currentPtr = (*stPtr)->nextPtr;

    while(currentPtr != NULL && currentPtr->data != value)
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (currentPtr != NULL) {
      ListNodePtr tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }
  }
  return -1;
}

ListNode* freeList(ListNodePtr *stPtr)
{
  ListNodePtr start = *stPtr;
  ListNodePtr currentPtr = *stPtr;
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
void printList(ListNodePtr currentPtr)
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
