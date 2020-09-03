#include <stdio.h>
#define LEN 10

int arr[LEN];

void input() {
    printf("Enter elements: array size is 10\n");
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &arr[i]);
    }
}

void display() {
    for (int i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotate(int n) {
    for (int i = 0; i < n; i++) {
        int last = arr[LEN - 1];
        for (int j = LEN - 1; j >= 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}

void main() {
    input();
    int n = 0;
    printf("How much do you want to right-rotate the array by?\n");
    scanf("%d", &n);
    rotate(n);
    display();
}
