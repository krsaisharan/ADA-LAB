#include <stdio.h>

int match(char text[], char pattern[], int m, int n) {
    for (int i = 0; i <= m - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}

int main() {
    int m, n;
    printf("Enter the length of the main text: ");
    scanf("%d", &m);
    printf("Enter the length of the pattern: ");
    scanf("%d", &n);

    char text[m + 1], pattern[n + 1];

    printf("Enter the main text: ");
    scanf("%s", text);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    int position = match(text, pattern, m, n);
    if (position != -1) {
        printf("Pattern found at position %d\n", position + 1);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}
