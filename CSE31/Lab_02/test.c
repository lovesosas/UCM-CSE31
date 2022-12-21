#include<stdio.h>
#include<string.h>
#include<stdlib.h>// termianl suggested to add this to not use Malloc form

void printArr(int *a, int size, char *name){
	//Your code here
            int *pz = 0;// points to z

     if(name == "Original"){
        printf("%s array's contents: ", name);
            for(int i=0; i < size; i++){
                pz = a+i;
                printf("%d ", *pz);
            }
            printf("\n");//for spacing
        }
    else if(name == "Copied"){
            printf("%s array's contents: ", name);
            for(int i = 0; i < size; i++){
                pz = a+i;
                printf("%d ", *pz);
            }
            printf("\n");//spacing
        }
    }



int* arrCopy(int *a, int size){
	//Your code here
    int *ps = 0;
    int *psNew = 0;
    int *arrCopy  = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        psNew = arrCopy + i; //Points to empty array
        ps = a+i;       //Points to the original  array
        *psNew = *ps; //Copy array as i iterates

    }
    return arrCopy;  //returns coppied array
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);

    //Dynamically create an int array of n items
    //Your code here
    
    int *array = (int *) malloc (n * sizeof(int));


    //Ask user to input content of array
	//Your code here
    
    int copied= 1;
    arr_copy= 0;
    int *pArr = 0;//pointer to array
    for(int i = 0; i < n; i++){
        pArr = array+i;
        printf("Enter array element #%d: ", copied);
        scanf("%d", pArr);
        copied++;
    }
    printf("\n");// space
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array with contents in reverse order
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}