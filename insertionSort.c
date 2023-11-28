#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int n=10000;
    int arr[n];

 for(int i=0;i<n;i++)
 	{
 		arr[i]=n-i;
 	}

 	clock_t t;
    	t=clock();
	insertionSort(arr, n);
    
	t=clock()-t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
	printArray(arr, n);
 	printf("insertion sort took %f seconds to execute\n",time_taken);
	
	return 0;
}