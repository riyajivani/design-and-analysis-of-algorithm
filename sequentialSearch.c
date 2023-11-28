#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
	int n=1000000;
    int arr[n];
    int x = 99999;
 
 	for(int i=0;i<n;i++)
 	{
 		arr[i]=i;
 	}
 
    clock_t t;
    t=clock();
    
    int result = search(arr, n, x);
    
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    (result == -1)
        ? printf("Element is not present in array\n")
        : printf("Element is present at index %d\n", result);
       
    printf("sequential search took %f seconds to execute\n",time_taken);
    return 0;
}