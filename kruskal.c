#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edges{
	int u,v,w;
}edges;

void sorting(edges e[], int vert, int edge)
{
	edges temp;
	for(int i=0; i<edge-1; i++)
	{
		for(int j=0; j<edge-1-i; j++)
		{
			if(e[j].w>e[j+1].w){
				temp = e[j];
				e[j] = e[j+1];
				e[j+1] = temp;
			}
		}
	}
}

int parent(int belongs[],int c1)
{
	if(belongs[c1] == c1)
		return c1;
	
	return parent(belongs, belongs[c1]);
}

void kruskal(edges e[], int vert, int edge)
{
	int *belongs = (int*)malloc(sizeof(int)*vert), i, cost = 0, count = 0, cn1, cn2;
	edges *graph = (edges*)malloc(sizeof(edges)*(vert-1));
	for(i=0; i<vert; i++)
		belongs[i] = i;
	
	i=0;
	
	while(count<vert-1)
	{
		cn1 = parent(belongs, e[i].u);
		cn2 = parent(belongs, e[i].v);
		if(cn1!=cn2)
		{
			graph[count] = e[i];
			belongs[cn1] = cn2;
			count++;
		}
		i++;
	}
	printf("The minimum spanning tree according to kruskal's algorithm is : \n");
	for(i=0; i<vert-1; i++)
	{
		printf("%d  %d  %d\n", graph[i].u, graph[i].v, graph[i].w);
		cost = cost + graph[i].w;
	}
	printf("The total cost of the tree is %d\n", cost);
}

int main()
{
	int vert, edge, i;
	edges *e;
	printf("Enter the no. of vertices in the graph : \n");
	scanf("%d",&vert);
	printf("Enter the no. of edges in the graph : \n");
	scanf("%d",&edge);
	e = (edges*)malloc(sizeof(edges)*edge);
	printf("Enter the edges and their respective costs : \n");
	
	for(i=0; i<edge; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	
	sorting(e, vert, edge);
	kruskal(e, vert, edge);
}

	