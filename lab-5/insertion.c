#include <stdio.h>
#define LEN 5

int a[LEN];

void sort() {
    int key = 0, j = 0;
    for (int i = 1; i < LEN; i++) {
        key = a[i];
        j = i - 1;
        while (key < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
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
    sort();
    printf("The sorted array is: "); display();
}
