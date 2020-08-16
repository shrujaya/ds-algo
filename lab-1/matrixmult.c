#include <stdio.h>
#include <stdlib.h>

void readmatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printmatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** makematrix(int rows, int cols) {
    int** mat = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        mat[i] = malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

int** mult(int** m1, int** m2, int** res, int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += (m1[i][k]*m2[k][j]);
            }
        }
    }
    return res;
}

void main() {
    int r1, c1, r2, c2 = 0;
    printf ("Enter number of rows in matrix1: ");
    scanf("%d", &r1);
    printf ("Enter number of columns in matrix1: ");
    scanf("%d", &c1);
    printf ("Enter number of rows in matrix2: ");
    scanf("%d", &r2);
    printf ("Enter number of columns in matrix2: ");
    scanf("%d", &c2);

    if (c1 == r2) {
        int** m1 = makematrix(r1, c1);
        int** m2 = makematrix(r2, c2);
        int** res = makematrix(r1, c2);
        printf("Enter elements of matrix1:\n");
        readmatrix(m1, r1, c1);
        printf("Enter elements of matrix2:\n");
        readmatrix(m2, r2, c2);
        res = mult(m1, m2, res, r1, c1, r2, c2);
        printf("The resulting matrix is:\n");
        printmatrix(res, r1, c2);
    }
    else {
        printf("These matrices cannot be multiplied!\n");
    }
}

