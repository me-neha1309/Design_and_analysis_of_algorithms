#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define m 10

void prims(int v, int t[][v], int e)
{
	int i = 0, top = 0, v1,j, vert1[10], vert2[10], weight[10], edges = v-1, visited[10] = {0};
	visited[0] = 1;
	while(edges>0)
	{   
		int k =0, k1 = 0;
		int temp, mincost = INT_MAX;
		
		while(k1<v)
		{ 
			
			if(visited[k1]){
				for(j=0; j<v; j++)
				{
					if(t[k1][j]<mincost && visited[j]==0){
						mincost = t[k1][j];
						k = k1;
						v1 = j;
					}
				}
				
			}
			k1++;
		}
			visited[v1] = 1;
			visited[k] = 1;
			vert2[top] = v1;
			vert1[top] = k;
			weight[top] = t[v1][k];
			edges--;
			top++;
	}
	
	printf("\nMinimum spanning tree according to Prim's :");
	int cost = 0;
	for(i=0; i<top; i++)
	{
		printf("\n%d  %d  %d", vert1[i]+1,vert2[i]+1,weight[i]);
		cost= cost + weight[i];
	}
	printf("\nThe total cost of MST is %d", cost);
}
int main()
{
	int v, i, j;
	printf("\nEnter the number of vertices : ");
	scanf("%d",&v);
	int t[v][v];
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			t[i][j] = INT_MAX;
		}
	}
	int x, y, w, e;
	printf("\nEnter the no. of edges : ");
	scanf("%d",&e);
	printf("\nEnter the vertices and cost between them:");
	for(i = 0; i<e; i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		t[x-1][y-1] = w;
		t[y-1][x-1] = w;
	}
	prims(v,t,e);
	
}