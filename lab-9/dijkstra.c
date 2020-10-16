#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindist, next, i, j;

	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(graph[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = graph[i][j];

	//initialize pred[], distance[] and visited[]
	for (i = 0; i < n; i++) {
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1) {
		mindist = INF;
		//nextnode gives the node at minimum distance
        	for (i = 0; i < n; i++)
			if (distance[i] < mindist && !visited[i]) {
				mindist = distance[i];
				next = i;
			}

			//check if a better path exists through nextnode
			visited[next] = 1;
			for (i = 0; i < n; i++)
				if (!visited[i])
					if (mindist + cost[next][i] < distance[i]) {
						distance[i] = mindist + cost[next][i];
						pred[i] = next;
					}
    		count++;
	}

	//print the path and distance of each node
	for (i = 0; i < n; i++)
		if (i != start) {
			printf("\nDistance of node %d = %d", i, distance[i]);
			printf("\nPath = %d ", i);

			j = i;
			do {
				j = pred[j];
				printf("<-- %d ", j);
			} while (j != start);
	}
}

void main() {
	int graph[MAX][MAX], i, j, n, start;
	printf("Enter the number of vertices in your graph: ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of your graph:\n");

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter the starting node: ");
	scanf("%d", &start);
	dijkstra(graph, n, start);
	printf("\n");
}
