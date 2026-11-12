#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node *adjacencyList[MAX_VERTICES];
};

struct Node *createNode(int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void BFS(struct Graph *graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Nodes reachable from node %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjacencyList[currentVertex];

        while (temp) {
            int adjacentVertex = temp->data;

            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                queue[rear++] = adjacentVertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
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

    int startVertex;

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}