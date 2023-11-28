#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}
 
int main(void)
{
	int n=10000;
    int arr[n];
    int x = 9990;
    
    for(int i=0;i<n;i++)
	{
 		arr[i]=i;
 	}
 	
    clock_t t;
    t=clock();
    
    int result = binarySearch(arr, 0, n - 1, x);
    
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    (result == -1)
        ? printf("Element is not present in array/n")
        : printf("Element is present at index %d/n", result);
        
    printf("binary search took %f seconds to execute\n",time_taken);
    return 0;
}