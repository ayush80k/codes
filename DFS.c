#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph *createGraph(int V) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

void DFS(struct Graph *graph, int v, int visited[]) {
    visited[v] = 1;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjacencyMatrix[v][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int isConnected(struct Graph *graph) {
    int visited[MAX_VERTICES] = {0};

    DFS(graph, 0, visited);

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            return 0;
    }

    return 1;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph *graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int src, dest;

        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        addEdge(graph, src, dest);
    }

    if (isConnected(graph))
        printf("Graph is connected");
    else
        printf("Graph is not connected");

    return 0;
}