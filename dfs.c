#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define maxx 50

typedef struct node{
	int vertex;
	struct node*next;
}node;

typedef struct graph{
	int vertices;
	int *visited;
	struct node** adjlist;
}graph;

typedef struct stack{
	int items[maxx];
	int top;
}stack;

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

stack* createstack()
{
	stack *s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	return s;
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


void push(stack *s, int item)
{
	s->top++;
	s->items[s->top]=item;
}

int isEmpty(stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}

int pop(stack *s)
{
	int item = s->items[s->top];
	s->top--;
	return item;
}

void printstack(stack *s)
{
	int i;
	for(i=0; i<=s->top; i++)
		printf("%d  ", s->items[i]);
	printf("\n");
}
//bbfs traversal of the graph
void dfs(graph *g, int start)
{
	stack *s = createstack();
	int *ans = (int *)malloc(sizeof(int)*g->vertices), top1 = 0, i;
	push(s, start);
	g->visited[start] = 1;
	while(!isEmpty(s))
	{
		printstack(s);
		ans[top1] = pop(s);
		node*temp = g->adjlist[ans[top1]];
		while(temp){
			if(g->visited[temp->vertex]==0)
			{
				g->visited[temp->vertex] = 1;
				push(s, temp->vertex);
			}
			temp = temp->next;
		}
		top1++;
	}
	
	//printing the ans array to show the traversal
	for(i=0; i<top1; i++)
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
	dfs(g,x);
}

