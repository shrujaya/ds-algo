#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int lenptr(char* s) {
    int count = 0;
    char *ch = s;
    while (*ch && *ch != '\n') {
        count++; ch++;
    }
    return count;
}

void main() {
    char* s = (char*)malloc(sizeof(char)*LEN);
    printf("Enter a string of your choice: ");
    fgets(s, LEN, stdin);
    printf("The length of your string is: %d\n", lenptr(s));
}
