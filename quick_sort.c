#include<stdio.h>
#include<stdlib.h>
void quickSort(int arr[],int bottom,int top);
int partition (int arr[],int bottom,int top);
void main() 
{
	int arr[10],i;
	printf("\nEnter the 10 elements:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,9);
	printf("\nElements in the sorted order:");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
}
void quickSort(int arr[],int bottom,int top)
{
	int index;
    if (bottom < top)
    {
        index = partition(arr, bottom, top);
        quickSort(arr, bottom, index - 1);  
        quickSort(arr, index + 1, top); 
    }
}
int partition (int arr[],int bottom,int top)
{
    int pivot = arr[top]; 
    int i = bottom-1,j,temp;

    for (j = bottom; j <= top; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp= arr[i]; 
			arr[i]=arr[j];
			arr[j]=temp;
        }
    }
    temp=arr[i+1];
	arr[i+1]=arr[top];
	arr[top]=temp;
    return (i + 1);
}