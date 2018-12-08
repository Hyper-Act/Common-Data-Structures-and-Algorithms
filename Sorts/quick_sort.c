#include<stdio.h>

void check(int A[],int first,int last)
{
    int i=first;
    for(;i<last;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*int hoarse_partition(int A[],int first,int last)
{
    int i = first,j = last-1,temp;
    int pivot = A[first];
    while(i<=j)
    {
        while(A[i]<=pivot && i<last)
            i++;
        while(A[j]>=pivot && j>first)
            j--;
        swap(&A[i],&A[j]);
    }
    swap(&A[first],&A[j]);
    return j;
}*/

int lomuto_partition(int A[],int first, int last)
{
    int length = first-1,j = first;
    int pivot = A[last-1];
    while(j<last-1)
    {
        if(A[j]<=pivot)
            swap(&A[++length],&A[j]);
        j++;            
    }
    swap(&A[++length],&A[last-1]);
    check(A,first,last);
    return length;
}

void quicksort(int A[],int first,int last)
{
    int v;
    if(first<last)
    {
        v = lomuto_partition(A,first,last);
        quicksort(A,first,v);
        quicksort(A,v+1,last);
    }
}

void main()
{
    int A[20],i,n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter %d terms\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quicksort(A,0,n);
    printf("Sorted Array\n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
