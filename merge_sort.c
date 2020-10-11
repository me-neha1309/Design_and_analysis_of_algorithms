#include<stdio.h>
#include<stdlib.h>
void merging(int arr[],int, int, int);
void mergeSort(int arr[], int, int);
void main() 
{
	int arr[10],i;
	printf("\nEnter the elements:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,9);
	printf("\nElements in the sorted order:");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
}
void merging(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int *Left, *Right; 
	Left=(int*)malloc(sizeof(int)*n1);
	Right=(int*)malloc(sizeof(int)*n2);
    for (i = 0; i < n1; i++) 
        Left[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        Right[j] = arr[m + 1+ j]; 
    i = 0; j = 0;k = l; 
    while (i < n1 && j < n2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            arr[k] = Left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
	 while (i < n1) 
    { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merging(arr, l, m, r); 
    } 
} 