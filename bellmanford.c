#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf INT_MAX
#define _inf INT_MIN

typedef struct edges{
	int u, v, w;
}edges;

void bellman(edges e[], int vert, int edge, int st)
{
	int *d, *p,*cycle, cost = 0, i, j, x, t, k=0;
	edges *path = (edges*)malloc(sizeof(edges)*vert);
	d = (int *)malloc(sizeof(int)*vert);
	p = (int *)malloc(sizeof(int)*vert);
	
	for(i=0; i<vert; i++)
		d[i] = inf;
	d[st] = 0;
	p[st] = -1;
	for(i=0; i<vert; i++)
	{
		x = -1;
		for(j=0; j<edge; j++)
		{
			if(d[e[j].u] < inf)
			{
				if(d[e[j].u] + e[j].w < d[e[j].v])
				{
					d[e[j].v] = d[e[j].u] + e[j].w;
					p[e[j].v] = e[j].u;
					x = 1;
					t = e[j].v;
				}
			}
		}
	}
	
	if(x==-1)
	{
		/*for(i=t; i!=-1; i=p[i])
		{
			//for the final path storing the source, destination and it's cost
			path[k].u = p[i];
			path[k].v = i;
			path[k].w = d[i];
			k++;
		}*/
		printf("The minimum cost of travelling  to the vertices from the source vertex %d\n",st);
		for(j=0; j<vert; j++)
		{
			printf("vertex: %d              cost: %d\n",j, d[j]);
			cost = cost + path[j].w;
		}
		//printf("Total cost of traversal is %d\n", cost);
	}
	else
	{
		printf("There is negative cycle in the graph\n");
		//printing the cycle
		for(i=0; i<vert; i++)
			t = p[t];
		for(j=t; ; j=p[j])
	    {
			cycle[k++] = j;
			if(j==t && k>1)
			    break;
		}
		printf("Cycle : \n");
		for(i=k-1; i>0; i--)
			printf("%d  ", cycle[i]);
	}
}

int main()
{
	int i, vert, edge, st;
	edges *e;
	printf("Enter the number of vertices and edges : \n");
	scanf("%d%d",&vert,&edge);
	e = (edges *)malloc(sizeof(edges)*edge);
	
	printf("Enter the edges with their weights : \n");
	for(i=0; i<edge; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	printf("Enter the starting vertex : \n");
	scanf("%d",&st);
	bellman(e, vert, edge, st);
}