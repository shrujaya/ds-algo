#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int compare(char* s1, char* s2) {
    char *a = s1;
    char *b = s2;
    while (*a && *b) {
        if (*a != *b) {
            return 1;
        }
        a++; b++;
    }
    return 0;
}

void main() {
    char s1[LEN], s2[LEN];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    int res = compare(s1, s2);
    if (res == 0) {
        printf("%s and %s match!\n", s1, s2);
    }
    else {
        printf("%s and %s don't match\n", s1, s2);
    }
}
