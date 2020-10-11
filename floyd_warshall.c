#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf 999

void floyd(int v, int **mat)
{
	int i, j, k;
	int dist[v][v];
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
			dist[i][j] = mat[i][j];
	}
	
	for(k=0; k<v; k++)
	{
		for(j=0; j<v; j++)
		{
			for(i=0; i<v; i++)
			{
				if(dist[i][j]>dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			if(dist[i][j]!=999)
			printf("%d    ", dist[i][j]);
			else
				printf("inf  ");
		}
			
		printf("\n");
	}
	
}

int main()
{
	int v, e, w, **mat, i, j, x, y;
	printf("Enter the number of vertices and the edges: \n");
	scanf("%d%d", &v, &e);
	mat = (int **)malloc(sizeof(int*)*v);
	for(i=0; i<v; i++)
	{
		mat[i] = (int *)malloc(sizeof(int)*v);
		for(j=0; j<v; j++)
		{
			mat[i][j] = inf;
			if(i==j)
				mat[i][j] = 0;
		}	
	}
	printf("Enter the edges with weights:\n");
	for(i=0; i<e; i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		mat[x][y] = w;
	}
	floyd(v , mat);
}