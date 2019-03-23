#include <stdio.h>
#include <stdlib.h>
int Occurrence(int *, int , int , int *, int *);
int Division(int,int,float*);
int main(int argc, char *argv[]) {
	//Initilize variables 
	int arr[8] = {1,4,6,1,20,1,5,7};
	int *arrPtr = arr;
	int n = 8;
	int num;
	int dex =  n;
	int dex2 = 0;
	float answer;
	int count = 0;
	int firstNum;
	int secondNum;
	int errorCheck = 0;
	
	
	//Main Program actions
	//Checking for 1
	num = 1; //setting the number we are looking for
	count = Occurrence(arrPtr, n, num, &dex, &dex2); //Calling occurence and setting what it returns = to count
	//Error checks and prints
	if (count == 0){ 
		printf("%d does not exist in this array\n", num);
	} else {
		printf("%d occurs %d times, the first index is %d and the last index is %d\n",num,count,dex,dex2);
	}
	
	//Checking for 10
	num = 10;
	count = Occurrence(arrPtr, n, num, &dex, &dex2); //Calling occurence and setting what it returns = to count
		//Error checks and prints
	if (count == 0){
		printf("%d does not exist in this array\n", num);
	} else {
		printf("%d occurs %d times, the first index is %d and the last index is %d\n",num,count,dex,dex2);
	}
	
	firstNum = 6; //setting variables before running functions
	secondNum = 8;
	printf("Trying to divide %d by %d\n", firstNum, secondNum); //Telling user what numbers are being used
	errorCheck = Division(firstNum, secondNum, &answer); // Calling division and setting its return value to error check so I can check the value and print based off it
		//Error checks and prints
	if (errorCheck == 0){
		printf("Error! Denominator cannot be 0\n");
	} else if (errorCheck == -1){
		printf("Error! numerator should be larger than denominator\n");
	} else {
		printf("%d dvided by %d is %.2f\n",firstNum,secondNum,answer);
	}
	
	firstNum = 8;
	secondNum = 0;
	printf("Trying to divide %d by %d\n", firstNum, secondNum);
	errorCheck = Division(firstNum, secondNum, &answer); // Calling division and setting its return value to error check so I can check the value and print based off it
		//Error checks and prints
	if (errorCheck == 0){
		printf("Error! Denominator cannot be 0\n");
	} else if (errorCheck == -1){
		printf("Error! numerator should be larger than denominator\n");
	} else {
		printf("%d dvided by %d is %.2f\n",firstNum,secondNum,answer);
	}
	
	firstNum = 9;
	secondNum = 5;
	printf("Trying to divide %d by %d\n", firstNum, secondNum);
	errorCheck = Division(firstNum, secondNum, &answer); // Calling division and setting its return value to error check so I can check the value and print based off it
		//Error checks and prints
	if (errorCheck == 0){
		printf("Error! Denominator cannot be 0\n");
	} else if (errorCheck == -1){
		printf("Error! numerator should be larger than denominator\n");
	} else {
		printf("%d dvided by %d is %.2f\n",firstNum,secondNum,answer);
	}

}

int Occurrence(int *arr, int n, int num, int *dex, int *dex2)
{
	int count = 0; // since count is not passed i have to create one just for this funciton
	
	//reseting index variables 
	*dex = n;
	*dex2 = 0;
	for(int i = 0; i < n; i++) //looping through the array
	{
		if(arr[i] == num)
		{
			if ( i < *dex){ //finding the first index of the number
				*dex = i;	
			}
			if ( i > *dex2){ // finding last index of number
				*dex2 = i;
			}
			count += 1;		// adding to count
		}
	}
	if(count == 0){ //if number does not exisit index is set to -1
		*dex = -1; 
		*dex2 = -1;
	}
	return count;
}
int Division(int num1, int num2, float *answer)
{
	if(num2 == 0){ //checking to see if second number is 0
		return 0;
	}
	if(num2 > num1){ // checking to see if second number is larger
		return -1;
	}
	*answer = (float)num1 / num2; //doing the math and casting to float
	return 1;
}