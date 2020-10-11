#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int solve(int arr[], int n)
{
	int m[n][n],d, i,j, minm, q, k;
	for(i=1; i<n; i++)
		m[i][i] = 0;
	for(d=1; d<n-1; d++)
	{
		for(i=1; i<n-d; i++)
		{
			j = i+d;
			minm = INT_MAX;
			for(k=i; k<=j-1; k++)
			{
				q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
				if(q<minm)
					minm = q;
			}
			m[i][j] = minm;
		}
	}
	return m[1][n-1];
}

int main()
{
	int n,i, res,*arr, j;
    printf("size of the array:\n");
    scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
    printf("Enter the elements:\n");
    for ( i = 0; i < n; i++)
        scanf("%d",&arr[i]);
	res = solve(arr, n);
    printf("The minimum number of scalar multiplication needed:\n");
    printf("%d",res);
	return 0;
}
