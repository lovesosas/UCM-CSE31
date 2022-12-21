#include <stdio.h>
#include <math.h>

int main(){
    //numbers
    int avgEvenCounter = 0; //keep track of our even counts to divide by
    int avgOddCounter = 0;

    float avg_even = 0; //actual average
    float avg_odd = 0;

    int userInput; //users numbers
    int count = 1; //for 1st, 2nd, 3rd, th...

    int remainderOfMod; //use to get our actual single digits from the number
    int restOfNumber = userInput; //rest of 

    int sum = 0;

        while(userInput != 0){

            if(count % 10 == 1){
             printf("Enter the 1st number: ");
             scanf("%d", &userInput);

            if(userInput == 0){
                printf("There is no average to compute\n");
                return 0;
            }

            while(remainderOfMod !=0){
                //printf("TEST");
                remainderOfMod = restOfNumber % 10; //example: 100 mod 10 = 0, 100/10 = 10, 10 mod 10 = 0, 10/10 = 1. 1-0-0
                sum = sum +remainderOfMod; //add to our sum
                restOfNumber = restOfNumber / 10;

            }

            if(sum % 2 == 0){
                //printf("TEST");
                avg_even = avg_even + userInput; //if sum of split numbers is even add to even avg.
                avgEvenCounter++;
                count++;
            } else if(sum % 2 == 1){ //if split numbers are odd add to ood avg.
                avg_odd = avg_odd + userInput;
                avgOddCounter++;
                count++;
            }
            }

         if (count % 10 == 2){
             printf("Enter the 2nd number: ");
             scanf("%d", &userInput);
              while(remainderOfMod !=0){
                remainderOfMod = restOfNumber % 10;
                sum = sum +remainderOfMod;
                restOfNumber = restOfNumber / 10;
            }
            if(sum % 2 == 0){
                avg_even = avg_even + userInput;
                avgEvenCounter++;
                count++;
            } else if(sum % 2 == 1){
                avg_odd = avg_odd + userInput;
                avgOddCounter++;
                count++;
            }

        } else if (count % 10 == 3){
             printf("Enter the 3rd number: ");
             scanf("%d", &userInput);
             while(remainderOfMod !=0){
                remainderOfMod = restOfNumber % 10;
                sum = sum +remainderOfMod;
                restOfNumber = restOfNumber / 10;
            }
            if(sum % 2 == 0){
                avg_even = avg_even + userInput;
                avgEvenCounter++;
                count++;
            } else if(sum % 2 ==1){
                avg_odd = avg_odd + userInput;
                avgOddCounter++;
                count++;
            }

    } else if (count % 10 == count){
        printf("Enter the %d", count);
        printf("th number: ");
             scanf("%d", &userInput);
              while(restOfNumber!=0){   
                remainderOfMod = restOfNumber % 10;
                sum = sum +remainderOfMod;
                restOfNumber = restOfNumber / 10;
            }
            if(sum % 2 == 0){
                avg_even = avg_even + userInput;
                avgEvenCounter++;
                count++;
            } else if (sum % 2 ==1){
                avg_odd = avg_odd + userInput;
                avgOddCounter++;
                count++;
            } 
        }
        //sum = 0;
        }

        

       avg_even = avg_even/(avgEvenCounter-1); //calculate average
       avg_odd = avg_odd/(avgOddCounter-1);




       if(avgEvenCounter > 0 && avgOddCounter == 0){
        printf("Average of inputs whose digits sum up to an even number: %.2f", (avg_even));
       } else if(avgOddCounter > 0 && avgEvenCounter == 0){
        printf("Average of inputs whose digits sum up to an odd number: %.2f", (avg_odd));
       } else if(avgEvenCounter > 0 && avgOddCounter > 0){
        printf("Average of inputs whose digits sum up to an even number: %.2f", (avg_even));
        printf("Average of inputs whose digits sum up to an odd number: %.2f", (avg_odd));
       }
    

    return 0;
}