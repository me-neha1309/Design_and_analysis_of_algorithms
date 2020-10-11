#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isSafe(int n, int **mat, int row, int col)
{
	int i, j;
	//row on the left
	for(i=0; i<col; i++)
		if(mat[row][i]==1)
			return 0;
	
	//upper diagonal on left side
	for(i=0, j=0; i<=row && j<=col; i++, j++)
		if(mat[i][j]==1)
			return 0;
		
	//lower diagonal on left side
	for(i=row, j=col; j>=0 && i<n; j--, i++)
		if(mat[i][j]==1)
			return 0;
	
	return 1;
		
}

void print(int n, int**mat)
{
	printf("---------------Chess Board---------------\n");
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d  ", mat[i][j]);
		
		printf("\n");
	}
}

int n_queen(int n, int **mat, int col)
{
	if(col>=n)
	{
		print(n, mat);
		return 1;
	}
		
	int i, res = 0;
	for(i=0; i<n; i++)
	{
		if(isSafe(n, mat, i, col)){
			mat[i][col] = 1;
			res = n_queen(n, mat, col+1) || res;
			mat[i][col] = 0;
		}
	}
	return res;
}
int main()
{
	int n, i, j, **mat;
	printf("Enter the size of the chess board : \n");
	scanf("%d",&n);
	mat = (int**)malloc(sizeof(int*)*n);
	
	for(i=0; i<n; i++)
	{
		mat[i] = (int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
			mat[i][j] = 0;
	}
	
	j = n_queen(n, mat, 0);
	if(j==0)
		printf("Solution does not exist\n");
}