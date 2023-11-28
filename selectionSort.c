#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		int min_idx = i;
		
		for (int j = i + 1; j < size; j++) 	
		{
			if (array[j] < array[min_idx])
			min_idx = j;
	    	}
	    	
    		swap(&array[min_idx], &array[i]);
  	}
}

int main() 
{
	int n=10000;
	  int data[n];
	  
	  for(int i=0;i<n;i++)
 	{
 		data[i]=i;
 	}
	  
	clock_t t;
    	t=clock();
	  
	  selectionSort(data,n);
	  
	  t=clock()-t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;

	  printf("selection sort took %f seconds to execute\n",time_taken);
}