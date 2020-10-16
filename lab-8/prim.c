#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define SIZE 30

int min(int adjlist[], bool visited[], int n) {
    int temp = INT_MAX, pos = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (adjlist[i] < temp) {
                temp = adjlist[i];
                pos = i;
            }
        }
    }
    return pos;
}

int spanningtree(int graph[SIZE][SIZE], int n) {
    int parent[SIZE], key[SIZE];
    bool visited[SIZE];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = min(key, visited, n);
        visited[u] = true;
        for (int j = 0; j < n; j++) {
            if (graph[u][j] != 0 && !visited[j] && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    int retval = 0;
    for (int i = 1; i < n; i++) {
        printf("%d --> %d : %d\n", parent[i], i, graph[i][parent[i]]);
        retval += graph[i][parent[i]];
    }
    return retval;
}

void main() {
    int graph[SIZE][SIZE];
    int n;
    printf("Enter the dimensions of your adjacency list: ");
    scanf("%d", &n);

    printf("Enter your adjacency list:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");
    int mincost = spanningtree(graph, n);
    printf("Minimum Cost = %d\n", mincost);
}
