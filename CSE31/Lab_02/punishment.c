#include <stdio.h>

int main(){
    //variables
    char * correctLinePrint = "Coding in C is fun and interesting!";
    char * typoLinePrint = "Coding in C is fun end interesting!";
    int lineRepetitionInt; 
    int typoLineInt;

    //input and output/error checking
    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%d", &lineRepetitionInt);

    while(lineRepetitionInt < 0){
        printf("You entered an invalid value for the number of repetitions!");
        
    }

    printf("Enter the line where you wish to introduce the typo: ");
    scanf("%d", &typoLineInt);

    if(typoLineInt < 0 || typoLineInt > lineRepetitionInt){
        printf("You entered an invalid value for the typo placement!");
    }

    for(int i =1; i <= lineRepetitionInt; i++){
        if(lineRepetitionInt == 0){
            printf("");
        } else if (i == typoLineInt){
            printf(typoLinePrint);
            printf("\n");

            //printf("hi");

        } else {
           printf(correctLinePrint);
            printf("\n");

            //printf("hi");
        }
    }
    return 0;
}