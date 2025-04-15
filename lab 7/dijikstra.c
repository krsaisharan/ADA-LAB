#include <stdio.h>
#include <limits.h>

#define MAX 20

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int distance[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        distance[i] = graph[src][i];
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[u][i] != INT_MAX && distance[u] + graph[u][i] < distance[i]) {
                distance[i] = distance[u] + graph[u][i];
            }
        }
    }

    printf("The shortest distance from %d is:\n", src + 1);
    for (int i = 0; i < n; i++) {
        printf("%d --> %d = %d\n", src + 1, i + 1, distance[i]);
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use %d for no edge):\n", 999);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src - 1);

    return 0;
}
