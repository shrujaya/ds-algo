#include <stdio.h>

int nthfib(int n) {
    if (n <= 1) {
        return n;
    }
    return nthfib(n - 1) + nthfib(n - 2);
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The fibonacci number at position %d is %d\n", n, nthfib(n));
}
