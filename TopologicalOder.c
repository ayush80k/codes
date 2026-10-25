#include <stdio.h>

int main() {
    int graph[20][20], indegree[20] = {0};
    int queue[20], result[20];
    int n, i, j, front = 0, rear = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j])
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int v = queue[front++];
        result[count++] = v;

        for (j = 0; j < n; j++) {
            if (graph[v][j]) {
                indegree[j]--;
                if (indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    if (count != n) {
        printf("Topological ordering not possible");
    } else {
        printf("Topological ordering: ");
        for (i = 0; i < n; i++)
            printf("%d ", result[i] + 1);
    }

    return 0;
}