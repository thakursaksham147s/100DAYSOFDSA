/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...
Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6
Explanation
One possible MST edges: (2-3), (3-4), (1-2)
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
        g[u][v] = g[v][u] = w;
    }
    int key[100], vis[100] = {0};

    for (int i = 1; i <= n; i++)
        key[i] = INF;

    key[1] = 0;  // start from node 1

    int total = 0;

    for (int i = 1; i <= n; i++) 
    {
        int u = -1;

        for (int j = 1; j <= n; j++)
            if (!vis[j] && (u == -1 || key[j] < key[u]))
                u = j;

        vis[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++)
            if (g[u][v] < key[v] && !vis[v])
                key[v] = g[u][v];
    }
    printf("%d", total);
    return 0;
}