#include <stdio.h>

int main() 
{   
    int evenCounter = 0;
    int oddCounter = 0;
    int counter = 1;
    int number = 1;
    int n;

    float OddTotal = 0;
    float EvenTotal = 0;
    int addDigits;
    while (number != 0) {
        printf("Enter number ");
        printf("%d", counter);
        printf(": ");
        scanf("%d", &number);
        if (number == 0) {
            break;
        }

        n = number;
        addDigits = 0;
        while (n != 0 ){
            addDigits += n % 10;
            n /= 10;
        }      
        // printf("%d", addDigits);


        if (addDigits % 2 == 0) {
            EvenTotal += number;
            evenCounter++;
            // printf("Even total: ");
            // printf("%f", EvenTotal);
            // printf("\n");
            // printf("Even counter: ");
            // printf("%d", evenCounter);
        } 
        else {
            OddTotal += number;
            oddCounter++;
            // printf("Odd total: ");
            // printf("%f", OddTotal);
            // printf("\n");
            // printf("Odd counter: ");
            // printf("%d", oddCounter);
        }

        counter++;
    }

    float avgEven = EvenTotal/evenCounter;
    float avgOdd = OddTotal/evenCounter;

    if (avgEven != 0) {
        printf("Even avg: ");
        printf("%f", avgEven);
        printf("\n");
    }
    if (avgOdd != 0) {
        printf("Odd avg: ");
        printf("%f", avgOdd);
    }

    if (avgEven == 0 && avgOdd == 0) {
        printf("There are no averages to compute.");
    }
    
    
    
    return 0;
}



