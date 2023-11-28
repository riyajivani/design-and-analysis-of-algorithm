#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;

    int b[h+1];

    while(i<=mid && j<=h)
    {
        if(a[i] < a[j])
        {
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }

    for(;i<=mid;i++)
    b[k++]=a[i];

    for(;j<=h;j++)
    b[k++]=a[j];

    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}

void merge_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

int main()
{
    int n=100000;
    int a[n];
    
    for(int i=0;i<n;i++)
    {
    	a[i]=n-i;
    }
    
    clock_t t;
    t=clock();
    merge_sort(a,0,n-1);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    
    printf("insertion sort took %f seconds to execute\n",time_taken);
    return 0;
}