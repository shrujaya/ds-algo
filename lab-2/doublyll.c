#include <stdio.h>
#include <stdlib.h>
#define LEN 3

typedef struct _node {
    int data;
    struct _node* right;
    struct _node* down;
} NODE;

NODE* construct(int arr[LEN][LEN], int i, int j, int rows, int cols) {
    if (i > cols - 1 || j > rows - 1) return NULL;

    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = arr[i][j];
    newnode->right = construct(arr, i, j + 1, rows, cols);
    newnode->down = construct(arr, i + 1, j, rows, cols);
    return newnode;
}

void display(NODE* head) {
    NODE* rightptr;
    NODE* downptr = head;
    int i = 0;
    while (downptr) {
        rightptr = downptr;
        while(rightptr) {
            printf("%d --> ", rightptr->data);
            rightptr = rightptr->right;
        }
        printf("NULL\n");
        i = 0;
        while(i < LEN) {
            printf("|     ");
            i++;
        }
        downptr = downptr->down;
        if (downptr) {
            printf("\n");
        }
    }
    printf("\n");
    i = 0;
    while (i < LEN) {
        printf("NULL  ");
        i++;
    }
    printf("\n");
}

void main() {
    int arr[LEN][LEN] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int rows = LEN, cols = LEN;
    NODE* head = construct(arr, 0, 0, rows, cols);
    display(head);
}
