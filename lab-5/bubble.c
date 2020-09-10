#include <stdio.h>
#define LEN 5

int a[LEN];

void sort() {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN - 1; j++) {
            if (a[j] > a[j + 1]) {
                 int temp = a[j];
                 a[j] = a[j + 1];
                 a[j + 1] = temp;
            }
        }
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
