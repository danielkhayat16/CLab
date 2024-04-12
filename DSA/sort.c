#include <stdio.h>
void swap(int * array, int i, int j);
int arrayLength(int * array);

void insertionSort(int * array);
void insertionReverseSort(int * array);

void selectionSort(int * array);
void selectionReverseSort(int * array);

void mergeSort(int * array);
void mergeReverseSort(int * array);
void helperMergeSort(int * array, int l, int r);
void merge(int * array, int l, int m, int r);
void reverseArray(int * array);
void bubbleSort(int * array);


void swap (int * array, int i, int j){
	int tmp ;
	tmp = array[i];
	* (array + i) = * (array + j);
	* (array + j) = tmp;
}

int arrayLength(int * array){
	int i = 0, length = 0; 
	for (i = 0; *(array + i) != '\0'; i ++){
		length ++;
	}
	return length;
}

void insertionSort (int * array){
	int i, j;
	for (i = 1; array[i] != '\0'; i ++){
		for (j = 0; j < i; j++){
			if (array[i] < array[j]){
				swap(array, i, j);
			}
		}
	}
}

void insertionReverseSort(int * array){
	int i, j;
	for (i = 1; array[i] != '\0'; i ++){
		for (j = 0; j < i; j++){
			if (array[i] > array[j]){
				swap(array, i, j);
			}
		}
	}
}

void selectionSort(int * array){
	int i, j ;
	int curMin = 0;
	for (i = 0; *(array + i) != '\0' ; i++){
		curMin = i;
		for (j = i; *(array + j) != '\0' ; j ++){
			if (*(array + j) < *(array + curMin)){
				curMin = j;
			}
		}
		swap(array, i , curMin);
	}
}

void selectionReverseSort(int * array){
	int i, j ;
	int curMin = 0;
	for (i = 0; *(array + i) != '\0' ; i++){
		curMin = i;
		for (j = i; *(array + j) != '\0' ; j ++){
			if (*(array + j) > *(array + curMin)){
				curMin = j;
			}
		}
		swap(array, i , curMin);
	}
}

void mergeSort(int * array){
	int length = arrayLength(array);

	helperMergeSort(array, 0, length-1);
	
}

void helperMergeSort(int * array, int l, int r){
	if (l < r){
	
	
	int m = (int)(l + r -1)/2;
		
	helperMergeSort(array, l, m);
	helperMergeSort(array, m+1, r);
	merge(array, l, m, r);
	}
}

void mergeReverseSort(int * array){
	mergeSort(array);
	reverseArray(array);
}

void merge(int * array, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m ;
	int arr1[n1], arr2[n2];
	int i, j, k;
	
	/*In the next two for loops we create arrays that we want to merge */
	for (i = 0; i <= n1; i ++){
		arr1[i] = array[l + i];
	}
	for (i = 0; i <= n2; i ++){
		arr2[i] = array[m + 1 + i];
	}
	i = 0;
	j = 0;
	k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            array[k] = arr1[i];
            i++;
        }
        else {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = arr1[i];
        i++;
        k++;
    }


    while (j < n2) {
        array[k] = arr2[j];
        j++;
        k++;
    }
	
	
}
void reverseArray(int * array){

	int i = 0;
	int arrLength = arrayLength(array);
	printf("%d", arrLength);
	while(2*i < arrLength){
		swap(array, i, arrLength -1 - i);
		i++;
	}
}

void bubbleSort(int * array){
	
	int i = 0;
	int len = arrayLength(array);
	int swapped = 0;
	do {
		swapped = 0;
		len --;
		for (i = 0; i < len ; i++){
			if (array[i] > array[i+1]){
				swap(array, i, i+1);
				swapped = 1;
			}
		}
	} while(swapped);
}