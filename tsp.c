#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int t[1001][1001] ;
void init(int v)
{
	int i, j;
	for(i=0; i<(1<<v); i++)
	{
		for(j=0; j<v; j++)
			t[i][j] = -1;
	}
}
int visited(int n)
{
	return (1<<n)-1;
}
//mask denotes the set of cities visited so far
int tsp(int v, int **mat, int mask, int pos)
{
	//if city has already been visited
	if(mask==visited(v))
		return mat[pos][0]; //if all the cities are visited then return the distance of going back to starting city from the current city
	
	if(t[mask][pos]!=-1)
		return t[mask][pos];
	
	int i, ans = INT_MAX, temp;
	for(i=0; i<v; i++)
	{
		if((mask&(1<<i))==0){
			temp = mat[pos][i] +  tsp(v, mat, (mask|(1<<i)), i);
			if(temp<ans)
				ans = temp;
		}
	}
	t[mask][pos] = ans;
	return t[mask][pos];
}
int main()
{
	int v, e, i, **mat, x, y, w, j, start;
	printf("Enter the number of vertices and edges : \n");
	scanf("%d%d", &v, &e);
	printf("Enter the edges and their weights : \n");
	mat = (int**)malloc(sizeof(int*)*v);
	init(v);
	for(i=0; i<v; i++)
	{
		mat[i] = (int*)malloc(sizeof(int)*v);
		for(j=0; j<v; j++)
			mat[i][j] = 0;
	}
	for(i=0; i<e; i++)
	{
		scanf("%d%d%d",&x, &y, &w);
		mat[x][y] = w;
		mat[y][x] = w;
	}
	printf("Enter the start city\n");
	scanf("%d", &start);
	printf("Minimum cost is %d", tsp(v, mat, 1, start));
}