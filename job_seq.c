#include <stdio.h>
#include <stdlib.h>

typedef struct job_sched{
	int start, end;
}job;

void merging(job arr[], int l, int m, int r) 
{ 
    int i, j, k, n1 = m - l + 1, n2 =  r - m; 
    job *Left, *Right; 
	Left=(job*)malloc(sizeof(job)*n1);
	Right=(job*)malloc(sizeof(job)*n2);
    for (i = 0; i < n1; i++) 
        Left[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        Right[j] = arr[m + 1+ j]; 
    i = 0; j = 0;k = l; 
    while (i < n1 && j < n2) 
    { 
        if (Left[i].end <= Right[j].end) 
            arr[k] = Left[i++]; 
        else
            arr[k] = Right[j++]; 
        k++; 
    } 
	while(i < n1) 
        arr[k++] = Left[i++]; 
    while(j < n2) 
        arr[k++] = Right[j++]; 
} 
  

void mergeSort(job arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merging(arr, l, m, r); 
    } 
} 

void job_scheduling(job arr[], int n)
{
	mergeSort(arr, 0, n-1);
	int k=1;
	printf("The sequence of mutually compatible jobs according to greedy method is \n");
	printf("\n%d. start time = %d, end time = %d",k,arr[0].start,arr[0].end);
    int f1=arr[0].end, i;
    k++;
    for(i=1;i<n;i++)
   {
	if(arr[i].start>=f1)
	{
       printf("\n%d. start time = %d, end time = %d",k,arr[i].start,arr[i].end);
       f1=arr[i].end;
       k++;
	}
   }
}


int main()
{
	int n,i;
	job *j;
	printf("Enter the no. of activities: \n");
	scanf("%d",&n);
	j= (job*)malloc(sizeof(job)*n);
	printf("Enter the start timings of all activities: \n");
	for(i=0;i<n;i++)
		scanf("%d",&j[i].start);
	printf("Enter the end timings of all activities: \n");
	for(i=0;i<n;i++)
		scanf("%d",&j[i].end);
	job_scheduling(j,n);
	
}