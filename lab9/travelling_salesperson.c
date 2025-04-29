#include <stdio.h>
#include <limits.h>

#define N 4

int minCost = INT_MAX;
int path[N];
int visited[N] = {0};
int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

void tsp(int pos, int cost, int count) {
    if (count == N && graph[pos][0]) {
        if (cost + graph[pos][0] < minCost) {
            minCost = cost + graph[pos][0];
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            tsp(i, cost + graph[pos][i], count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    visited[0] = 1;
    tsp(0, 0, 1);
    printf("Travelling Sales Person : \n");
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
