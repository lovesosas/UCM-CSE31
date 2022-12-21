
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* bubbleSort(int arr[], int n) { //n is size of array
    int temp, i = 0, j = 0;
    int *s_arr = (int*)malloc(n * sizeof(int));

    // Copy arr to s_arr
    for(i = 0; i < n; i++)
        s_arr[i] = arr[i];


    // Sorting using pointer notations. i.e. you cannot use "[]"!
    // Your code goes here...
    for(i = 0; i < n -1; i++){
        for(j = 0; j < n-1; j++){
            if(*(s_arr + j) > *(s_arr + j +1)){ 
                temp = *(s_arr + j + 1); //store the right j+1 index into temp
                *(s_arr + j + 1) = *(s_arr + j); //swap te left j index onto the right j+1
                *(s_arr + j) = temp; // swap the j+1 index on the left index j
            }
        }
    }
    return s_arr; //return our array sorted

}

void printArray(int arr[], int n) {
    int i = 0;
    printf("[");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int bSearch(int *arr, int a, int b, int key) {
    // Binary search function. arr is the array, key is the value to search for, a and b are the boundaries of arr to be searched within.
    // You must use pointer notations. i.e. no "[]"
    // Your code goes here:
    int count = 0;
    int mid = (a+b)/2;
    
    /*if(key != *(arr + count)){
        return -1;
    }
    */
   if (a > b) {
    return -1;
   }

    if(*(arr + mid) == key){ 
        return mid;
    } else if(key > *(arr+mid)){
        count++;
        return bSearch(arr, mid+1, b, key);
    } else if(key < *(arr + mid)){
        count++;
        return bSearch(arr, a, mid-1, key);
    }
    
    return 0;
}

int main() {

    int i = 0, size = 0, key = 0, result = 0;
    int *array, *sorted;

    printf("How big is your array?  ");
    scanf("%d", &size);
    array = (int*)malloc(size * sizeof(int));

    for(i = 0; i < size; i++) {
        printf("Please enter array[%d]:  ", i);
        scanf("%d", &array[i]);
    }
    
    printf("Please wait while I sort your numbers...\n");
    sorted = bubbleSort(array, size);
    printf("Here is your original array:\n");
    printArray(array, size);
    printf("Here is your SORTED array: \n");
    printArray(sorted, size);

    printf("What number are you looking for? ");
    scanf("%d", &key);
    printf("OK, let me see if I can find a \"%d\" in the array...\n", key);
    result = bSearch(sorted, 0, size-1, key);
    if(result != -1)
        printf("Got it! A \"%d\" is at index %d.\n", key, result);
    else
        printf("I'm sorry, a \"%d\" cannot be found in the array.\n", key);
	return 0;


}


