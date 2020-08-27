#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* right;
    struct _node* down;
} NODE;


int getarrayindex(int cols, int i, int j) {
     return i*cols + j;
}

NODE* construct(int *arr, int i, int j, int rows, int cols) {
    if (i > rows - 1 || j > cols - 1) return NULL;

    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = arr[getarrayindex(cols, i, j)];
    newnode->right = construct(arr, i, j + 1, rows, cols);
    newnode->down = construct(arr, i + 1, j, rows, cols);
    return newnode;
}

void display(NODE* head, int dim) {
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
        while(i < dim) {
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
    while (i < dim) {
        printf("NULL  ");
        i++;
    }
    printf("\n");
}

void main() {
    int dim;
    printf("Enter dimension of your matrix: ");
    scanf("%d", &dim);
    int arr[dim*dim];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &arr[getarrayindex(dim, i, j)]);
        }
    }

    int rows = dim, cols = dim;
    NODE* head = construct(arr, 0, 0, rows, cols);
    display(head, dim);
}
