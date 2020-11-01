#include <stdio.h>
#define MAX 999999
#define SIZE 4

int dist[SIZE][SIZE];

int VISITEDALL;

int table[16][4];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int salesmandist(int mask, int pos) {
    if (mask == VISITEDALL) {
        return dist[pos][0];
    }
    if (table[mask][pos] != -1) {
        return table[mask][pos];
    }

    int ans = MAX;
    for (int city = 0; city < SIZE; city++) {
        if ((mask&(1<<city)) == 0) {
            int newans = dist[pos][city] + salesmandist(mask|(1<<city), city);
            ans = min(ans, newans);
        }
    }
    return table[mask][pos] = ans;
}

void main() {
    printf("Enter a 4x4 cost matrix:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &dist[i][j]);
        }
    } 

    VISITEDALL = (1<<SIZE) - 1;
    for (int i = 0; i < (1<<SIZE); i++) {
        for (int j = 0; j < SIZE; j++) {
            table[i][j] = -1;
        }
    }

    printf("Travelling salesman distance = %d\n", salesmandist(1, 0));
}
