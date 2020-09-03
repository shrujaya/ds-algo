#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 5

time_t t;

void generaterandarr(int* arr) {
    //seed created based on time of execution
    srand((unsigned)time(&t));
    for (int i = 0; i < LEN; i++) {
        arr[i] = (rand() % 20) + 1;
    }
}

void display(int* arr) {
    for (int i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum(int* arr) {
    int sum = 0;
    for (int i = 0; i < LEN; i++) {
        sum += arr[i];
    }
    return sum;
}

int lessthan10(int* arr) {
    int count = 0;
    for (int i = 0; i < LEN; i++) {
        if (arr[i] <= 10) {
            count += 1;
        }
    }
    return count;
}

void accumulate(int *arr1, int* arr2) {
    int accum = 0;
    for (int i = 0; i < LEN; i++) {
        accum += arr2[i];
        arr1[i] = accum;
    }
}

void main() {
    int* A = (int*)malloc(sizeof(int) * LEN);
    generaterandarr(A);
    printf("A: "); display(A);
    printf("The sum of the elements is %d\n", sum(A));
    printf("The number of  elements less than 10 is %d\n", lessthan10(A));
    int* B = (int*)malloc(sizeof(int) * LEN);
    accumulate(B, A);
    printf("B: "); display(B);
    free(A);
    free(B);
}
