#include<stdio.h>
#include<time.h>

int fibbonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

int main() {
   int n =80;
   int i;
   clock_t t;
   t=clock();
   
   for(i = 0;i<n;i++) {
     fibbonacci(i);            
   }
   
   t=clock()-t;
   double taken_time=((double)t)/CLOCKS_PER_SEC;
   printf("total vtime taken by fibonacci is %f\n",taken_time);
}