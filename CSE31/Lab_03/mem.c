
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr; //int pointer
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int)); //allocates 8 bytes of memory on the heap
	*ptr = num; //point to 14
	handle = (int **)malloc(1 * sizeof(int *)); //alocate
	*handle = ptr;

	// Insert code here
	printf("%p\n", &num);
	printf("%p\n", &ptr);
	printf("%p\n", &handle);

	return 0;
} 

