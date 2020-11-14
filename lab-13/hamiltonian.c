#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define V 5

void display(int path[]) {
    printf("Solution exists!\n");
    printf("One Hamiltonian Cycle is: ");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d ", path[0]);
    printf("\n");
}

bool issafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph [path[pos-1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonianexists(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos-1]][path[0]] == 1)
           return true;
        else
          return false;
    }

    for (int v = 1; v < V; v++) {
        if (issafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianexists(graph, path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltoniancycle(bool graph[V][V]) {
    int *path = (int*)malloc(sizeof(int) * V);
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamiltonianexists(graph, path, 1) == false) {
        printf("Solution does not exist!\n");
        return false;
    }

    display(path);
    return true;
}

void main() {
    bool graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };
    printf("GRAPH 1:\n");
    hamiltoniancycle(graph1);

    bool graph2[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
    };
    printf("\nGRAPH 2:\n");
    hamiltoniancycle(graph2);
}
