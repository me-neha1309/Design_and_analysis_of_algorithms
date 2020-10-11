#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int n1, int n2)
{
	if(n1>n2)
		return n1;
	else
		return n2;
}

int chromatic_number(int v, int **adj)
{
	int i, j, chrom=0, *col, *available;
	col = (int*)malloc(sizeof(int)*v);
	available = (int *)malloc(sizeof(int)*v);
	col[0] = 0;
	
	for(i=1; i<v; i++)
		col[i] = -1;
	
	for(i=0; i<v; i++)
		available[i] = 0;
	
	for(i=1; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			if(adj[i][j]==1 && col[j]!=-1){
				available[col[j]] = 1;
			}
		}
		
		for(j=0; j<v; j++)
		{
			if(available[j]==0)
				break;
		}
		
		col[i] = j;
		
		for(j=0; j<v; j++)
		{
			if(col[j]!=-1)
				available[col[j]] = 0;
		}
	}
	
	for(i=0; i<v; i++)
	{
		chrom = max(chrom, col[i]);
	}
	return chrom+1;
}

int isSafe(int v, int **adj, int c, int k, int x[])
{
	int i;
	for(i=0; i<v; i++)
	{
		if(adj[k][i]==1 && c==x[i])
			return 0;
	}
	return 1;
}

void print(int x[], int v)
{
	int i;
	for(i=0; i<v; i++)
		printf("%d  ", x[i]);
	
	printf("\n");
}

void color(int v, int **adj, int m, int l, int x[])
{
	int c;
	if(l+1>v)
	{
		print(x, v);
		return;
	}
		
	for(c=1; c<=m; c++){
		if(isSafe(v, adj, c, l, x)){
			x[l] = c;
			color(v, adj, m, l+1, x);
			x[l] = 0;
		}
	}
}

int main()
{
	int **adj, i, j, x1,*x, y, n, m, e;
	printf("Enter the number of vertices and edges : \n");
	scanf("%d%d", &n, &e);
	
	adj = (int**)malloc(sizeof(int*)*n);
	x = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
	{
		adj[i] = (int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
			adj[i][j] = 0;
	}
	printf("Enter the edges :\n");
	for(i=0; i<e; i++)
	{
		scanf("%d%d",&x1, &y);
		adj[x1][y] = 1;
		adj[y][x1] = 1;
	}
	
	for(i=0; i<n; i++)
		x[i] = 0;
	m = chromatic_number(n, adj);
	printf("Chromatic number for the given graph is %d\n", m);
	printf("All the possible ways in which graph can be colored :\n");
	color(n, adj, m, 0, x);
	
}