#include <stdio.h>
#include <limits.h>

#define N 3

int cost[N][N] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int minCost = INT_MAX;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int perm[], int l, int r) {
    if (l == r) {
        int currentCost = 0;
        for (int i = 0; i < N; i++) {
            currentCost += cost[i][perm[i]];
        }
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        printf("Assignment: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", perm[i]);
        }
        printf("Cost: %d\n", currentCost);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        permute(perm, l + 1, r);
        swap(&perm[l], &perm[i]);
    }
}

int main() {
    int perm[N] = {0, 1, 2};
    permute(perm, 0, N - 1);
    printf("Minimum Cost: %d\n", minCost);
    return 0;
}
