#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf INT_MAX
#define maxx 50

//adjacency list and it's operations
typedef struct node{
	int vertex;
	struct node*next;
}node;

typedef struct graph{
	int vertices;
	int *visited;
	struct node** adjlist;
}graph;

typedef struct queue{
	int items[maxx];
	int front;
	int rear;
}queue;

node* createnode(int v)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->vertex = v;
	newnode->next = NULL;
	return newnode;
}

graph* creategraph(int v)
{
	graph *g = (graph *)malloc(sizeof(graph));
	g->visited = (int*)malloc(sizeof(int)*v);
	g->vertices = v;
	g->adjlist = (node**)malloc(sizeof(node*)*v);
	
	for(int i=0; i<v; i++){
		g->adjlist[i] = NULL;
		g->visited[i] = 0;
	}
		
	return g;
}

queue* createqueue()
{
	queue *q = (queue*)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

void addEdge(graph*g, int s, int d)
{
	//adding edge from source to destination
	node *newnode = createnode(d);
	newnode->next = g->adjlist[s];
	g->adjlist[s] = newnode;
	
	//adding edge from destination to source
	newnode = createnode(s);
	newnode->next = g->adjlist[d];
	g->adjlist[d] = newnode;
}

//queue and it's operations


void enqueue(queue *q, int item)
{
	if(q->front==-1)
		q->front++;
	q->rear++;
	q->items[q->rear] = item;
}

int isEmpty(queue *q)
{
	if(q->rear==-1)
		return 1;
	return 0;
}

int dequeue(queue *q)
{
	int item = q->items[q->front];
	q->front++;
	
	if(q->front>q->rear)
		q->front = q->rear = -1;
	
	return item;
}

void printqueue(queue *q)
{
	int i;
	for(i=q->front; i<=q->rear; i++)
		printf("%d  ", q->items[i]);
	printf("\n");
}
//bbfs traversal of the graph
void bfs(graph *g, int start)
{
	queue *q = createqueue();
	int *ans = (int *)malloc(sizeof(int)*g->vertices), top = 0, i;
	enqueue(q, start);
	g->visited[start] = 1;
	while(!isEmpty(q))
	{
		printqueue(q);
		ans[top] = dequeue(q);
		node*temp = g->adjlist[ans[top]];
		while(temp){
			if(g->visited[temp->vertex]==0)
			{
				g->visited[temp->vertex] = 1;
				enqueue(q, temp->vertex);
			}
			temp = temp->next;
		}
		top++;
	}
	
	//printing the ans array to show the traversal
	for(i=0; i<top; i++)
		printf("%d  ", ans[i]);
	
}
//main function
int main()
{
	int i, v, e, x, y;
	graph *g;
	printf("Enter the number of vertices and edges : \n");
	scanf("%d%d",&v,&e);
	g = creategraph(v);
	printf("Enter the edges : \n");
	for(i=0; i<e; i++)
	{
		scanf("%d%d",&x,&y);
		addEdge(g, x, y);
	}
	printf("Enter the start vertex :\n");
	scanf("%d",&x);
	
	/*node *temp;
	for(i=0; i<g->vertices; i++)
	{
		temp = g->adjlist[i];
		while(temp)
		{
			printf("%d->",temp->vertex);
			temp = temp->next;
			
		}
		printf("\n");
	}*/
	bfs(g,x);
}

