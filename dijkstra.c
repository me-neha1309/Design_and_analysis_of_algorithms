#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define inf INT_MAX

void dijkstra(int v, int edge[][v], int start)
{
	int *distance = (int*)malloc(sizeof(int)*v), i, j, nextmin;
	int *visited = (int*)malloc(sizeof(int)*v);
	
	//assigning each vertex and non visited and distance as infinity
	for(i=0; i<v; i++)
	{
		distance[i] = inf;
		visited[i] = 0;
	}
	
	distance[start] = start;
	visited[i] = 1;
	
	//first loop to take count of edges one by one
	for(i=0; i<v-1; i++)
	{
		nextmin = -1;
		//find the vertex whose cost of visit from the previous vertex is minimum
		for(j=0; j<v; j++)
		{
			if(!visited[j] && (nextmin==-1 || distance[j]<distance[nextmin]))
				nextmin = j;
		}
		
		//from that minimum vertex visit all it's adjacent vertex and update their edge costs.
		visited[nextmin] = 1;
		for(j=0; j<v; j++)
		{
			if(edge[nextmin][j]!=0 && visited[j]==0)
			{
				if(distance[nextmin]+edge[nextmin][j]<distance[j])
					distance[j] = distance[nextmin]+edge[nextmin][j];
			}
		}
	}
	
	//printing the cost of vertices after applying dijkstra's algorith
	printf("The minimum cost of visiting all the vertices from source vertex %d :\n",start);
	printf("Vertex       Distance from source\n");
	for(i=0; i<v; i++)
		printf("%d                  %d\n",i, distance[i]);
	
}

int main()
{
	int v,e,i,j,x,y,w, st;
	printf("Enter the number of vertices and edges :\n");
	scanf("%d%d", &v,&e);
	int edge[v][v];
	for(i=0; i<v; i++)
	{
			for(j=0; j<v; j++)
				edge[i][j] = 0;
	}
	printf("Enter the edges and their weights : \n");
	for(i=0; i<e; i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		edge[x][y] = w;
		edge[y][x] = w;
	}
	printf("Enter the starting vertex : \n");
	scanf("%d",&st);
	dijkstra(v, edge, st);
}
