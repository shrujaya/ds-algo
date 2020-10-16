#include<stdio.h>
#include<stdlib.h>
#define INF 9999999
#define MAX 20

int graph[MAX][MAX], spanningtree[MAX][MAX], n;

int prims() {
	int cost[MAX][MAX];
	int u, v, mindist, dist[MAX], from[MAX];
	int visited[MAX], edges, mincost;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if(graph[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = graph[i][j];
				spanningtree[i][j] = 0;
		}

	dist[0] = 0;
	visited[0] = 1;

	for(int i = 1; i < n; i++) {
		dist[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
	}

	mincost = 0;
	edges = n-1;

	while(edges > 0) {
		mindist = INF;
		for(int i = 1; i < n; i++)
			if(visited[i] == 0 && dist[i] < mindist) {
				v = i;
				mindist = dist[i];
			}

		u = from[v];

		spanningtree[u][v] = dist[v];
		spanningtree[v][u] = dist[v];
		edges--;
		visited[v] = 1;

		for(int i = 1; i < n; i++)
			if(visited[i] == 0 && cost[i][v] < dist[i]) {
				dist[i] = cost[i][v];
				from[i] = v;
			}

		mincost = mincost + cost[u][v];
	}

	return(mincost);
}

void main() {
	int total_cost;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	total_cost = prims();
	printf("\n");
	printf("Spanning tree matrix:\n");

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", spanningtree[i][j]);
    	}
		printf("\n");
    }
	printf("Minimum Cost = %d\n", total_cost);
}
