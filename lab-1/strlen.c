#include <stdio.h>
#define LEN 100

int len(char s[]) {
    int count = 0;
    for (int i = 0; s[i] && s[i] != '\n'; i++) {
        count++;
    }
    return count;
}

void main() {
    char s[LEN];
    printf("Enter a string of your choice: ");
    fgets(s, LEN, stdin);
    printf("The length of your string is: %d\n", len(s));
}
