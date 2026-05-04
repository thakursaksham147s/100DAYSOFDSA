/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void dfs(struct Node* adj[], int vis[], int s) {
    printf("%d ", s);
    vis[s] = 1;

    for (struct Node* t = adj[s]; t; t = t->next) 
    {
        if (!vis[t->data])
            dfs(adj, vis, t->data);
    }
}
int main() {
    int n, m, u, v, s;

    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d", &u, &v);

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = v;
        temp->next = adj[u];
        adj[u] = temp;
    }
    scanf("%d", &s);

    int vis[n];
    for (int i = 0; i < n; i++)
        vis[i] = 0;

    dfs(adj, vis, s);

    return 0;
}