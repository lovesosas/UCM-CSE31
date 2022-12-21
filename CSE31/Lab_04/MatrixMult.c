#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **matC = (int**)malloc(size * sizeof(int*));
	for(int i =0; i<size; i++){
		*(matC + i) = (int*)malloc(size * sizeof(int));
		for(int j =0; j< size; j++){
			*(*(matC + i )+ j) = 0;
			for(int k = 0; k < size; k++){
				*(*(matC + i )+ j) = *(*(a+i)+k) * (*(*(b+k)+j));
			}
		}
	}
return matC;

}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	for(int i = 0; i < n; i++){ //print our the column and rows
		for(int j =0; j < n; j++){
			printf("%d", *(*(arr+i)+j));
			
		}
		printf("\n");
	}
}

int main() {
	int n = 3;
	//int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	int **matA = (int**)malloc(n * sizeof(int*)); //create an pointer thats points to an array of pointers
	int **matB = (int**)malloc(n * sizeof(int*));
	// int **matC = (int**)malloc(n * sizeof(int*));

for(int i = 0; i < n; i++){  
	*(matA + i) = (int*)malloc(n * sizeof(int)); //point to the first columun and working your way down the column
	for(int j = 0; j < n; j++){ //set the entire first column to 2 and the rows to 2
		*(*(matA + i)+j) = 2;
	}
}


for(int i = 0; i < n; i++){ //same goes here
	*(matB + i) = (int*)malloc(n * sizeof(int));
	for(int j= 0; j < n; j++){
		*(*(matB + i)+j) = 1;
	}
}


// for(int i = 0; i < n; i++){ //our third matrix to save our values in
// 	*(matC + i) = (int*)malloc(n * sizeof(int));
// 	for(int j= 0; j < n; j++){
// 		*(*(matC + i)+j) = 1;
// 	}
// }

	// (3) Call printArray to print out the 2 arrays here.
		printArray(matA, n);
		printf("\n");
		printArray(matB, n);
		printf("\n");

	// (5) Call matMult to multiply the 2 arrays here.
		int **matC = matMult(matA, matB, n);
		printf("\n");
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}