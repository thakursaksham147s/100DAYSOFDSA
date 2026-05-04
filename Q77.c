/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
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

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // undirected
    }
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }
    printf("CONNECTED");
    return 0;
}