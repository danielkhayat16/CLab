#include "sort.c"
#include <stdio.h>

int main(void){
	
	 
	int arr [5] = {5,4,3,2,1};
	int arr2[9] = {10,56,7,34,5,22,3,2,1};
	int i;
	  
	swap(arr, 0,4);
	printf("arr[0] = %d et arr[4] = %d\n \n", arr[0], arr[4]);
	swap(arr, 0,4);
	selectionSort(arr);
	for (i = 0; i < 5; i++){
	printf("arr[%d] = %d\n", i , arr[i]);}
	
	selectionReverseSort(arr);
	for (i = 0; i < 5; i++){
	printf("arr[%d] = %d\n", i , arr[i]);}
	for (i = 0; i < 9; i++)	{printf("arr[%d] = %d\n", i , arr2[i]);}          
	printf("\n\nStarting to test Merge Sort \n\n");
	
	mergeSort(arr2);
	for (i = 0; i < 9; i++)	{printf("arr[%d] = %d\n", i , arr2[i]);}  
	
	printf("\n\nStarting to test Reverse Merge Sort \n\n");
	mergeReverseSort(arr2);           
	     
	for (i = 0; i < 9; i++){
	printf("arr[%d] = %d\n", i , arr2[i]);}
	
	printf("\n\nStarting to test Bubble Sort \n\n");
	bubbleSort(arr2);           
	     
	for (i = 0; i < 9; i++){
	printf("arr[%d] = %d\n", i , arr2[i]);}

	return 0;
} 