#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int chromatic_number(int v, int adj[][v])
{
	int i, j, chrom = 1, *col;
	col = (int*)malloc(sizeof(int)*v);
	for(i=0; i<v; i++)
		col[i] = -1;
	
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			if(adj[i][j]==1 && col[j]==chrom)
				break;
		}
		if(j<v)
			chrom++;
		col[i] = chrom;
	}
	return chrom;
}

int main()
{
	int **adj, int i, j, x, y, *color, n, m, e;
	printf("Enter the number of vertices and edges : \n");
	scanf("%d%d", &v, &e);
	
	adj = (int**)malloc(sizeof(int*)*v);
	for(i=0; i<n; i++)
	{
		adj[i] = (int*)malloc(sizeof(int)*v);
		for(j=0; j<n; j++)
			adj[i][j] = 0;
	}
	printf("Enter the edges :\n");
	for(i=0; i<e; i++)
	{
		scanf("%d%d",&x, &y);
		adj[x][y] = 1:
		adj[y][x] = 1;
	}
	m = chromatic_number(v, adj);
	printf("Chromatic number for the given graph is %d", m);
	
}