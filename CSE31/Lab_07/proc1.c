#include <stdio.h>

int printOut(int *temp1, int *temp2){
    int sum = 0;
    sum = *temp1+*temp2;
    

    return sum;
}


int main(){
    int m;
    int n;

    m = 10;
    n = 5;

    int *aTemp1 = &m;
    int *aTemp2 = &n;

    printf("%d", printOut(aTemp1, aTemp2));
    

    //printf("%d", *aTemp1);







    return 0;
}