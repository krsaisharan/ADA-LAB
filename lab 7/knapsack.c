#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w[], int p[], int c) {
    int v[n+1][c+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= c; j++) {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(w[i-1] > j)
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], p[i-1] + v[i-1][j - w[i-1]]);
        }
    }

    printf("\nMaximum Profit is: %d\n", v[n][c]);

    // Displaying the DP Table
    printf("\nTable:\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= c; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, c;

    printf("\nEnter the number of objects: ");
    scanf("%d", &n);

    int w[n], p[n];

    printf("\nEnter the weights: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("\nEnter the profits: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nEnter the capacity: ");
    scanf("%d", &c);

    knapsack(n, w, p, c);

    return 0;
}
