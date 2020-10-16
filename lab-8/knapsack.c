#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int knap[n+1][W+1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (wt[i-1] <= w)
                knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
            else
                knap[i][w] = knap[i-1][w];
        }
    }
    return knap[n][W];
}

void main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack's capacity: ");
    scanf("%d", &W);

    int* val = (int*)malloc(sizeof(int) * n);
    int* wt = (int*)malloc(sizeof(int) * n);

    printf("Enter the value of each item: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Enter the weight of each item: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Optimal weight of the knapsack is: %d\n", knapsack(W, wt, val, n));
}
