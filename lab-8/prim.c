#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define VER 5

int smallestkey(int keys[], bool mstset[]) {
    int min = INT_MAX, mindex;

    for (int v = 0; v < VER; v++) {
        if ((mstset[v] == false) && (keys[v] < min)) {
            min = keys[v], mindex = v;
        }
    }
    return mindex;
}

void display(int parent[], int graph[VER][VER]) {
    printf("EDGE\tWEIGHT\n");
    for (int i = 1; i < VER; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void prim_mst(int graph[VER][VER]) {
    int parent[VER];
    int keys[VER];
    bool mstset[VER];

    for (int i = 0; i < VER; i++) {
        keys[i] = INT_MAX;
        mstset[i] = false;
    }

    keys[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < VER - 1; i++) {
        int u = smallestkey(keys, mstset);
        mstset[u] = true;
        for (int v = 0; v < VER; v++) {
            if ((graph[u][v]) && (mstset[v] == false) && (graph[u][v] < keys[v])) {
                parent[v] = u;
                keys[v] = graph[u][v];
            }
        }
    }
    display(parent, graph);
}

void main() {
    int graph[VER][VER] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim_mst(graph);
}

