//#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void printArr(int *a, int size, char *name){
        printf("%s", name);
	 for (int i = 0; i < size; i++){
        printf(" ");
        printf("%d", *(a + i));
     }
     printf("\n");
    return;
}

int* arrCopy(int *a, int size){
    int *arrCopy  = (int *)malloc(size * sizeof(int));
    int *pointerOriginal = a+0;
    int *pointerArrCopy = arrCopy+0;
    /*for(int i = 0; i < size; i++){ //create double for loop for i and j (note)
        for(int j = size-1; j >-1; j--){
            pointerArrCopy = *(arrCopy+j);
            pointerOriginal = *(a+i);
        //pointerArrCopy = arrCopy+j;
        //pointerOriginal = a+i;       
        *pointerArrCopy = *pointerOriginal; 
        }
        */

       //other code method
        int j = size - 1; 
        int transferVar = 0; 
        for (int i = 0; i < size; i++)
        {
            transferVar = *(a+j); //save the  last element in array  into transfervar

            *(arrCopy+i) = transferVar; // copy that element into arrCopy first index and so on
            j--;
        }
    return arrCopy;
    }

int main(){
    int n;
    int *arr;
    int *arr_copy;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);


    //Dynamically create an int array of n items
    //Your code here
    arr = (int*)malloc(n *sizeof(int));

    //Ask user to input content of array
	//Your code here
	for(int i =0; i < n; ++i){
        printf("Enter array element #");
        printf("%d", i+1);
        printf(": ");
        scanf("%d", arr + i);
    }
    printf("\n");
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original array's contents:");

	//Copy array with contents in reverse order
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied array's contents:");
    free(arr);
    return 0;
}