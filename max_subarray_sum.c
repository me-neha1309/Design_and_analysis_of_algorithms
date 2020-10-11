#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int num1, int num2)
{
	if(num1>num2)
		return num1;
	else
		return num2;
}

int crossingsum(int a[], int l, int m, int h)
{
	int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN, i;
	for(i=m; i>=l; i--)
	{
		sum+=a[i];
		if(sum>left_sum)
			left_sum = sum;
	}
	
	sum = 0;
	for(i=m+1; i<=h; i++)
	{
		sum+=a[i];
		if(sum>right_sum)
			right_sum = sum;
	}
	return(max(max(left_sum, right_sum), left_sum+right_sum));
}

int maxsubarraysum(int a[], int l, int h)
{
	if(l==h)
		return a[l];
	
	int m = (l+h)/2;
	
	return (max(max(maxsubarraysum(a, l, m), maxsubarraysum(a, m+1, h)), crossingsum(a, l, m, h)));
}

int main()
{
	int *a, i, n;
	printf("Enter the number of elements in the array : \n");
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);
	printf("Enter the elemeents :\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	printf("The maximum sub array sum is %d \n", maxsubarraysum(a, 0, n-1));
}