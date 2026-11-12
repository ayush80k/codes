#include <stdio.h>

#define MAX_VERTICES 100
#define INF_MAX 9999

int minDistance(int dist[], int visited[], int V) {
    int min = INF_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(int dist[], int V, int src) {
    printf("Shortest distances from source %d:\n", src);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF_MAX)
            printf("To vertex %d: INF\n", i);
        else
            printf("To vertex %d: %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF_MAX;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INF_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V, src);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter weighted adjacency matrix (0 for no edge):\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}