#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int first, int mid, int last)
{
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 =  last - mid;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[first + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = first; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = (first+last)/2;
 
        // Sort first and second halves
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
 
        merge(arr, first, mid, last);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[20],arr_size,i;
    printf("Enter size of array\n");
    scanf("%d",&arr_size);
    printf("Enter terms\n");
    for(i=0;i<arr_size;i++)
        scanf("%d",&arr[i]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
