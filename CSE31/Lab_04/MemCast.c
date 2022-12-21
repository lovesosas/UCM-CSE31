#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%d\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
    printf("%x\n", four_ints[2]); 
    // Add your code for the exercises here:
	
	for(int i =0; i < 4; i++){
		printf("%p\n", &four_ints[i]);
	}
	for(int i =0; i < 4; i++){
		printf("%x\n", &four_ints[i]);
	}
	printf("-------------------------\n");

	for(int i =0; i < 4; i++){
		printf("%p\n", &four_c[i]);
	}

	for(int i =0; i < 4; i++){
		printf("%x\n", &four_c[i]);
	}
	
	printf("%d\n", four_c[0]);
	printf("%d\n", four_c[1]);
	printf("%d\n", four_c[2]);
	printf("%d\n", four_c[3]);
	
	return 0;
}