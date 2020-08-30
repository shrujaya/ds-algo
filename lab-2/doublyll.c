#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *right;
    struct _node *down;
} NODE;


int getarrayindex(int cols, int i, int j) {
     return i*cols + j;
}

NODE* construct(int *arr, int i, int j, int rows, int cols, void **ptrcache) {
    if (i > rows - 1 || j > cols - 1) return NULL;

    void *cachedptr = ptrcache[getarrayindex(cols, i, j)];
    if (cachedptr) return cachedptr;

    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    ptrcache[getarrayindex(cols, i, j)] = newnode;
    newnode->data = arr[getarrayindex(cols, i, j)];
    newnode->right = construct(arr, i, j + 1, rows, cols, ptrcache);
    newnode->down = construct(arr, i + 1, j, rows, cols, ptrcache);
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
    void* ptrcache[dim*dim];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &arr[getarrayindex(dim, i, j)]);
    	    ptrcache[getarrayindex(dim, i, j)] = NULL;
        }
    }

    int rows = dim, cols = dim;
    NODE* head = construct(arr, 0, 0, rows, cols, ptrcache);
    display(head, dim);
}
