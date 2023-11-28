#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int arr[], int i, int j)
{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

void sort(int arr[], int left, int right)
{
        if (left < right)
        {
            int pivot = arr[left];
            int i = left;
            int j = right + 1;

            do
            {
                do
                {
                    i++;
                } while (pivot > arr[i]);
                do
                {
                    j--;
                } while (pivot < arr[j]);

                if (i < j)
                {
                    swap(arr, i, j);
                }

            } while (i < j);

            if (i > j)
            {
                swap(arr, left, j);
            }

            sort(arr, left, j - 1);
            sort(arr, j + 1, right);
        }
}

int main()
{
    int n=100000;
    int arr[n];
    
    for(int i=0;i<n;i++)
 	{
 		arr[i]=i;
 	}
    
    int left = 0;
    int right = n-1;

	clock_t t;
    	t=clock();
    	
    sort(arr, left, right);
    
    t=clock()-t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
 	printf("quick sort took %f seconds to execute\n",time_taken);

    return 0;
}