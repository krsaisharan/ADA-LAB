#include <stdio.h>

#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (weights[n - 1] > W)
        return knapsack(W, weights, values, n - 1);

    return max(values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
               knapsack(W, weights, values, n - 1));
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);

    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
