#include <stdlib.h>
#include <stdio.h>

void addition(int integer1,int integer2,int* sumPtr); // function prototype

int main(void) {
	//declare
	int integer1 = 1, integer2 = 2, sum;
	printf("First integer is %d, and second integer is %d\n",integer1,integer2);

	// compute the sum by calling your addition function
	//call the function with the 2 integers and pass sum by reference
	addition(integer1, integer2, &sum);
	// print out the value in the third integer
	
	//print out the third integer which is the sum variable with printf
	printf("The third inetger is %d\n", sum);
	return 0;
}

void addition(int integer1,int integer2,int* sumPtr){
	// explain purpose of this function, incoming parameters and how to call it
	// This function takes the two integers and adds them together, then sets it equal to a pointer to the sum variable
	*sumPtr = integer1 + integer2;
}
