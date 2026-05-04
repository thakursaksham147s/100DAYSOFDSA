/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);

    struct Edge e[MAX];

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    scanf("%d", &src);

    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < m; j++) {
            int u = e[j].u, v = e[j].v, w = e[j].w;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    for (int j = 0; j < m; j++) 
    {
        int u = e[j].u, v = e[j].v, w = e[j].w;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}