#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    struct Edge e[100], temp;
    int n, m, i, j, count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    printf("Edges in MST:\n");

    for (i = 0; i < m && count < n - 1; i++) {
        if (find(e[i].u - 1) != find(e[i].v - 1)) {
            unionSet(e[i].u - 1, e[i].v - 1);
            printf("%d - %d : %d\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            count++;
        }
    }

    printf("Minimum cost = %d", cost);

    return 0;
}