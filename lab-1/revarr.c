#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int* a, int len) {
    int* start = a;
    int* end = a + (len - 1);
    //swapping contents of end and start ptrs
    while (end > start) {
        swap(start, end);
        end--; start++;
    }
}

void printarray(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *a);
        a++;
    }
    printf("\n");
}

void main() {
    int len = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &len);

    //terminating program if len = 0
    if (len == 0) {
        printf("Nothing to reverse!\n");
        return;
    }

    int* a = (int*)malloc(sizeof(int)*len);
    printf("Enter an integer array of your choice: ");
    int* p = a;
    for (int i = 0; i < len; i++) {
        scanf("%d", p);
        p++;
    }
    reverse(a, len);
    printf("The reversed array is: ");
    printarray(a, len);
    free(a);
}
