/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m, u, v, w, src;
    int adj[MAX][MAX], dist[MAX], vis[MAX] = {0};

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if directed
    }

    scanf("%d", &src);

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int min = INT_MAX, u = -1;

        for (int j = 0; j < n; j++)
            if (!vis[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }

        if (u == -1) break;
        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !vis[v] && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}