/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.
Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6
Explanation
Shortest distances computed via priority queue.
*/
#include <stdio.h>

#define INF 999999

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int g[100][100];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = w;  
    }
    int src;
    scanf("%d", &src);

    int dist[100], vis[100] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++)
            if (!vis[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        vis[u] = 1;

        for (int v = 1; v <= n; v++)
            if (!vis[v] && g[u][v] != INF &&
                dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}