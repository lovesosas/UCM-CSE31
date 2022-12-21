#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;


// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\n\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) { //print our puzzle
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            printf("%c ", *(*(arr+i)+j));
        }
        printf("\n");
        
    }
    printf("\n");
}

char upcase(char letter) {  //function to capitalize a letter
    if (letter >= 'a' && letter <= 'z') { //check if its in bounds of alphabet
        return (letter += 'A' - 'a'); //the differnce in all ascii values are 32 so we subtract A - a to get 32 and add to letter to get capital of letter
    }
} 


int concat(int a, int b) { // function to concatenate two integers and return as integer
    char s1[20]; //array of 20 chars
    char s2[20];

    sprintf(s1, "%d", a); //take in a number from puzzle and turn it into a number and store int s1 char array
    sprintf(s2, "%d", b);//take in a letter from puzzle and turn it into a number and store int s2 char array

    strcat(s1, s2); //combines s1 and s2 char arrays which hold ints to get multiples digits in one position

    int c = atoi(s1); //convert s1 array into an integer
    return c;
}

int searchAround(char** arr, int loc1, int loc2, char* word, int* pathing, int next) {
    if (next+1 > strlen(word)) { //if the next+1 value reaches the strlen of word it means the end of the word as been reached so return true
        return 1;
    }

    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {  // loop through the matrix    
            bool condition = i == loc1 && j == loc2;
            if ((*(*(arr + i) + j) == *(word+next/*next indicates the place letter in the word we are searching for*/)) && i - loc1 >= -1 && i - loc1 <= 1 && j - loc2 >= -1 && j - loc2 <= 1 && !condition) { //find the values in the array that are equal to the letter you are searching for and within one space of the previous letter
                *(pathing + 2 * next - 2) = i; //update the pathing array with the coordinates of the value found that meets condtion
                *(pathing + 2 * next - 1) = j;
                return searchAround(arr, i, j, word, pathing, ++next); //recursively call searchAround with ++next (will be next letter in word)
            }
        }
    }
    if (next+1 <= strlen(word)) { //if word has not reached end but it has not found it yet
        return 2;
    }
    return 0; // return false if runs through and not meet conditions
}



int reverseSearchAround(char** arr, int loc1, int loc2, char* word, int* pathing, int next) {
    if (next+1 > strlen(word)) { //if the next+1 value reaches the strlen of word it means the end of the word as been reached so return true
        return 1;
    }
    for (int i = bSize-1; i >= 0; i--) {
        for (int j = bSize-1; j >= 0; j--) {  //do the same thing as search around but this time go in opposite direction
            bool condition = i == loc1 && j == loc2; //
            if ((*(*(arr + i) + j) == *(word+next/*next indicates the place letter in the word we are searching for*/)) && i - loc1 >= -1 && i - loc1 <= 1 && j - loc2 >= -1 && j - loc2 <= 1 && !condition) { //find the values in the array that are equal to the letter you are searching for and within one space of the previous letter
                
                *(pathing + 2 * next - 2) = i; //update the pathing array with the coordinates of the value found that meets condtion
                *(pathing + 2 * next - 1) = j;
                
                return reverseSearchAround(arr, i, j, word, pathing, ++next); //recursively call searchAround with ++next (will be next letter in word)
            }
        }
    }
    return 0; // return false if runs through and not meet conditions
}


int countDigits(int n) { // function that returns the # of digits of an integer
    int count = 0;
    do {
        n /= 10;
        ++count;
    } while (n != 0);
    return count;
}


void printPathing(int** pathArray, int* pathing) { //given the pathing array will transcribe values into pathArray so it will display when printed
    int iVal;
    int jVal;
    int* pathPointer = pathing; //create pathPointer that points to beginning of pathing array
    int c = 1;
    //pathing array should have numbers by now if there is a word found and as long as the pointer does not reach -1 (no values)
    while (*pathPointer != -1) { // loops until pathPointer points to a value which is -1 (the array is full of -1 by default and updated by the searchAround function)
        iVal = *(pathing + ((2 * c) - 2)); //pathing is an array containing pairs of consecutive coordinates, and this will find the values in pathing and turn them into i and j coordinates to put in the pathArray 2d array
        jVal = *(pathing + ((2 * c) - 1)); //esentailly this will copy the each pair in our pathing array and put them into our visual matrix **patharray

        if (*(*(pathArray + iVal) + jVal) == 0) { // if there is a 0 in that postiion 
            *(*(pathArray + iVal) + jVal) = c+1; // start the chaining of the path. Ex 1 2 3 4 5 6...
        } else {
            *(*(pathArray + iVal) + jVal) = concat(*(*(pathArray + iVal) + jVal), c+1); //if there is already a value there then concatenate it with the new value and add it on there
        }
       
        c++; //increment c to have the 1 2 3 4 5 6... path
        pathPointer+=2; //increment the pathpointer by 2 (since we used 2 values as coordinates) to move down the array onto the next pair
    } 

    printf("Word found!\n");
    printf("Printing the search path:\n"); //printing the search path
    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            printf("%d", *(*(pathArray + i)+j));
            int x = countDigits(*(*(pathArray + i)+j));
            for (int k = 0; k < 7 - x; k++) { //prints out space based on the digits stored in that place in pathArray (to prevent irregular spacing)
                printf(" ");
            }
        }
        printf("\n");
    }
}


void zeroIntMatrix(int** arr) { // will make a int matrix all zeroes
    for (int i = 0; i < bSize; i++) {
        *(arr + i) = (int*)malloc(bSize * sizeof(int));
        for (int j = 0; j < bSize; j++) {
            *(*(arr + i) + j) = 0; //set each i and j for all postions in the matrix equal to 0
        }
    }
}

void searchPuzzle(char** arr, char* word) {
    // CONVERT LETTERS TO UPPER
    for (int i = 0; i < strlen(word); i++) { //as long as i is less the the length of word turn each letter in our word into uppercase
        *(word + i) = upcase(*(word + i));
    }

    //Create and set 2D matrix of pathArray to all 0's
    int** pathArray = (int**)malloc(bSize * sizeof(int*)); //create another 2d matrix to see the visual of the 2d matrix path in the end. Seperate from **arr since that is used for the acutal math part
    zeroIntMatrix(pathArray); //set all positions in our 2d matrix to 0

    int *pathing = (int*)malloc(40 * sizeof(int)); //create a normal array so we can store our data into. Initalize all to -1's.
    for (int i = 0; i < 40; i++) {
        *(pathing + i) = -1;
    } 

    int found = 0; //checking to see if we found our word or not
    char* letter = word; //letter is first letter of word
    for (int i = 0; i < bSize && found == 0; i++) { //in **arr make sure we dont go out of bounds of matrix and check if we have found first letter yet.
        for (int j = 0; j < bSize && found == 0; j++) {
            if (*(*(arr + i) + j) == *letter) { //if that postiion in matrix equals to our first letter then
                *(*(pathArray + i) + j) = 1; //set the first index in visual pathArray to that letter found

                int searchLocation1 = i; //store our i and j of that position/coords of wherever the first letter was located
                int searchLocation2 = j; // searchlocations are the i and j coords of the letter found
                int searchResult = searchAround(arr, searchLocation1, searchLocation2, word, pathing, 1); //start search around with these arguments
                if (searchResult == 1) { //if searcharound returns 1 then the word is found
                    found = 1; //make found into 1
                }
                if (searchResult = 2) { //if 2 is returned from searchAround, begin searching the opposite direction of the letters surroudning the first letter
                    if(reverseSearchAround(arr, searchLocation1, searchLocation2, word, pathing, 1) == 1) { //if reversesearch around returns true (word is found) make found check into 1
                        found = 1;
                    }
                }
                if(found) { //if found is 1 print our final visual matrix for the user to see
                    printPathing(pathArray, pathing); //print pathing if word found
                }
                zeroIntMatrix(pathArray); //clear pathing array afterwords
            }
        }
    }
    if (found == 0) //if neither first letter or searcha arround and reverse search arround returns 1 the word is not in the matrix
    printf("Word not found!");
}

