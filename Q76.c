/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3
Explanation
Components: {1,2,3}, {4}, {5,6}
*/
#include <stdio.h>

int adj[100][100], vis[100];
int n, m;

void dfs(int u) {
    vis[u] = 1;

    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !vis[v])
            dfs(v);
    }
}
int main() {
    scanf("%d %d", &n, &m);

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // undirected
    }
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}