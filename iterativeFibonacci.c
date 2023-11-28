#include<stdio.h>
#include<time.h>
    
int main()    
{    

	 int n1=0,n2=1,n3,number=50;    
	   
	 printf("\n%d %d",n1,n2);//printing 0 and 1  
   
   	clock_t t=clock();
	 for(int i=2;i<number;++i)//loop starts from 2 because 0 and 1 are already printed    
	 {    
		  n3=n1+n2;    
		  printf(" %d",n3);    
		  n1=n2;    
		  n2=n3;    
	 }  
	 t=clock()-t;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 
	 printf("time taken by iterative fibonacci is %f\n",time_taken);
  	return 0; 
 }