#include<stdio.h>
#include<stdlib.h>
void heapify(int arr[], int, int);
void heapSort(int arr[], int);
void main() 
{
	int arr[10],i;
	printf("\nEnter the 10 elements:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapSort(arr,10);
	printf("\nElements in the sorted order:");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
}
void heapify(int arr[], int n, int i) 
{ 
    int largest = i,temp; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;		
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{  
    int i,temp;
	for ( i = (n/2-1); i >= 0; i--) 
        heapify(arr, n, i);  
    for ( i=n-1; i>0; i--) 
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;		
        heapify(arr, i, 0); 
    } 
} 
