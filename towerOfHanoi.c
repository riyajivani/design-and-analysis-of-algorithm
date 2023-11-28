#include<stdio.h>
#include<time.h>


void TOH(int n,char x,char y,char z)
{
	   if(n>0) 
	   {
	      TOH(n-1,x,z,y);
	      printf("%c to %c \n",x,y);
	      TOH(n-1,z,y,x);
	   }
}

int main() 
{
   int n=25;
   clock_t t;
   t=clock();
   TOH(n,'A','B','C');
   t=clock()-t;
   
   double time_taken=((double)t)/CLOCKS_PER_SEC;
   
   printf("tower_of_hanoi took %f seconds to execute\n",time_taken);
   return 0;
}