#include <stdio.h> 
 
 int main() { 
  int x= 0;
  int y=0;
  int *px = &x;
  int *py = &y;
  int arr[10];
 
 printf("%d\n", y);
 printf("%d\n", x);


 for(int i =0; i < 10; i++){
    arr[i] = 0;
 }

 for(int i =0; i < 10; i++){
     printf("%d", arr[i]," ");
 }
 printf("\n");

 printf("%d\n", px);
printf("%d\n", py);
printf("%d\n", *px);
printf("%d\n", *py);

for(int i =0; i < 10; i++){
     printf("%d", *(arr +i)," ");
 }
printf("\n");
printf("%d\n", arr);
printf("%d", &arr);





 return 0;
 }
 