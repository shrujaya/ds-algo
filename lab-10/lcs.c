#include <stdio.h>
#include <string.h>
#define LEN 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char* s1, char* s2, int l1, int l2) {
    int LCS[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            //initialize first row/column to 0
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    int len = LCS[l1][l2];
    printf("The length of the lcs is %d\n", len);

    char lcsstr[len + 1];
    lcsstr[len] = '\0';

    int i = l1, j = l2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsstr[len - 1] = s1[i - 1];
            i--; j--; len--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1]) { i--; }
        else { j--; }
    }
    printf("The lcs is %s\n", lcsstr);
}

int main() {
    char s1[LEN];
    char s2[LEN];
    printf("Enter 2 strings of your choice:\n");
    scanf("%s", s1);
    scanf("%s", s2);

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    lcs(s1, s2, l1, l2);
}
