#include <stdio.h>
#define LEN 5

int a[LEN];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int l, int u) {
    //taking pivot as the last element
    int pivot = a[u];
    int i = l;
    for (int j = l; j <= u - 1; j++) {
        if (a[j] < pivot) {
            swap(&a[j], &a[i]);
            i++;
        }
    }
    swap(&a[i], &a[u]);
    return i;
}

void sort(int l, int u) {
    if (l < u) {
        int pindex = partition(l, u);
        sort(l, pindex - 1);
        sort(pindex + 1, u);
    }
}

void input() {
    printf("Enter 5 array elements: ");
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &a[i]);
    }
}


void display() {
    for (int i = 0; i < LEN; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void main() {
    input();
    sort(0, LEN - 1);
    printf("The sorted array is: "); display();
}
